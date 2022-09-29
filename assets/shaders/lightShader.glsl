# type vertex
# version 330 core

layout (location = 0)  in vec3 aPos;

uniform mat4 model;
uniform mat4 camMatrix;

void main() {
    gl_Position = camMatrix * model * vec4(aPos,1.0f);
}

# type fragment
# version 330 core

out vec4 color;

uniform vec4 lightColor;

void main() {
    color = lightColor;
}