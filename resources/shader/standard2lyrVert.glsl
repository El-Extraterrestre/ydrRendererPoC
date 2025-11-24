#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm1;
layout (location = 2) in vec4 aNorm2;
layout (location = 2) in vec4 aNorm3;
layout (location = 3) in vec4 aColor1;
layout (location = 3) in vec4 aColor2;
layout (location = 4) in vec2 aTex1;
layout (location = 4) in vec2 aTex2;
layout (location = 4) in vec2 aTex3;

out vec4 vertexColor1;
out vec4 vertexColor2;
out vec4 palColor;
out vec2 TexCoords1;
out vec2 TexCoords2;
out vec3 modelNormal1;
out vec3 modelNormal2;
out vec3 bitangent;
out vec4 screenSpacePosition;
out vec3 position;
out vec2 screenSize;

layout (std140) uniform matrices{
    mat4 model;
    mat4 view;
    mat4 projection;
    vec2 viewSize;
};

uniform sampler2D tintpalettetex;

void main()
{
    vec3 normal1NDC = (aNorm1 * 2.0) - vec3(1.0);
    vec4 normal2NDC = (aNorm2 * 2.0) - vec4(1.0);

    mat3 modelMat = mat3(model[0].xyz, model[1].xyz, model[2].xyz);

    vec3 modelNorm1 = modelMat * normal1NDC;
    vec3 modelNorm2 = modelMat * normal2NDC.xyz;

    vec4 mvpPosition = projection * (view * (model * vec4(aPos, 1.0)));

    vertexColor1 = aColor1;
    vertexColor2 = aColor2;
    palColor = texture(tintpalettetex, vec2(aColor1.z, 0.0));
    TexCoords1 = aTex1;
    TexCoords2 = aTex2;
    modelNormal1 = modelNorm1;
    modelNormal2 = modelNorm2;
    bitangent = cross(modelNorm1, modelNorm2) * normal2NDC.w;
    screenSpacePosition = vec4(mvpPosition.xy * vec2(0.5, -0.5) * viewSize, mvpPosition.zw);
    position = aPos;
    screenSize = viewSize;

    gl_Position = mvpPosition;
}
