cmake_minimum_required(VERSION 3.10) # common to every CLion project
project(OpenGLLinuxTest) # project name


set(OpenGlLinkers -lGL -lglfw3 -lX11 -lXxf86vm -lpthread -lXi) # setting all the Glut libraries as one variable.


################################################

add_executable(OpenGLLinuxTest1 src/main/Main.cpp src/engine/Window.cpp src/engine/Window.h src/util/Settings.h include/GLAD/glad.c src/renderer/Shader.cpp src/renderer/Shader.h src/debug/Triangle2D.cpp src/debug/Triangle2D.h src/engine/Camera.cpp src/engine/Camera.h src/renderer/Renderer.cpp src/renderer/Renderer.h src/renderer/VertexBuffer.cpp src/renderer/VertexBuffer.h src/renderer/IndexBuffer.cpp src/renderer/IndexBuffer.h src/renderer/VertexArray.cpp src/renderer/VertexArray.h) #common to all clion project
target_link_libraries(OpenGLLinuxTest1 ${OpenGlLinkers}) # linking opengl libraries to the project

#################################################