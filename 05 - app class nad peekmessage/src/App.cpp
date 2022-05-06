#include "App.hpp"

App::App() : window(800, 600, "ja nie komar") {}

int App::go() {
    while(true) {
        if(const auto ecode = Window::processMessages()) {
            return *ecode;
        }

        doFrame();
    }

}

void App::doFrame() {
    
}