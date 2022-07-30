Texture2D mainTexture: register(t0);
//Texture2D normalTexture : register(t1);

SamplerState samplerState : register(s0);

struct DIR_LIGHT
{
	float3 m_direction;
    float specularStrength;
	float3 m_color;
	float m_intensity;
};

cbuffer MaterialPixelBuffer : register(b0)
{
	DIR_LIGHT dirLight;
};

struct PS_INPUT
{
    float4 position : SV_POSITION;
    float3 normal : NORMAL;
    float2 uv : TEXCOORD;
    float3 color : COLOR;
    float3 camPosition : CAMERAPOSITION;
    float3 worldPosition : WORLDPOSITON;
};

float3 CalculateDirectionalLight(DIR_LIGHT _dirLight, float3 _normal, float3 _viewDir)
{
    float3 lightDirection = normalize(-_dirLight.m_direction);
    float diff = dot(_normal, lightDirection) * 1; //_dirLight.m_intensity;
    float3 halfDirection = normalize(-lightDirection - _viewDir);
    float spec = pow(saturate(dot(-halfDirection, _normal)), 128); // 8 = spec strength
    
    float3 ambient = _dirLight.m_color; // * intensity
    float3 diffuse = float3(1, 1, 1) * diff;
    float3 specular = float3(1, 1, 1) * spec;
    
    return ambient + diffuse + specular;
    return diffuse + specular;
    return specular;
    return diffuse;
    return ambient;
}

float4 main(PS_INPUT _input) : SV_TARGET
{
    //float3 normal = normalTexture.Sample(samplerState, _input.uv);
    //normal = (normal * 2) -1;
    //normal = normalize(normal);

    //return float4(normal, 1);
    
    float3 viewDirection = normalize(_input.camPosition - _input.worldPosition);
    float3 result = CalculateDirectionalLight(dirLight, _input.normal, viewDirection);
	float4  tex = mainTexture.Sample(samplerState, _input.uv);
    
    return float4(result, 1) * tex;
    return float4(result, 1);
  
}