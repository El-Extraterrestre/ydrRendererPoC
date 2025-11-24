#version 460 core
out vec4 fragColor;

in vec2 TexCoords;

uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gAlbedo;
uniform sampler2D gSpec;

uniform vec3 viewPos;
uniform vec3 sun;

void main()
{
    // retrieve data from gbuffer
    vec3 fragPos = texture(gPosition, TexCoords).rgb;
    vec3 normal = texture(gNormal, TexCoords).rgb;
    vec4 Diffuse = texture(gAlbedo, TexCoords);
    float Specular = texture(gSpec, TexCoords).x;
    
    // then calculate lighting as usual
    vec3 lighting  = Diffuse.rgb * 0.1; // hard-coded ambient component
    vec3 viewDir  = normalize(viewPos - fragPos);

    vec3 sunColor = vec3(1.0, 0.95, 0.9);

    // diffuse
    vec3 lightDir = normalize(-sun);
    vec3 diffuse = max(dot(normal, lightDir), 0.0) * Diffuse.rgb * sunColor;
    // specular
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(normal, halfwayDir), 0.0), 16.0);
    vec3 specular = sunColor * spec * Specular;
    // attenuation
    float attenuation = 1.0 / 1.0;
    diffuse *= attenuation;
    specular *= attenuation;
    lighting += diffuse + specular;

    //fragColor = vec4(TexCoords,0.0,0.5);
    //fragColor = vec4(texture(gPosition, TexCoords).xy,0.0, 1.0);
    //fragColor = vec4(texture(gNormal, TexCoords).xyz, 1.0);
    //fragColor = texture(gAlbedo, TexCoords);
    fragColor = mix(vec4(lighting, Diffuse.w), Diffuse, bvec4(length(normal) == 0));
}