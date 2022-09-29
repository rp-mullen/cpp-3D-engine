//
// Created by mu on 8/17/22.
//

#include "DebugPrism.h"

namespace debug {

    DebugPrism::DebugPrism(glm::vec3 center, glm::vec3 color, float size, renderer::Shader& shader) {

        DebugPrism::center = center;
        DebugPrism::color = color;
        DebugPrism::size = size;

        renderer::Vertex vertices[] =
                {
                        renderer::Vertex{size*(glm::vec3(-0.5f, 0.0f,  0.5f)+center),     color, 	     glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, -1.0f, 0.0f)}, // Bottom side
                        renderer::Vertex{size*(glm::vec3(-0.5f, 0.0f, -0.5f)+center),     color,	     glm::vec2(0.0f, 5.0f),      glm::vec3(0.0f, -1.0f, 0.0f)}, // Bottom side
                        renderer::Vertex{size*(glm::vec3(0.5f, 0.0f, -0.5f)+center),     color,	     glm::vec2(5.0f, 5.0f),      glm::vec3(0.0f, -1.0f, 0.0f)}, // Bottom side
                        renderer::Vertex{size*(glm::vec3(0.5f, 0.0f,  0.5f)+center),     color,	     glm::vec2(5.0f, 0.0f),      glm::vec3(0.0f, -1.0f, 0.0f)}, // Bottom side

                        renderer::Vertex{size*(glm::vec3(-0.5f, 0.0f,  0.5f)+center),     color, 	     glm::vec2(0.0f, 0.0f),     glm::vec3(-0.8f, 0.5f,  0.0f)}, // Left Side
                        renderer::Vertex{size*(glm::vec3(-0.5f, 0.0f, -0.5f)+center),     color,	     glm::vec2(5.0f, 0.0f),     glm::vec3(-0.8f, 0.5f,  0.0f)}, // Left Side
                        renderer::Vertex{size*(glm::vec3(0.0f, 0.8f,  0.0f)+center),      color,	     glm::vec2(2.5f, 5.0f),     glm::vec3(-0.8f, 0.5f,  0.0f)}, // Left Side

                        renderer::Vertex{size*(glm::vec3(-0.5f, 0.0f, -0.5f)+center),    color,	    glm::vec2(5.0f, 0.0f),      glm::vec3(0.0f, 0.5f, -0.8f)}, // Non-facing side
                        renderer::Vertex{size*(glm::vec3(0.5f, 0.0f, -0.5f)+center),     color,	    glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.5f, -0.8f)}, // Non-facing side
                        renderer::Vertex{size*(glm::vec3(0.0f, 0.8f,  0.0f)+center),     color,	    glm::vec2(2.5f, 5.0f),      glm::vec3(0.0f, 0.5f, -0.8f)}, // Non-facing side

                        renderer::Vertex{size*(glm::vec3(0.5f, 0.0f, -0.5f)+center),     color,	    glm::vec2(0.0f, 0.0f),      glm::vec3(0.8f, 0.5f,  0.0f)}, // Right side
                        renderer::Vertex{size*(glm::vec3(0.5f, 0.0f,  0.5f)+center),     color,	    glm::vec2(5.0f, 0.0f),      glm::vec3(0.8f, 0.5f,  0.0f)}, // Right side
                        renderer::Vertex{size*(glm::vec3(0.0f, 0.8f,  0.0f)+center),     color,	    glm::vec2(2.5f, 5.0f),      glm::vec3(0.8f, 0.5f,  0.0f)}, // Right side

                        renderer::Vertex{size*(glm::vec3(0.5f, 0.0f,  0.5f)+center),     color,	    glm::vec2(5.0f, 0.0f),      glm::vec3(0.0f, 0.5f,  0.8f)}, // Facing side
                        renderer::Vertex{size*(glm::vec3(-0.5f, 0.0f,  0.5f)+center),    color, 	    glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.5f,  0.8f)}, // Facing side
                        renderer::Vertex{size*(glm::vec3(0.0f, 0.8f,  0.0f)+center),     color,	    glm::vec2(2.5f, 5.0f),      glm::vec3(0.0f, 0.5f,  0.8f)}  // Facing side
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

        renderer::Texture textures[] = {};

        std::vector<renderer::Vertex> verts(vertices,vertices + sizeof(vertices)/sizeof(renderer::Vertex));
        std::vector<GLuint> ind(indices, indices + sizeof(indices)/sizeof(GLuint));
        std::vector<renderer::Texture> tex(textures, textures + sizeof(textures)/sizeof(renderer::Texture));

        DebugPrism::mesh = new renderer::Mesh(verts,ind,tex);
        DebugPrism::setup(shader);

    }

    DebugPrism::~DebugPrism() {
        delete mesh;
    }

    void DebugPrism::setup(renderer::Shader &shader) {
        shader.use();
        model = glm::mat4(1.0f);
        model = glm::translate(model,center);
        glUniformMatrix4fv(glGetUniformLocation(shader.getID(),"model"),1,GL_FALSE,glm::value_ptr(model));

    }

    void DebugPrism::update(float t, renderer::Shader &shader) {
        float a = 2.0f;
        model = glm::mat4(1.0f);
        center.z = a*sin(t);
        model = glm::translate(model, glm::vec3(center.x, center.y, center.z));
        model = glm::rotate(model, center.z, glm::vec3(0.0, 1.0, 1.0));
        glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "model"), 1, GL_FALSE, glm::value_ptr(model));

    }

    void DebugPrism::draw(renderer::Shader &shader, engine::Camera &camera) {
        mesh->draw(shader,camera);
    }

}