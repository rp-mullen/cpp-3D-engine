//
// Created by mu on 8/10/22.
//

#ifndef OPENGLLINUXTEST_INDEXBUFFER_H
#define OPENGLLINUXTEST_INDEXBUFFER_H

#include <GLES3/gl3.h>

namespace renderer {

    class IndexBuffer {

    private:
        unsigned int m_RendererID;
        unsigned int m_Count;
    public:
        IndexBuffer(const unsigned int *data, unsigned int count);

        ~IndexBuffer();

        void bind();

        void unbind();

        void destroy();

        inline unsigned int getCount() const { return m_Count; }
    };

}
#endif //OPENGLLINUXTEST_INDEXBUFFER_H
