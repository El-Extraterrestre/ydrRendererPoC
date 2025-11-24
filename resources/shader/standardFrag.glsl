#version 460 core
layout (location = 0) out vec2 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gAlbedo;
layout (location = 3) out vec4 gSpec;

in vec4 vertexColor;
in vec4 palColor;
in vec2 transformedTexCoords;
in vec3 modelNormal1;
in vec3 modelNormal2;
in vec3 bitangent;
in vec4 screenSpacePosition;
in vec3 position;
in vec2 screenSize;

uniform sampler2D _0xe9f32960;
uniform sampler2D diffusetex;
uniform sampler2D detailtexarrayn;
uniform sampler2D bumptex;
uniform sampler2D speculartex;
uniform sampler2D speculartex2;

void main()
{
    vec3 modelNormal1Facing = modelNormal1 * float(gl_FrontFacing ? 1 : (-1));
    vec2 normalMap = texture(bumptex, transformedTexCoords).xy;
    vec3 combinedNormalMap = normalize((normalize(modelNormal2) * normalMap.x) + (normalize(bitangent) * normalMap.y) + (normalize(modelNormal1Facing) * 0.01));
    gPosition = ((screenSpacePosition.xy / vec2(screenSpacePosition.w)) + (screenSize * 0.5)) - gl_FragCoord.xy;
    gAlbedo = texture(diffusetex, transformedTexCoords) ;//* palColor;
    gNormal = (combinedNormalMap * 0.5) + vec3(0.5);
    gSpec = vec4(texture(speculartex, transformedTexCoords).xy, 0.0, 1.0);
}