//
// Created by mu on 8/3/22.
//

#ifndef OPENGLLINUXTEST_SHADER_H
#define OPENGLLINUXTEST_SHADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <GLES3/gl3.h>

namespace renderer {

    class Shader {
    private:
        unsigned int shaderProgramID;

        std::string fragmentSource;
        std::string vertexSource;
        std::string filepath;

        unsigned int vertexID;
        unsigned int fragmentID;

    public:
        Shader(std::string filepath);

        void compile();

        void use();

        void detach();

        void destroy();

        unsigned int getID();
    };
}

#endif //OPENGLLINUXTEST_SHADER_H
