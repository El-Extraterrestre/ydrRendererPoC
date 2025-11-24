#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec2 TexCoords;
out mat4 mvp;
out vec4 pos;

layout (std140) uniform matrices{
    mat4 model;
    mat4 view;
    mat4 projection;
};

void main()
{
    mvp = view;
    mvp[0].w = 0.0;
    mvp[1].w = 0.0;
    mvp[2].w = 0.0;

    pos = mvp * vec4(0.0, 0.0, 1.0, 1.0);
    TexCoords = aTexCoords;
    gl_Position = vec4(aPos, 1.0);
}