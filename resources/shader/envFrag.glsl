#version 460 core
out vec4 fragColor;

in vec2 TexCoords;
in mat4 mvp;
in vec4 pos;

uniform vec3 rot;
uniform vec3 sun;

void main()
{
    vec4 color = mvp *vec4(0.1,0.0,0.0,1.0);
    //color = mvp * color;
    //fragColor = vec4(TexCoords, 0.0, 1.0);
    float h = pos.z ;//+ TexCoords.y;
    //if(pos.y + (1.0 - TexCoords.y) > 1.0){
    //    fragColor = vec4(vec3(pos.z),1.0);
    //}
    //else {
    //    fragColor = vec4(0.0,0.0,0.0,1.0);
    //}
    vec3 sRot = rot + vec3((TexCoords*0.5), 0.0);
    float sunPos = dot(sRot, sun);
    float sunFactor = max(min(((sunPos-0.9)*10), 1.0), 0.0);
    float up = dot(sRot, vec3(0.0,0.0,1.0));
    float factor = min((up + TexCoords.y/10.0 + 0.4)*2, 1.0);
    
    fragColor = vec4(0.75, 0.73, 1.0, 1.0) * factor + vec4(0.0,0.0,0.0,1.0) * (1.0-factor) + vec4(1.0, 1.0, 0.0, 1.0) * sunFactor;
    
}