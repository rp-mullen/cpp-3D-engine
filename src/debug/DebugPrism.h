//
// Created by mu on 8/17/22.
//

#ifndef OPENGLLINUXTEST_DEBUGPRISM_H
#define OPENGLLINUXTEST_DEBUGPRISM_H

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "../renderer/Shader.h"
#include "../engine/Camera.h"
#include "../renderer/Mesh.h"

namespace debug {
    class DebugPrism {
    public:
        glm::vec3 center;
        glm::vec3 color;
        glm::mat4 model;

        float size;
        renderer::Mesh *mesh;

        bool updating = false;

        DebugPrism(glm::vec3 center, glm::vec3 color, float size, renderer::Shader& shader);
        ~DebugPrism();

        void setup(renderer::Shader& shader);

        void draw(renderer::Shader &shader, engine::Camera &camera);

        void update(float dt, renderer::Shader& shader);
    };

}

#endif //OPENGLLINUXTEST_DEBUGPRISM_H
