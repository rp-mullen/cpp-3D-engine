# type vertex
# version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec3 aNormal;

out vec3 fColor;
out vec2 fTex;
out vec3 fNormal;
out vec3 currPos;

uniform mat4 camMatrix;
uniform mat4 model;

void main() {

    currPos = vec3(model * vec4(aPos,1.0f));
    gl_Position = camMatrix * vec4(currPos,1.0f);

    fColor = aColor;
    fTex = aTex;
    fNormal = aNormal;
}

# type fragment
# version 330 core

in vec3 fColor;
in vec2 fTex;
in vec3 fNormal;
in vec3 currPos;

out vec4 FragColor;

uniform sampler2D diffuse0;
uniform sampler2D specular0;

uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 camPos;

vec4 pointLight() {

    // difference vector between position and the light source
    vec3 lightVec = lightPos - currPos;
    float dist = length(lightVec);
    float a = 3.0f;
    float b = 0.7;
    float inten = 1.0f / (a * dist * dist + b * dist + 1.0f);

    // ambient lighting
    float ambient = 0.15f;

    // diffuse lighting
    vec3 normal = normalize(fNormal);
    vec3 lightDirection = normalize(lightVec);
    float diffuse = max(dot(normal,lightDirection),0.0f);

    // specular lighting
    float specularLight = 0.50f;
    vec3 viewDirection = normalize(camPos - currPos);
    vec3 reflectionDirection = reflect(-lightDirection,normal);
    float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 8);
    float specular = specAmount * specularLight;

    //return (texture(diffuse0, fTex) * (diffuse * inten + ambient) + texture(specular0,fTex).r * specular * inten) * lightColor;
    return texture(diffuse0, fTex);
}

void main() {

    FragColor = pointLight();
}
