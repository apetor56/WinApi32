#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "RWin.hpp

class Window {
public:
    Window(long width, long height, const char *name);

    ~Window();

    Window(const Window& other) = delete;

    Window& operator=(const Window& other) = delete;

private:
    long width;
    long height;
    HWND hWnd;

//////////////////////////////////////////////////////////////////////

    /* class for our window class to register */
    class WindowClass {
    public:
        static const char *getName() noexcept;
        static HINSTANCE getInstance() noexcept;

    private:
        static WindowClass windowClass;
        HINSTANCE hInstance;                // it will be handler to out aplication

        WindowClass() noexcept;

        ~WindowClass();

        WindowClass(const WindowClass& other) = delete;

        WindowClass& operator=(const WindowClass& other) = delete;

        static constexpr const char* wndClassName = "some name";
    };

//////////////////////////////////////////////////////////////////////

    static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

    static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

    LRESULT WINAPI HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
};

#endif // WINDOW_HPP