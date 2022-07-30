Texture2D mainTexture : register(t0);
Texture2D reflectionTexture : register(t1);

SamplerState samplerState : register(s0);

cbuffer MaterialPixelBuffer : register(b0)
{
    
    float3 ambientColor;
    float ambientStrength;
};

struct PS_INPUT
{
    float4 position : SV_Position;
    float2 tex : TEXCOORD;
    float4 reflectionPosition : OTHERTEXCOORD;
};

float4 main(PS_INPUT _input) : SV_TARGET
{
    float4 textureColor = mainTexture.Sample(samplerState, _input.tex);
    float2 reflectTexCoord;
    float4 reflectionColor;
    float4 color;
    
    reflectTexCoord.x = _input.reflectionPosition.x / _input.reflectionPosition.w / 2.0f + 0.5f;
    reflectTexCoord.y = -_input.reflectionPosition.y / _input.reflectionPosition.w / 2.0f + 0.5f;
    
    reflectionColor = reflectionTexture.Sample(samplerState, reflectTexCoord);
    
    color = lerp(textureColor, reflectionColor, 0.15f);
    
    return color;
}