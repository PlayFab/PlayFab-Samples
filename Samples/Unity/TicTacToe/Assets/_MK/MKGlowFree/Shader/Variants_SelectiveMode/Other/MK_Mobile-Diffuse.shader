// Unity built-in shader source. Copyright (c) 2016 Unity Technologies. MIT license (see license.txt)

// Simplified Diffuse shader. Differences from regular Diffuse one:
// - no Main Color
// - fully supports only 1 directional light. Other lights can affect it, but it will be per-vertex/SH.

Shader "MK/Glow/Selective/Mobile/Diffuse" {
Properties {
	_MainTex ("Base (RGB)", 2D) = "white" {}
	_Color ("Main Color", Color) = (1,1,1,1)

	_MKGlowColor ("Glow Color", Color) = (1,1,1,1)
	_MKGlowPower ("Glow Power", Range(0.0,2.5)) = 1.0
	_MKGlowTex ("Glow Texture", 2D) = "black" {}
	_MKGlowTexColor ("Glow Texture Color", Color) = (1,1,1,1)
	_MKGlowTexStrength ("Glow Texture Strength ", Range(0.0,10.0)) = 1.0
}
SubShader {
	Tags { "RenderType"="MKGlow" }
	LOD 150

CGPROGRAM
#pragma surface surf Lambert noforwardadd

sampler2D _MainTex;
fixed4 _Color;

sampler2D _MKGlowTex;
half _MKGlowTexStrength;
fixed4 _MKGlowTexColor;

struct Input {
	float2 uv_MainTex;
	float2 uv_MKGlowTex;
};

void surf (Input IN, inout SurfaceOutput o) {
	fixed4 c = tex2D(_MainTex, IN.uv_MainTex)*_Color;
	fixed3 d = tex2D(_MKGlowTex, IN.uv_MKGlowTex) * _MKGlowTexColor;
	c.rgb += (d.rgb * _MKGlowTexStrength);
	o.Albedo = c.rgb;
	o.Alpha = c.a;
}
ENDCG
}

Fallback "Mobile/VertexLit"
}
