#version 460 core
layout (location = 0) out vec2 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gAlbedo;
layout (location = 3) out vec4 gSpec;

in vec4 vertexColor1;
in vec4 vertexColor2;
in vec4 palColor;
in vec2 TexCoords1;
in vec2 TexCoords2;
in vec3 modelNormal1;
in vec3 modelNormal2;
in vec3 bitangent;
in vec4 screenSpacePosition;
in vec3 position;
in vec2 screenSize;

uniform sampler2D lyr0diffusetex;
uniform sampler2D lyr0normaltex;
uniform sampler2D lyr0materialatex;
uniform sampler2D lyr0materialbtex;
uniform sampler2D lyr1diffusetex;
uniform sampler2D lyr1normaltex;
uniform sampler2D lyr1materialatex;
uniform sampler2D lyr1materialbtex;
uniform sampler2D dirtdiffusetex;
uniform sampler2D controltexturetex;
uniform sampler2D aotexturetex;
uniform sampler2D detailtexarrayn;


void main()
{
    vec3 modelNormal1Facing = modelNormal1 * float(gl_FrontFacing ? 1 : (-1));
    vec2 normalMap = texture(lyr0normaltex, TexCoords1).xy;
    vec3 combinedNormalMap = normalize((normalize(modelNormal2) * normalMap.x) + (normalize(bitangent) * normalMap.y) + (normalize(modelNormal1Facing) * 0.01));
    gPosition = ((screenSpacePosition.xy / vec2(screenSpacePosition.w)) + (screenSize * 0.5)) - gl_FragCoord.xy;
    gAlbedo = texture(lyr0diffusetex, TexCoords1) * vec4(0.4) + texture(lyr1diffusetex, TexCoords2) * vec4(0.4) + texture(dirtdiffusetex, TexCoords2) * vec4(0.2);
    gNormal = vec3(0);//(combinedNormalMap * 0.5) + vec3(0.5);
    gSpec = vec4(texture(lyr0materialatex, TexCoords1).xy, 0.0, 1.0);
}