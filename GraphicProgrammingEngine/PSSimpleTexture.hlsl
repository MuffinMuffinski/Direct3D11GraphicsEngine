Texture2D mainTexture : register(t0);

SamplerState samplerState : register(s0);

cbuffer MaterialPixelBuffer : register(b0)
{
    float3 ambientColor;
    float ambientStrength;
};

struct PS_INPUT
{
    float4 position : SV_POSITION;
    float3 normal : NORMAL;
    float2 uv : TEXCOORD;
    float3 color : COLOR;
};

float4 main(PS_INPUT _input) : SV_TARGET
{
    float4 tex = mainTexture.Sample(samplerState, _input.uv);
    return tex;
    return tex * float4(ambientColor, 0.8f) ;
}