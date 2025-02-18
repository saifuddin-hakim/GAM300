
#version 450

struct Material
{
    vec4 ambient;
    vec4 diffuse;
    vec4 specular;

    float shininess;
    float reflectivity;
    float opacity;
    uint diffuseID;
    
    uint specularID;
    uint normalID;
    uint emissiveID;
    uint opacityID;
 
};

layout(set = 1, binding = 4) uniform sampler2D texArraySampler[500];

layout(location = 0) in vec4 fragColor;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in vec3 fragPosWorld;
layout(location = 3) in vec3 fragNormalWorld; 
layout(location = 4) in flat uint id;
layout(location = 5) in vec4 clipspacepos;
layout(location = 6) flat in uint texID;


layout(location = 0) out vec4 outColor;
layout(location = 1) out uint outID;

struct PointLight{
    vec4 Position;
    vec4 Color;
    vec4 pad[2];
};


layout(set = 0, binding = 0) uniform GlobalUBO{
    mat4 proj;
    mat4 view;
    //mat4 InvView;
    vec4 ambientlightcolor;
    PointLight pointlights[50];
    int activelights;
    vec4 pad[15];    
}PL;


float constant=0.1;
float linear=0.01;
float quadratic=0.005;
void main() {
    if (abs(clipspacepos.x)>1.0||abs(clipspacepos.y)>1.0 || abs(clipspacepos.z)>1.0) discard;
    
    int textureID = int(texID);
    vec3 ambientlight = PL.ambientlightcolor.xyz * PL.ambientlightcolor.w;
    vec3 SurfaceNormal = normalize(fragNormalWorld);
    vec3 diffuselight = vec3(0.0,0.0,0.0);
    
    for (int i=0; i<PL.activelights; ++i)
    {
        PointLight currentlight = PL.pointlights[i];
        vec3 directiontolight = PL.pointlights[i].Position.xyz - fragPosWorld;
        
        float atten = 1.0/(constant + (length(directiontolight)* linear) + (length(directiontolight)*quadratic));
        directiontolight = normalize(directiontolight);
        
        float cosAngleIncidence = max(dot(SurfaceNormal, directiontolight),0.0);
        vec3 intensity = currentlight.Color.xyz * currentlight.Color.w * 5 * atten;
        
        diffuselight += intensity * cosAngleIncidence;
    }

    outID = id;
    
    vec4 texColor = texture(texArraySampler[textureID], fragTexCoord);

    //outColor = vec4((diffuselight*ambientlight)*fragColor,1.0);
    //outColor = texture(texSampler, fragTexCoord);

    outColor = texColor * vec4((diffuselight + ambientlight), 1.0);
}