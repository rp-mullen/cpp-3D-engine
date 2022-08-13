//
// Created by mu on 8/12/22.
//

#include "VertexArray.h"

namespace renderer {

    VertexArray::VertexArray() {
        glGenVertexArrays(1,&vaoID);
    }

    void VertexArray::LinkVBO(VertexBuffer& VBO, unsigned int layout) {
        VBO.bind();
        glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
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