//
// Created by mu on 8/13/22.
//

#ifndef OPENGLLINUXTEST_TEXTURE_H
#define OPENGLLINUXTEST_TEXTURE_H

#include "../../include/stb/stb_image.h"
#include "Shader.h"
#include <GLES3/gl3.h>

namespace renderer {

    class Texture {
    private:
        GLuint texID;
        GLuint unit;
        const char* type;
    public:

        Texture(const char* filepath, const char* texType, GLenum slot, GLenum format, GLenum pixelType);

        void bind();
        void upload(Shader& shader, const char* uniform, GLuint unit);
        void unbind();
        void destroy();

        const char* getType();
    };

}
#endif //OPENGLLINUXTEST_TEXTURE_H
