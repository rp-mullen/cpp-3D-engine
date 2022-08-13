//
// Created by mu on 8/8/22.
//

#ifndef OPENGLLINUXTEST_VERTEXBUFFER_H
#define OPENGLLINUXTEST_VERTEXBUFFER_H

#include <GLES3/gl3.h>

namespace renderer {

    class VertexBuffer {
    private:
        unsigned int m_RendererID;
    public:
        VertexBuffer(const void *data, unsigned int size);

        ~VertexBuffer();

        void bind();

        void unbind();

        void destroy();
    };

}
#endif //OPENGLLINUXTEST_VERTEXBUFFER_H
