//
// Created by mu on 8/16/22.
//

#ifndef OPENGLLINUXTEST_DEBUGCUBE_H
#define OPENGLLINUXTEST_DEBUGCUBE_H


#include <glm/vec3.hpp>
#include <filesystem>
#include "../renderer/Mesh.h"
namespace fs = std::filesystem;
namespace debug {

    class DebugCube {
    public:
        glm::vec3 center;
        glm::vec3 color;
        glm::mat4 model;

        renderer::Shader shader = renderer::Shader("debugShader.glsl");

        float size;
        renderer::Mesh *mesh;

        bool updating = false;

        DebugCube(glm::vec3 center, glm::vec3 color, float size);
        ~DebugCube();

        void setup();

        void draw(engine::Camera &camera);

        void update(float dt);
    };
}

#endif //OPENGLLINUXTEST_DEBUGCUBE_H
