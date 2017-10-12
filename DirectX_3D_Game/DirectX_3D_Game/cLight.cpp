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
	light.Ambient = *color * 0.4f;	// ���⼺�� ���� ���� ���� �ݻ���� ����
	light.Diffuse = *color;			// ���� ��ü�� ����� ��쿡  �ݻ��ϴ� ���� ����
	light.Specular = *color * 0.6f; // ���� ���� ���� �κ��� �ݻ������ ��¦�̰� �ϴ� ������ ����
	light.Direction = *direction;	// ���� ����

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
