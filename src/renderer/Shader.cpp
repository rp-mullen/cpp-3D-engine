//
// Created by mu on 8/3/22.
//

#include "Shader.h"

namespace renderer {

    bool beingUsed = false;

    Shader::Shader(std::string filepath) {
        this->filepath = filepath;

        vertexSource = "";
        fragmentSource = "";

        std::cout << "Building shader..." << std::endl;
        try {

            std::string source;

            bool vertexReading = false;
            bool fragmentReading = false;
            bool ignoreLine = false;

            std::cout << "Filepath: " << this->filepath << std::endl;

            std::fstream ifs;
            std::string line;
            ifs.open(this->filepath);
            if (ifs.is_open()){
                while(getline(ifs, line)){  //read data from file object and put it into string.
                    if (line.find("# type vertex") != std::string::npos) {
                        vertexReading = true;
                        ignoreLine = true;
                    }
                    else if (line.find("# type fragment") != std::string::npos) {
                            vertexReading = false;
                            fragmentReading = true;
                            ignoreLine = true;
                        }

                    if (vertexReading) {
                        if (!ignoreLine) {
                            vertexSource += line + "\n";
                        } else {
                            ignoreLine = false;
                        }
                    } else if (fragmentReading) {
                        if (!ignoreLine) {
                            fragmentSource += line + "\n";
                        } else {
                            ignoreLine = false;
                        }
                    }
                }
                ifs.close();

            } else {
                std::cout << "Error: couldn't open file." << std::endl;
            }
            std::cout << fragmentSource << std::endl;
            std::cout << vertexSource << std::endl;

        } catch (const char* message) {
            std::cout << "Error parsing shader" << message << std::endl;
        }

    }

    void Shader::compile() {
        const char* vertexContent = vertexSource.c_str();
        const char* fragmentContent = fragmentSource.c_str();

        shaderProgramID = glCreateProgram();

        // create vertex shader
        vertexID = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexID, 1, &vertexContent, nullptr);
        glCompileShader(vertexID);

        int result;
        glGetShaderiv(vertexID,GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE) {
            std::cout << "Error: Could not compile Vertex Shader." << std::endl;
            std::cout << "Error: Could not compile Fragment Shader." << std::endl;
            int length;
            glGetShaderiv(vertexID,GL_INFO_LOG_LENGTH,&length);
            char* message = (char*)alloca(length * sizeof(char));
            glGetShaderInfoLog(vertexID,length,&length,message);
            std::cout << message << std::endl;
        } else {
            std::cout << "Vertex Shader compiled successfully." << std::endl;

        }

        // create fragment shader
        fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentID,1,&fragmentContent,nullptr);
        glCompileShader(fragmentID);

        glGetShaderiv(fragmentID,GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE) {
            std::cout << "Error: Could not compile Fragment Shader." << std::endl;
            int length;
            glGetShaderiv(fragmentID,GL_INFO_LOG_LENGTH,&length);
            char* message = (char*)alloca(length * sizeof(char));
            glGetShaderInfoLog(fragmentID,length,&length,message);
            std::cout << message << std::endl;

        } else {
            std::cout << "Fragment Shader compiled successfully." << std::endl;

        }

        glAttachShader(shaderProgramID, vertexID);
        glAttachShader(shaderProgramID, fragmentID);

        glLinkProgram(shaderProgramID);
        glValidateProgram(shaderProgramID);

        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);

    }

    void Shader::use() {
        glUseProgram(shaderProgramID);
    }

    void Shader::detach() {
        glUseProgram(0);
        beingUsed = false;
    }

    void Shader::destroy() {
        glDeleteProgram(shaderProgramID);
    }

    unsigned int Shader::getID() {
        return shaderProgramID;
    }

}