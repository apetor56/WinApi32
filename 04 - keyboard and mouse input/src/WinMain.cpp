#include "Window.hpp"
#include <iostream>
#include <bitset>

int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int cmdShow
) {
    try {
        Window window(800, 600, "only window");

        // message
        MSG msg;
        BOOL gResult;

        while( (gResult = GetMessage(&msg, nullptr, 0, 0)) > 0 ) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            while(!window.mouse.IsEmpty()) {
                const auto e = window.mouse.Read();
                if(e.value().GetType() == Mouse::Event::Type::Move) {
                    std::ostringstream oss;
                    oss << "Mouse Position: (" << e.value().GetPosX() << ',' << e.value().GetPosY() << ')';
                    window.setTitle(oss.str());
                }
            }

        }

        if(gResult == -1) {
            return -1;
        }
        else {
            return msg.wParam;
        }    
    }
    catch(const DXException& e) {
        MessageBox(nullptr, e.what(), e.getType(), MB_OK | MB_ICONEXCLAMATION);
    }
    catch(const std::exception& e) {
        MessageBox(nullptr, e.what(), "Standard exception", MB_OK | MB_ICONEXCLAMATION);
    }
    catch(...) {
        MessageBox(nullptr, "No details", "Unknown exception", MB_OK | MB_ICONEXCLAMATION);
    }
    return -1;
}