//
// Created by mu on 8/12/22.
//

#ifndef OPENGLLINUXTEST_VERTEXARRAY_H
#define OPENGLLINUXTEST_VERTEXARRAY_H

#include "VertexBuffer.h"

namespace renderer {

    class VertexArray {
    public:
        unsigned int vaoID;

        VertexArray();

        void linkAttrib(VertexBuffer& VBO, unsigned int layout, unsigned int numComponents, GLenum type, GLsizeiptr stride, void* offset);
        void bind();
        void unbind();
        void destroy();
    };

}

#endif //OPENGLLINUXTEST_VERTEXARRAY_H
