#include "stdafx.h"
#include "cRightTopArm.h"


cRightTopArm::cRightTopArm()
{
}


cRightTopArm::~cRightTopArm()
{
}

void cRightTopArm::Setup(char * imageName, BODYKIND kind)
{
	cCube::Setup(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld, matRotY;
	D3DXMatrixScaling(&matS, 0.5f, 1.0f, 0.5f);
	D3DXMatrixRotationY(&matRotY, 0.0f);
	D3DXMatrixTranslation(&matT, 1.9f, -1.0f, 0.0f);

	matWorld = matS * matRotY * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.y += 8.0f;
}
