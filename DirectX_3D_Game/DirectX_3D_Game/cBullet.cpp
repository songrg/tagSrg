#include "stdafx.h"
#include "cBullet.h"


cBullet::cBullet()
{
}


cBullet::~cBullet()
{
}

void cBullet::BulletFire(char* imageName, D3DXVECTOR3 scal, D3DXVECTOR3 center, D3DXVECTOR3 direction, float angleY, float speed)
{
	BULLET bullet;
	ZeroMemory(&bullet, sizeof(BULLET));
	
	D3DXCreateTextureFromFile(g_pD3DDevice, imageName, &bullet.pTB);
	D3DXMatrixIdentity(&bullet.matWorld);
	D3DXMatrixIdentity(&bullet.matTrans);
	D3DXMatrixIdentity(&bullet.matRY);
	D3DXMatrixIdentity(&bullet.matS);

	bullet.vecScal = scal;
	bullet.vecCenter = center;
	bullet.vecDirection = direction;
	bullet.angleY = angleY;
	bullet.vecFireStrat = center;
	bullet.speed = speed;

	ST_PC_TEXTURE_VERTEXT v;
	// 뒤
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.0f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.16f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.0f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.0f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.16f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.16f, 1.0f);
	bullet.vecVertex.push_back(v);
	// 왼쪽
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.16f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.32f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.16, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.16f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.32f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.32f, 1.0f);
	bullet.vecVertex.push_back(v);
	// 앞
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.48f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.48f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.32f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.48f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.32f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.32f, 0.0f);
	bullet.vecVertex.push_back(v);
	// 오른쪽
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.64f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.64f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.48f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.64f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.48f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.48f, 0.0f);
	bullet.vecVertex.push_back(v);
	// 위쪽
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.65f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.81f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.65f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.65f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.81f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.81f, 1.0f);
	bullet.vecVertex.push_back(v);
	// 아래
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.81f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.81f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(1.0f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.81f, 0.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(1.0f, 1.0f);
	bullet.vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(1.0f, 0.0f);
	bullet.vecVertex.push_back(v);

	m_vBullet.push_back(bullet);
}

void cBullet::BulletMove()
{
	if (m_vBullet.size() == 0) return;

	for (m_viBullet = m_vBullet.begin(); m_viBullet != m_vBullet.end();)
	{
		m_viBullet->vecCenter.x += (m_viBullet->vecDirection.x * m_viBullet->speed);
		m_viBullet->vecCenter.z += (m_viBullet->vecDirection.z * m_viBullet->speed);

		D3DXMatrixScaling(&m_viBullet->matS, m_viBullet->vecScal.x, m_viBullet->vecScal.y, m_viBullet->vecScal.z);
		D3DXMatrixRotationY(&m_viBullet->matRY, m_viBullet->angleY);
		D3DXMatrixTranslation(&m_viBullet->matTrans, m_viBullet->vecCenter.x, m_viBullet->vecCenter.y + 8.5f, m_viBullet->vecCenter.z);

		m_viBullet->matWorld = m_viBullet->matS * m_viBullet->matRY * m_viBullet->matTrans;

		// 자동 삭제
		if (getDistans(m_viBullet->vecFireStrat, m_viBullet->vecCenter) >= 700.0f)
		{
			m_viBullet = m_vBullet.erase(m_viBullet);
		}
		else
		{
			++m_viBullet;
		}
	}
}

void cBullet::BulletRender()
{
	if (m_vBullet.size() == 0) return;

	for (m_viBullet = m_vBullet.begin(); m_viBullet != m_vBullet.end(); ++m_viBullet)
	{
		g_pD3DDevice->SetTexture(0, m_viBullet->pTB);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_viBullet->matWorld);
		g_pD3DDevice->SetFVF(ST_PC_TEXTURE_VERTEXT::FVF);

		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
			m_viBullet->vecVertex.size() / 3,
			&m_viBullet->vecVertex[0],
			sizeof(ST_PC_TEXTURE_VERTEXT));
	}
}

void cBullet::BulletDistroy(int arryNum)
{
	m_vBullet.erase(m_vBullet.begin() + arryNum);
}

float cBullet::getDistans(D3DXVECTOR3 vec1, D3DXVECTOR3 vec2)
{
	float x = vec2.x - vec1.x;
	float z = vec2.z - vec1.z;

	return sqrtf(x * x + z * z);
}
