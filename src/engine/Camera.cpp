//
// Created by mu on 8/5/22.
//


#include "Camera.h"


namespace engine {

    Camera::Camera(glm::vec3 position) {
        window = Window::get()->getWindow();
        width = Window::get()->getWidth();
        height = Window::get()->getHeight();
        this->position = position;
    }

    void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane) {

        // initialize view and projection matrices
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);

        view = glm::lookAt(position, position + orientation, up);
        projection = glm::perspective(glm::radians(FOVdeg), (float)(width/height), nearPlane, farPlane);

        cameraMatrix = projection * view;
    }

    void Camera::upload(renderer::Shader& shader, const char *uniform) {
        glUniformMatrix4fv(glGetUniformLocation(shader.getID(),uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
    }

    void Camera::Inputs() {

        t = Window::get()->getTime();

        // Handles key inputs
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            position += speed * orientation;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            position += speed * -glm::normalize(glm::cross(orientation, up));
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            position += speed * -orientation;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            position += speed * glm::normalize(glm::cross(orientation, up));
        }
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        {
            position += speed * up;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        {
            position += speed * -up;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        {
            speed = 0.4f;
        }
        else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
        {
            speed = 0.1f;
        }

        // TODO: make this better
        if (glfwGetKey(window,GLFW_KEY_M)) {

            if (wireframeEnabled == false ) {
                if (!checkTime) {
                    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                    wireframeEnabled = true;
                    checkTime = true;
                }

            }
            else {
                if (!checkTime) {
                    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                    wireframeEnabled = false;
                    checkTime = true;
                }

            }

            M_time += 0.01f;

            if ((M_time) >= 0.08f) {
                checkTime = false;
                M_time = 0.0f;
            }

        }


        // Handles mouse inputs
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        {
            // Hides mouse cursor
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

            // Prevents camera from jumping on the first click
            if (firstClick)
            {
                glfwSetCursorPos(window, (width / 2), (height / 2));
                firstClick = false;
            }

            // Stores the coordinates of the cursor
            double mouseX;
            double mouseY;
            // Fetches the coordinates of the cursor
            glfwGetCursorPos(window, &mouseX, &mouseY);

            // Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
            // and then "transforms" them into degrees
            float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
            float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

            // Calculates upcoming vertical change in the orientation
            glm::vec3 newOrientation = glm::rotate(orientation, glm::radians(-rotX), glm::normalize(glm::cross(orientation, up)));

            // Decides whether or not the next vertical orientation is legal or not
            if (abs(glm::angle(newOrientation, up) - glm::radians(90.0f)) <= glm::radians(85.0f))
            {
                orientation = newOrientation;
            }

            // Rotates the orientation left and right
            orientation = glm::rotate(orientation, glm::radians(-rotY), up);

            // Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
            glfwSetCursorPos(window, (width / 2), (height / 2));
        }
        else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
        {
            // Unhides cursor since camera is not looking around anymore
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            // Makes sure the next time the camera looks around it doesn't jump
            firstClick = true;
        }
    }

}