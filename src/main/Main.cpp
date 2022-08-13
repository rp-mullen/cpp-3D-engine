#include <iostream>
#include <GLFW/glfw3.h>
#include "../engine/Window.h"

int main() {
    engine::Window::get()->run();
    return 0;
}
