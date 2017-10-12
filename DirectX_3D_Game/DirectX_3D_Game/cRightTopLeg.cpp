#include "stdafx.h"
#include "cRightTopLeg.h"


cRightTopLeg::cRightTopLeg()
{
}


cRightTopLeg::~cRightTopLeg()
{
}

void cRightTopLeg::Setup(char * imageName, BODYKIND kind)
{
	cCube::Setup(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld, matRotY;
	D3DXMatrixScaling(&matS, 0.5f, 1.3f, 0.5f);
	D3DXMatrixRotationY(&matRotY, 0.0f);
	D3DXMatrixTranslation(&matT, 0.8f, -1.6f, 0.0f);

	matWorld = matS * matRotY * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.y += 5.0f;
}
