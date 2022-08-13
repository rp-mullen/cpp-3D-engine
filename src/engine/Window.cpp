//
// Created by mu on 8/3/22.
//

#include "Window.h"
#include "../renderer/VertexArray.h"

namespace engine {

    // Vertices coordinates
    GLfloat vertices[] =
            {
                    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
                    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
                    0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
                    -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
                    0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
                    0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
            };

    // Indices for vertices order
    GLuint indices[] =
            {
                    0, 3, 5, // Lower left triangle
                    3, 2, 4, // Lower right triangle
                    5, 4, 1 // Upper triangle
            };

    static Window* instance = nullptr;

    Window::Window() {
        width = 1920;
        height = 1080;
        title = (char*)"Window";
        r = 0.07f;
        g = 0.13f;
        b = 0.17f;
        a = 1.0f;
    }

    Window* Window::get() {
        if (instance == nullptr) {
            instance = new Window();
        }
        return instance;
    }

    void Window::run() {
        init();
        loop();

        // free memory
        glfwDestroyWindow(window);
    }

    void Window::init() {
        glfwInit();

        if (!glfwInit()) {
            std::cout << "Failed to initialize GLFW" << std::endl;
            return;
        }
        // v. 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        window = glfwCreateWindow(width,height,title,nullptr,nullptr);

        glfwMakeContextCurrent(window);

        //glfwSwapInterval(1);

        glfwShowWindow(window);

        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
    }

    void Window::loop() {

        shader.compile();
        shader.use();

        float t = 0.0f;
        float x = 0.0f;
        int location = glGetUniformLocation(shader.getID(),"u_Color");
        glUniform4f(location,x,g,b,a);


        renderer::VertexArray vao;
        vao.bind();

        renderer::VertexBuffer vb(vertices, 6*3*sizeof(float));
        renderer::IndexBuffer ib(indices, 9);

        vao.LinkVBO(vb,0);

        vao.unbind();
        vb.unbind();
        ib.unbind();

        auto beginTime = (float)glfwGetTime();
        float endTime;
        float dt = -1.0f;

        while (!glfwWindowShouldClose(window)) {

            t += dt;

            glClearColor(r,g,b,a);
            glClear(GL_COLOR_BUFFER_BIT);

            shader.use();

            vao.bind();

            x = sin(t*10);


            glUniform4f(location,x,g,b,a);
            glDrawElements(GL_TRIANGLES,9,GL_UNSIGNED_INT,0);

            glfwSwapBuffers(window);
            glfwPollEvents();

            endTime = (float)glfwGetTime();
            dt = endTime - beginTime;
            beginTime = endTime;

        }

        vao.destroy();
        vb.destroy();
        ib.destroy();

        shader.destroy();

        glfwDestroyWindow(window);
        glfwTerminate();

    }

    int Window::getWidth() {
        return get()->width;
    }

    int Window::getHeight() {
        return get()->height;
    }

    GLFWwindow* Window::getWindow() {
        return get()->window;
    }

    renderer::Shader Window::getShader() {
        return get()->shader;
    }

}
