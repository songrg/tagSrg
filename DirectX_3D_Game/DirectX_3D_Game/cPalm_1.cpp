#include "stdafx.h"
#include "cPalm_1.h"


cPalm_1::cPalm_1()
{
}


cPalm_1::~cPalm_1()
{
}

void cPalm_1::SetupHand(char * imageName, HANDKIND kind)
{
	cCube::SetupHand(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld, matRotY;
	D3DXMatrixScaling(&matS, 6.0f, 1.0f, 2.0f);
	D3DXMatrixRotationY(&matRotY, 0.0f);
	D3DXMatrixTranslation(&matT, 0.0f, 2.0f, 4.0f);

	matWorld = matS * matRotY * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.y += 6.0f;
}
