cbuffer MaterialVertexBuffer
{
    float4x4 worldPosition;
    float4x4 wvp;
    float4x4 worldMatrix;
};

cbuffer ReflectionBuffer
{
    matrix reflectionMatrix;
};

struct VS_INPUT
{
    float4 position : SV_Position;
    float2 tex : TEXCOORD;
};

struct VS_OUTPUT
{
    float4 position : SV_Position;
    float2 tex : TEXCOORD;
    float4 reflectionPosition : OTHERTEXCOORD;
};

VS_OUTPUT main(VS_INPUT _input)
{
    VS_OUTPUT output;
    matrix reflectProjectWorld;
    
    _input.position.w = 1.0f;
    output.position = mul(_input.position, worldMatrix);
    output.position = mul(output.position, wvp);
    output.tex = _input.tex;
    
    reflectProjectWorld = mul(reflectionMatrix, wvp); // Projection und view Matrix getrennt 
    reflectProjectWorld = mul(worldMatrix, reflectProjectWorld);
    output.reflectionPosition = mul(_input.position, reflectProjectWorld);
    
    return output;
}
