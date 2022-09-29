# type vertex
# version 330

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform mat4 camMatrix;
uniform mat4 model;

out vec3 fColor;

void main() {
    gl_Position = camMatrix * model * vec4(aPos, 1.0);
    fColor = aColor;
}

# type fragment
# version 330

in vec3 fColor;

out vec4 color;

void main() {
    color = vec4(fColor,1.0);
}