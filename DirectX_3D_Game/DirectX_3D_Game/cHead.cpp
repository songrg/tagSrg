#include "stdafx.h"
#include "cHead.h"


cHead::cHead()
{
}

cHead::~cHead()
{
}

void cHead::Setup(char* imageName, BODYKIND kind)
{
	cCube::Setup(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld, matRotY;
	D3DXMatrixScaling(&matS, 1.2f, 1.3f, 1.2f);
	D3DXMatrixRotationY(&matRotY, 0.0f);
	D3DXMatrixTranslation(&matT, 0.0f, 9.0f, 0.0f);

	matWorld = matS * matRotY * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}
