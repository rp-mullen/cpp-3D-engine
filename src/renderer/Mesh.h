//
// Created by mu on 8/15/22.
//

#ifndef OPENGLLINUXTEST_MESH_H
#define OPENGLLINUXTEST_MESH_H

#include <vector>
#include "VertexBuffer.h"
#include "Texture.h"
#include "../engine/Camera.h"
#include "VertexArray.h"

namespace renderer {
    class Mesh {
    public:
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
        std::vector<Texture> textures;

        VertexArray vao;

        Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures);

        void draw(Shader& shader, engine::Camera& camera);
    };
}

#endif //OPENGLLINUXTEST_MESH_H
