//
// Created by mu on 8/8/22.
//

#ifndef OPENGLLINUXTEST_VERTEXBUFFER_H
#define OPENGLLINUXTEST_VERTEXBUFFER_H

#include <GLES3/gl3.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>

namespace renderer {

    struct Vertex {
        glm::vec3 position;
        glm::vec3 color;
        glm::vec2 texUV;
        glm::vec3 normal;
    };

    class VertexBuffer {
    private:
        unsigned int m_RendererID;
    public:
        VertexBuffer(std::vector<Vertex>& vertices);

        ~VertexBuffer();

        void bind();

        void unbind();

        void destroy();
    };

}
#endif //OPENGLLINUXTEST_VERTEXBUFFER_H
