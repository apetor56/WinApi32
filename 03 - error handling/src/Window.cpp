#include "Window.hpp"
#include <sstream>

Window::WindowClass Window::WindowClass::windowClass;

Window::WindowClass::WindowClass() noexcept : hInstance(GetModuleHandle(nullptr)) {
    WNDCLASSEX windowClass = {0};

    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = CS_OWNDC;
    windowClass.lpfnWndProc = HandleMsgSetup;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = hInstance;
    windowClass.hIcon = nullptr;
    windowClass.hCursor = nullptr;
    windowClass.hbrBackground = nullptr;
    windowClass.lpszMenuName = nullptr;
    windowClass.lpszClassName = getName();

    RegisterClassEx(&windowClass);
}

Window::WindowClass::~WindowClass() {
    UnregisterClass(wndClassName, getInstance());
}

const char* Window::WindowClass::getName() noexcept {
    return wndClassName;
}

HINSTANCE Window::WindowClass::getInstance() noexcept {
    return windowClass.hInstance;
}

Window::Window(long width, long height, const char *name) : width(width), height(height) {
    RECT wr;
    wr.left = 100;
    wr.right = width + wr.left;
    wr.top = 100;
    wr.bottom = height + wr.top;

    AdjustWindowRect(&wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);

    hWnd = CreateWindow(
        WindowClass::getName(), name,
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top,
        nullptr, nullptr, WindowClass::getInstance(), this
    );

    if(hWnd == nullptr) {
        throw DXWND_LAST_EXCEPT();
    }

    ShowWindow(hWnd, SW_SHOWDEFAULT);
}

Window::~Window() {
    DestroyWindow(hWnd);
}

/* this procedure is to get window instance pointer by CREATESRTUCT
   and link it with winapi32 side and then set new window procedure 'HandleMsgThunk */
LRESULT CALLBACK Window::HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept {
    /* we receive pointer to CREATESTRUCT by this message (in 'lParam') */
    if(msg == WM_NCCREATE) {
        const CREATESTRUCTW *const pCreate = reinterpret_cast<CREATESTRUCTW *>(lParam);
        Window *const pWnd = static_cast<Window *>(pCreate->lpCreateParams);

        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
        SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(Window::HandleMsgThunk));

        return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
    }
    
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

/* this procedure is to invoke 'HandleMsg' procedure,
   we cann't use directly 'HandleMsg' as window procedure */
LRESULT CALLBACK Window::HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept {
    Window *const pWnd = reinterpret_cast<Window *>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
    return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
}

LRESULT Window::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept {
    switch(msg) {
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

// Window exception

Window::Exception::Exception(int line, const char *file, HRESULT hr) noexcept
:   DXException(line, file),
    hr(hr) {}

const char *Window::Exception::what() const noexcept {
    std::ostringstream oss;

    oss << getType() << '\n'
    << "[Error code] " << getErrorCode() << '\n'
    << "[Description] " << getErrorString() << '\n'
    << getOriginString();

    /* we can't return oss.c_str() directly because
      it will not exist after what() function execution
      and we can't return pointer to nothing so the result
      of oss.str() will be stored in class memeber 'whatBuffer' */
    
    whatBuffer = oss.str();
    return whatBuffer.c_str();
}

const char *Window::Exception::getType() const noexcept {
    return "DX Exception";
}

std::string Window::Exception::translateErrorCode(HRESULT hr) noexcept {
    char *pMsgBuf = nullptr;

    DWORD nMsgLen = FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        nullptr, hr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        reinterpret_cast<LPSTR>(&pMsgBuf), 0, nullptr
    );

    if(nMsgLen == 0) {
        return "Unidentified error code";
    }

    std::string errorString = pMsgBuf;
    LocalFree(pMsgBuf);

    return errorString;
}

HRESULT Window::Exception::getErrorCode() const noexcept {
    return hr;
}

std::string Window::Exception::getErrorString() const noexcept {
    return translateErrorCode(hr);
}

