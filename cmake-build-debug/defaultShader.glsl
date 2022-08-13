# type vertex
# version 330 core

layout (location = 0) in vec3 aPos;

void main() {

    gl_Position = vec4(aPos,1.0);
}

# type fragment
# version 330 core

uniform vec4 u_Color;

out vec4 color;

void main() {
    color = u_Color;
}
