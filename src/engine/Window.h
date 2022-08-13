//
// Created by mu on 8/3/22.
//

#ifndef OPENGLLINUXTEST_WINDOW_H
#define OPENGLLINUXTEST_WINDOW_H

#include <iostream>
#include <string>
#include <GLFW/glfw3.h>
#include <GLES3/gl3.h>
#include "../renderer/Shader.h"

#include "Camera.h"
#include "../renderer/VertexBuffer.h"
#include "../renderer/IndexBuffer.h"


namespace engine {
    class Window {
    private:
        GLFWwindow* window;
        renderer::Shader shader = renderer::Shader("defaultShader.glsl");
        int width, height;
        char* title;

    protected:
        Window();

    public:
        float r, g, b, a;

        static Window *get();
        void run();
        void init();
        void loop();

        static int getWidth();
        static int getHeight();
        static GLFWwindow* getWindow();
        static renderer::Shader getShader();
    };
}

#endif //OPENGLLINUXTEST_WINDOW_H
