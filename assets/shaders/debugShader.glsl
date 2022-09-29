# type vertex
# version 330

layout (location = 0) in vec3 aPos;

void main() {
    gl_Position = vec4(aPos, 1.0);
}

# type fragment
# version 330

out vec4 fColor

uniform vec3 aColor;

void main() {
    fColor = aColor;
}