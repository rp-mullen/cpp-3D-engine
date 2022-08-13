//
// Created by mu on 8/3/22.
//

#include "Triangle2D.h"


namespace renderer {

    bool firstCreation = true;

    Triangle2D::Triangle2D(glm::vec3 center, float size) {
        this->center = center;
        this->size = size;

        create();
        start();

    }

    void Triangle2D::create() {
        if (firstCreation) {
            center.x /= engine::Window::getWidth();
            center.y /= engine::Window::getHeight();
            center.z = 0.0f;
            std::cout << "Triangle: {" << center.x << ", " << center.y << ", " << center.z << "}" << std::endl;
            firstCreation = false;
        }

        // lower left
        glm::vec3 e1 = center;
        e1.x -= size;
        e1.y -= size;

        // top
        glm::vec3 e2 = center;
        e2.y += size;

        // lower right
        glm::vec3 e3 = center;
        e3.x += size;
        e3.y -= size;

        data = new float[9]{
                e1.x, e1.y, e1.z,
                e2.x, e2.y, e2.z,
                e3.x, e3.y, e3.z
        };

    }

    void Triangle2D::update(float dt) {

        GLFWwindow* window = engine::Window::get()->getWindow();
        if (glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS) {
            center.y += dt;
        }
        if (glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS) {
            center.x -= dt;
        }
        if (glfwGetKey(window,GLFW_KEY_S) == GLFW_PRESS) {
            center.y -= dt;
        }
        if (glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS) {
            center.x += dt;
        }
        if (glfwGetKey(window,GLFW_KEY_UP) == GLFW_PRESS) {
            size += dt;
        }
        if (glfwGetKey(window,GLFW_KEY_DOWN) == GLFW_PRESS) {
            size -= dt;
        }

        create();
        start();

    }

    void Triangle2D::start() {
        glGenVertexArrays(1,&vaoID);
        glBindVertexArray(vaoID);

        glGenBuffers(1,&vboID);

        glBindBuffer(GL_ARRAY_BUFFER,vboID);
        glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), data, GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float),0);
        glEnableVertexAttribArray(0);

    }

    void Triangle2D::draw() {
        glBindBuffer(GL_ARRAY_BUFFER,vboID);

        shader.use();

        glBindVertexArray(vaoID);
        glEnableVertexAttribArray(0);

        glDrawArrays(GL_TRIANGLES,0,3);

        glDisableVertexAttribArray(0);
        glBindVertexArray(0);

        shader.detach();
    }

    void Triangle2D::destroy() {
        delete data;
    }

}