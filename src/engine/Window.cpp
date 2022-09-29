//
// Created by mu on 8/3/22.
//

#include <filesystem>
namespace fs = std::filesystem;

#include "Window.h"
#include "../renderer/VertexArray.h"
#include "../renderer/Texture.h"
#include "../renderer/Mesh.h"
#include "../debug/DebugCube.h"
#include "../debug/DebugPrism.h"


namespace engine {

    std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
    std::string texPath0 = "/assets/textures/brick.png";
    std::string texPath1 = "/assets/textures/brick_specular.png";

    // Vertices coordinates
    renderer::Vertex vertices[] =
            {                                               //     COORDINATES     /                                COLORS                                       TEXTURE UV                                            NORMALS       //
                    renderer::Vertex{glm::vec3(-0.5f, 0.0f,  0.5f),     glm::vec3(0.83f, 0.70f, 0.44f), 	     glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, -1.0f, 0.0f)}, // Bottom side
                    renderer::Vertex{glm::vec3(-0.5f, 0.0f, -0.5f),     glm::vec3(0.83f, 0.70f, 0.44f),	     glm::vec2(0.0f, 5.0f),      glm::vec3(0.0f, -1.0f, 0.0f)}, // Bottom side
                    renderer::Vertex{glm::vec3(0.5f, 0.0f, -0.5f),     glm::vec3(0.83f, 0.70f, 0.44f),	     glm::vec2(5.0f, 5.0f),      glm::vec3(0.0f, -1.0f, 0.0f)}, // Bottom side
                    renderer::Vertex{glm::vec3(0.5f, 0.0f,  0.5f),     glm::vec3(0.83f, 0.70f, 0.44f),	     glm::vec2(5.0f, 0.0f),      glm::vec3(0.0f, -1.0f, 0.0f)}, // Bottom side

                    renderer::Vertex{glm::vec3(-0.5f, 0.0f,  0.5f),     glm::vec3(0.83f, 0.70f, 0.44f), 	     glm::vec2(0.0f, 0.0f),     glm::vec3(-0.8f, 0.5f,  0.0f)}, // Left Side
                    renderer::Vertex{glm::vec3(-0.5f, 0.0f, -0.5f),     glm::vec3(0.83f, 0.70f, 0.44f),	     glm::vec2(5.0f, 0.0f),     glm::vec3(-0.8f, 0.5f,  0.0f)}, // Left Side
                    renderer::Vertex{glm::vec3(0.0f, 0.8f,  0.0f),      glm::vec3(0.92f, 0.86f, 0.76f),	     glm::vec2(2.5f, 5.0f),     glm::vec3(-0.8f, 0.5f,  0.0f)}, // Left Side

