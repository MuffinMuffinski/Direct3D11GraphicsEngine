
cbuffer MaterialVertexBuffer
{
    float4x4 worldPosition;
    float4x4 wvp;
    float3 camPosition;
    float padding;
};

struct VS_INPUT
{
    float4 position : POSITION;
    float3 normal : NORMAL;
    float2 uv : TEXCOORD;
    float3 color : COLOR;
};

struct VS_OUTPUT
{
    float4 position : SV_POSITION;
    float3 normal : NORMAL;
    float2 uv : TEXCOORD;
    float3 color : COLOR;
    float3 camPosition : CAMERAPOSITION;
    float3 worldPosition : WORLDPOSITON;
};

VS_OUTPUT main(VS_INPUT _input)
{
    VS_OUTPUT output;
    _input.position.w = 1.0f;
    output.position = mul(_input.position, wvp);
    output.normal = mul(float4(_input.normal, 0.0f), worldPosition).xyz;
    //offset : + float2(x,y)
    //tiling : * float2(x,y)
    output.uv = _input.uv;
    output.color = _input.color;
    
    output.camPosition = camPosition;
    output.worldPosition = mul(_input.position, worldPosition);


    return output;
}