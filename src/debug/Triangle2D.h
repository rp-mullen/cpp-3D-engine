//
// Created by mu on 8/3/22.
//

#ifndef OPENGLLINUXTEST_TRIANGLE2D_H
#define OPENGLLINUXTEST_TRIANGLE2D_H

#include <glm/glm.hpp>
#include "../engine/Window.h"
#include "../renderer/Shader.h"
#include <GLES3/gl3.h>
#include <iostream>

namespace renderer {
    class Triangle2D {
    private:
        glm::vec3 center;
        unsigned int vboID, vaoID;
        float size;
        float *data;
        Shader shader = engine::Window::getShader();

    public:
        Triangle2D(glm::vec3 center, float size);

        void create();

        void start();

        void draw();

        void update(float dt);

        void destroy();
    };
}

#endif //OPENGLLINUXTEST_TRIANGLE2D_H
