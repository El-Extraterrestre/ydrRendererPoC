#version 460 core
layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gAlbedo;
layout (location = 3) out vec4 gSpec;

void main()
{
    gAlbedo = vec4(0.0, 0.0, 1.0, 1.0);
}