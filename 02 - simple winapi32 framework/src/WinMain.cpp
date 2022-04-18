#include "Window.hpp

int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int cmdShow
) {
    Window window(800, 600, "only window");

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