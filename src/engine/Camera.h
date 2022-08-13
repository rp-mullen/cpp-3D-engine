//
// Created by mu on 8/5/22.
//

#ifndef OPENGLLINUXTEST_CAMERA_H
#define OPENGLLINUXTEST_CAMERA_H

#ifndef GLM_INCLUDED
#define GLM_INCLUDED
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#endif

#include "Window.h"
#include "../renderer/Shader.h"

namespace engine {

    class Camera {
    protected:
        GLFWwindow* window;
    public:
        glm::vec3 position;
        glm::vec3 orientation = glm::vec3(0.0f,0.0f,1.0f);

        glm::vec3 up = glm::vec3(0.0f,1.0f,0.0f);
        glm::mat4 cameraMatrix = glm::mat4(1.0f);

        bool firstClick = true;

        int width, height;

        float speed = 0.1f;
        float sensitivity = 100.0f;

        Camera(glm::vec3 position);

        void updateMatrix(float FOVdeg, float nearPlane, float farPlane);

        void Matrix(renderer::Shader& shader, const char* uniform);

        void Inputs();

    };
}

#endif //OPENGLLINUXTEST_CAMERA_H
