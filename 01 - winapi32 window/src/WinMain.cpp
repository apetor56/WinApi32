#include <sstream>
#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        /* terminale the application */

        case WM_CLOSE:
            PostQuitMessage(10);
            break;

        /* WM_KEYDOWN / WM_KEYUP are used for checking key stroking
        - it doesn't distinguish letter type like 'a' or 'A'
        - recognized using keys like f1, f1, ctrl */

        case WM_KEYDOWN:
            if(wParam == 'F') {
                SetWindowText(hWnd, "something else");
            }
            if(wParam == VK_ESCAPE) {
                PostQuitMessage(VK_ESCAPE);
            }
            break;

        case WM_KEYUP:
            SetWindowText(hWnd, "key up");
            break;

        /* WM_CHAR recognized differences between 'a' and 'A'
        - it doenn't see f1, f2, enter ect.
        - mainly used in text typing */

        case WM_CHAR:
            static std::string title;
            title.push_back(wParam);
            SetWindowText(hWnd, title.c_str());
            break;

        /* some mouse button click event */
        
        case WM_LBUTTONDOWN:
            std::ostringstream oss;
            POINTS point = MAKEPOINTS(lParam);
            
            oss << '(' << point.x << ',' << point.y << ')';
            SetWindowText(hWnd, oss.str().c_str());
    }
    
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int cmdShow
) {
    // register window class

    const char *windowClassName = "hw3d";
    WNDCLASSEX windowClass = {0};

    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = CS_OWNDC;
    windowClass.lpfnWndProc = WndProc;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = hInstance;
    windowClass.hIcon = nullptr;
    windowClass.hCursor = nullptr;
    windowClass.hbrBackground = nullptr;
    windowClass.lpszMenuName = nullptr;
    windowClass.lpszClassName = windowClassName;

    RegisterClassEx(&windowClass);

    // create window instance

    HWND handleWnd = CreateWindowEx(
        0,
        windowClassName,
        "Just window",
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
        0, 0, 800, 600,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    ShowWindow(handleWnd, SW_SHOW);

    // message
    MSG msg;
    BOOL gResult;

    while( (gResult = GetMessage(&msg, nullptr, 0, 0)) > 0 ) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    if(gResult == -1) {
        return -1;
    }
    else {
        return msg.wParam;
    }    
}