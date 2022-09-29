//
// Created by mu on 8/16/22.
//

#include <filesystem>
#include "DebugCube.h"

namespace debug {

    DebugCube::DebugCube(glm::vec3 center, glm::vec3 color, float size) {

        DebugCube::center = center;
        DebugCube::size = size;
        DebugCube::color = color;

        shader.compile();

        renderer::Vertex vertices[] =
                {
                        renderer::Vertex{size*(glm::vec3(-0.1f, -0.1f,  0.1f) + center), color},
                        renderer::Vertex{size*(glm::vec3(-0.1f, -0.1f, -0.1f) + center),color},
                        renderer::Vertex{size*(glm::vec3(0.1f, -0.1f, -0.1f) + center), color},
                        renderer::Vertex{size*(glm::vec3(0.1f, -0.1f,  0.1f) + center), color},
                        renderer::Vertex{size*(glm::vec3(-0.1f,  0.1f,  0.1f) + center), color},
                        renderer::Vertex{size*(glm::vec3(-0.1f,  0.1f, -0.1f) + center), color},
                        renderer::Vertex{size*(glm::vec3(0.1f,  0.1f, -0.1f) + center), color},
                        renderer::Vertex{size*(glm::vec3(0.1f,  0.1f,  0.1f) + center), color}
                };

        GLuint indices[] =
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

        renderer::Texture textures[] = {};

        std::vector<renderer::Vertex> verts(vertices,vertices + sizeof(vertices)/sizeof(renderer::Vertex));
        std::vector<GLuint> ind(indices, indices + sizeof(indices)/sizeof(GLuint));
        std::vector<renderer::Texture> tex(textures, textures + sizeof(textures)/sizeof(renderer::Texture));

        DebugCube::mesh = new renderer::Mesh(verts,ind,tex);
        DebugCube::setup();

    }


    DebugCube::~DebugCube() {
        delete mesh;
    }

    void DebugCube::setup() {
        shader.use();
        model = glm::mat4(1.0f);
        model = glm::translate(model,center);
        glUniformMatrix4fv(glGetUniformLocation(shader.getID(),"model"),1,GL_FALSE,glm::value_ptr(model));

    }

    void DebugCube::update(float t) {
            model = glm::mat4(1.0f);
            center.x = sin(t);
            center.y = cos(t);
            model = glm::translate(model, glm::vec3(center.x, center.y, center.z));
            model = glm::rotate(model, center.x, glm::vec3(0.0, 1.0, 1.0));
            glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
    }

    void DebugCube::draw(engine::Camera &camera) {
        mesh->draw(shader,camera);

    }

}