                    renderer::Vertex{glm::vec3(-0.5f, 0.0f, -0.5f),    glm::vec3(0.83f, 0.70f, 0.44f),	    glm::vec2(5.0f, 0.0f),      glm::vec3(0.0f, 0.5f, -0.8f)}, // Non-facing side
                    renderer::Vertex{glm::vec3(0.5f, 0.0f, -0.5f),     glm::vec3(0.83f, 0.70f, 0.44f),	    glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.5f, -0.8f)}, // Non-facing side
                    renderer::Vertex{glm::vec3(0.0f, 0.8f,  0.0f),     glm::vec3(0.92f, 0.86f, 0.76f),	    glm::vec2(2.5f, 5.0f),      glm::vec3(0.0f, 0.5f, -0.8f)}, // Non-facing side

                    renderer::Vertex{glm::vec3(0.5f, 0.0f, -0.5f),     glm::vec3(0.83f, 0.70f, 0.44f),	    glm::vec2(0.0f, 0.0f),      glm::vec3(0.8f, 0.5f,  0.0f)}, // Right side
                    renderer::Vertex{glm::vec3(0.5f, 0.0f,  0.5f),     glm::vec3(0.83f, 0.70f, 0.44f),	    glm::vec2(5.0f, 0.0f),      glm::vec3(0.8f, 0.5f,  0.0f)}, // Right side
                    renderer::Vertex{glm::vec3(0.0f, 0.8f,  0.0f),     glm::vec3(0.92f, 0.86f, 0.76f),	    glm::vec2(2.5f, 5.0f),      glm::vec3(0.8f, 0.5f,  0.0f)}, // Right side

                    renderer::Vertex{glm::vec3(0.5f, 0.0f,  0.5f),     glm::vec3(0.83f, 0.70f, 0.44f),	    glm::vec2(5.0f, 0.0f),      glm::vec3(0.0f, 0.5f,  0.8f)}, // Facing side
                    renderer::Vertex{glm::vec3(-0.5f, 0.0f,  0.5f),    glm::vec3(0.83f, 0.70f, 0.44f), 	    glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.5f,  0.8f)}, // Facing side
                    renderer::Vertex{glm::vec3(0.0f, 0.8f,  0.0f),     glm::vec3(0.92f, 0.86f, 0.76f),	    glm::vec2(2.5f, 5.0f),      glm::vec3(0.0f, 0.5f,  0.8f)}  // Facing side
            };


    GLuint indices[] =
            {
                    0, 1, 2, // Bottom side
                    0, 2, 3, // Bottom side
                    4, 6, 5, // Left side
                    7, 9, 8, // Non-facing side
                    10, 12, 11, // Right side
                    13, 15, 14 // Facing side
            };

    renderer::Texture textures[] = {

            renderer::Texture((parentDir+texPath0).c_str(),"diffuse",0,GL_RGBA,GL_UNSIGNED_BYTE),
            renderer::Texture((parentDir + texPath1).c_str(), "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
    };

    // LIGHT CUBE
    renderer::Vertex lightVertices[] =
            { //     COORDINATES     //
                    renderer::Vertex{glm::vec3(-0.1f, -0.1f,  0.1f)},
                    renderer::Vertex{glm::vec3(-0.1f, -0.1f, -0.1f)},
                    renderer::Vertex{glm::vec3(0.1f, -0.1f, -0.1f)},
                    renderer::Vertex{glm::vec3(0.1f, -0.1f,  0.1f)},
                    renderer::Vertex{glm::vec3(-0.1f,  0.1f,  0.1f)},
                    renderer::Vertex{glm::vec3(-0.1f,  0.1f, -0.1f)},
                    renderer::Vertex{glm::vec3(0.1f,  0.1f, -0.1f)},
                    renderer::Vertex{glm::vec3(0.1f,  0.1f,  0.1f)}
            };

    GLuint lightIndices[] =
            {
                    0, 1, 2,
                    0, 2, 3,
                    0, 4, 7,
                    0, 7, 3,
                    3, 7, 6,
                    3, 6, 2,
                    2, 6, 5,
                    2, 5, 1,
                    1, 5, 4,
                    1, 4, 0,
                    4, 5, 6,
                    4, 6, 7
            };

    static Window* instance = nullptr;

    Window::Window() {
        width = 1050;
        height = 1050;
        title = (char*)"MainEngineWindow";
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
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width,height,title,nullptr,nullptr);

        glfwMakeContextCurrent(window);

        glViewport(0, 0, width, height);

        glfwShowWindow(window);


//        glEnable(GL_BLEND);
//        glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
    }

    void Window::loop() {

        // object shader
        shader.compile();
        shader.use();

        std::vector<renderer::Vertex> verts(vertices,vertices + sizeof(vertices) / sizeof(renderer::Vertex));
        std::vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
        std::vector<renderer::Texture> tex(textures, textures + sizeof(textures) / sizeof(renderer::Texture));

        renderer::Mesh pyramid(verts,ind,tex);


        // light shader
        renderer::Shader lightShader("lightShader.glsl");
        lightShader.compile();
        lightShader.use();

        std::vector<renderer::Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(renderer::Vertex));
        std::vector<GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));

        renderer::Mesh light(lightVerts, lightInd, tex);

        // set up positions / uniforms
        glm::vec4 lightColor = glm::vec4(1.0f,1.0f,1.0f,1.0f);
        glm::vec3 lightPos = glm::vec3(0.5f,0.5f,0.5f);
        glm::mat4 lightModel = glm::mat4(1.0f);
        lightModel = glm::translate(lightModel,lightPos);

        glm::vec3 pyramidPos = glm::vec3(0.0f,0.0f,0.0f);
        glm::mat4 pyramidModel = glm::mat4(1.0f);
        pyramidModel = glm::translate(pyramidModel,pyramidPos);

        lightShader.use();
        glUniformMatrix4fv(glGetUniformLocation(lightShader.getID(),"model"),1, GL_FALSE,glm::value_ptr(lightModel));
        glUniform4f(glGetUniformLocation(lightShader.getID(), "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
        shader.use();
        glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
        glUniform4f(glGetUniformLocation(shader.getID(), "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
        glUniform3f(glGetUniformLocation(shader.getID(), "lightPos"), lightPos.x, lightPos.y, lightPos.z);

        // debug objects

        renderer::Shader debugShader0("debugShader.glsl");
        renderer::Shader debugShader1("debugShader.glsl");

        debug::DebugCube dbc(glm::vec3(0.0,0.0,1.0), glm::vec3(1.0,0.0,0.0), 1.0);
        debug::DebugCube dbc2(glm::vec3(0.0,1.0,0.0), glm::vec3(0.0,0.0,1.0), 2.0);
        debug::DebugPrism dbp(glm::vec3(0.5,0.5,-0.5),glm::vec3(0.0,1.0,0.0),0.5,debugShader0);
        debug::DebugPrism dbp2(glm::vec3(1.0,0.0,0.0),glm::vec3(1.0,1.0,1.1),1.0,debugShader1);

        glEnable(GL_DEPTH_TEST);

        Camera camera(glm::vec3(0.0f,0.0f,2.0f));

        auto beginTime = (float)glfwGetTime();
        float endTime;
        float dt = -1.0f;
        

        // TODO: fix texture error on pyramid
        // TODO: figure out why both debug cubes are updating instead of just one
        while (!glfwWindowShouldClose(window)) {

            t += dt;

            glClearColor(r,g,b,a);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            camera.Inputs();
            camera.updateMatrix(45.0f,0.1f,100.0f);


            pyramid.draw(shader,camera);

            light.draw(lightShader,camera);

            dbc.draw(camera);
            dbc2.draw(camera);

            dbc.update(t);
            dbc2.update(t);

            dbp.draw(debugShader0,camera);
            dbp.update(t,debugShader0);

            dbp2.draw(debugShader1,camera);
            dbp2.update(t/10,debugShader1);

            glfwSwapBuffers(window);
            glfwPollEvents();

            endTime = (float)glfwGetTime();
            dt = endTime - beginTime;
            beginTime = endTime;

        }


        shader.destroy();
        lightShader.destroy();

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

    float Window::getTime() {
        return get()->t;
    }

}
