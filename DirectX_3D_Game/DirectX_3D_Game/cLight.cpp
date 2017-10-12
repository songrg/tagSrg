#include "stdafx.h"
#include "cLight.h"


cLight::cLight()
{
}


cLight::~cLight()
{
}

D3DLIGHT9 cLight::DirectionalLight(D3DXVECTOR3 * direction, D3DXCOLOR * color)
{
	D3DLIGHT9 light;
	ZeroMemory(&light, sizeof(D3DLIGHT9));

	light.Type = D3DLIGHT_DIRECTIONAL;
	light.Ambient = *color * 0.4f;	// 방향성이 없는 빛에 대한 반사색을 설정
	light.Diffuse = *color;			// 빛이 물체에 닿았을 경우에  반사하는 색상 설정
	light.Specular = *color * 0.6f; // 빛에 의한 밝은 부분의 반사색보다 반짝이게 하는 생삭을 설정
	light.Direction = *direction;	// 방향 설정

	return light;
}

D3DLIGHT9 cLight::PointLight(D3DXVECTOR3 * postion, D3DXCOLOR * color)
{
	D3DLIGHT9 light;
	ZeroMemory(&light, sizeof(D3DLIGHT9));

	light.Type = D3DLIGHT_POINT;
	light.Ambient = *color * 0.4f;
	light.Diffuse = *color;
	light.Specular = *color * 0.6f;
	light.Position = *postion;
	light.Range = 20.0f;

	return light;
}

D3DLIGHT9 cLight::SpotLight(D3DXVECTOR3 * postion, D3DXVECTOR3* postionTrans, D3DXVECTOR3 * direction, D3DXCOLOR * color, float phi)
{
	D3DLIGHT9 light;
	ZeroMemory(&light, sizeof(D3DLIGHT9));

	light.Type = D3DLIGHT_SPOT;
	light.Ambient = *color * 0.4f;
	light.Diffuse = *color;
	light.Specular = *color * 5.6f;
	light.Position = *postion + *postionTrans;
	light.Direction = *direction;
	light.Phi = phi;
	light.Theta = D3DX_PI / 8;
	light.Falloff = 1.0f;
	light.Range = 200.0f;

	return light;
}
