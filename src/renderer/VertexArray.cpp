//
// Created by mu on 8/12/22.
//

#include "VertexArray.h"

namespace renderer {

    VertexArray::VertexArray() {
        glGenVertexArrays(1,&vaoID);
    }

    void VertexArray::linkAttrib(VertexBuffer& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
        VBO.bind();
        glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
        glEnableVertexAttribArray(layout);
        VBO.unbind();
    }

    void VertexArray::bind() {
        glBindVertexArray(vaoID);
    }

    void VertexArray::unbind() {
        glBindVertexArray(0);
    }

    void VertexArray::destroy() {
        glDeleteVertexArrays(1,&vaoID);
    }

}