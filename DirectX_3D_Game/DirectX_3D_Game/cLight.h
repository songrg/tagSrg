#pragma once

#define g_Light cLight::GetInstance()

class cLight
{
	SINGLETONE(cLight);

public:
	D3DLIGHT9 DirectionalLight(D3DXVECTOR3* direction, D3DXCOLOR* color);
	D3DLIGHT9 PointLight(D3DXVECTOR3* postion, D3DXCOLOR* color);
	D3DLIGHT9 SpotLight(D3DXVECTOR3* postion, D3DXVECTOR3* postionTrans, D3DXVECTOR3* direction, D3DXCOLOR* color, float phi);
};

