//
// Created by mu on 8/3/22.
//

#ifndef OPENGLLINUXTEST_WINDOW_H
#define OPENGLLINUXTEST_WINDOW_H

#include <iostream>
#include <string>

#include "../../imgui/imgui.h"
#include "../../imgui/imgui_impl_glfw.h"
#include "../../imgui/imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>
#include <GLES3/gl3.h>
#include "../renderer/Shader.h"

#include "Camera.h"
#include "../renderer/VertexBuffer.h"
#include "../renderer/IndexBuffer.h"

#include "../../include/stb/stb_image.h"




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
        float t = 0.0f;

        static Window *get();
        void run();
        void init();
        void loop();

        static int getWidth();
        static int getHeight();
        static GLFWwindow* getWindow();
        static renderer::Shader getShader();

        float getTime();
    };
}

#endif //OPENGLLINUXTEST_WINDOW_H
