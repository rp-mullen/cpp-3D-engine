//
// Created by mu on 8/15/22.
//

#include "Mesh.h"

namespace renderer {

    Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, std::vector<Texture> &textures)
    {
        Mesh::vertices = vertices;
        Mesh::indices = indices;
        Mesh::textures = textures;

        vao.bind();

        renderer::VertexBuffer vb(vertices);
        renderer::IndexBuffer ib(indices);

        vao.linkAttrib(vb,0,3,GL_FLOAT,sizeof(Vertex),(void*)0);
        vao.linkAttrib(vb,1,3,GL_FLOAT,sizeof(Vertex),(void*)(3 * sizeof(float)));
        vao.linkAttrib(vb, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
        vao.linkAttrib(vb, 3, 3, GL_FLOAT, sizeof(Vertex), (void*)(8 * sizeof(float)));

        vao.unbind();
        vb.unbind();
        ib.unbind();
    }

    void Mesh::draw(Shader& shader, engine::Camera& camera) {
        shader.use();
        vao.bind();

        unsigned int numDiffuse = 0;
        unsigned int numSpecular = 0;

        for (unsigned int i = 0; i < textures.size(); i++) {
            std::string num;
            std::string type = textures[i].getType();
            if (type == "diffuse") {
                num = std::to_string(numDiffuse++);
            }
            else if (type == "specular") {
                num = std::to_string(numSpecular++);
            }
            textures[i].upload(shader,(type+num).c_str(),i);
            textures[i].bind();
        }

        glUniform3f(glGetUniformLocation(shader.getID(),"camPos"),camera.position.x,camera.position.y, camera.position.z);
        camera.upload(shader,"camMatrix");

        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }

}