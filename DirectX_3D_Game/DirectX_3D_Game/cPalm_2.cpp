#include "stdafx.h"
#include "cPalm_2.h"


cPalm_2::cPalm_2()
{
}


cPalm_2::~cPalm_2()
{
}

void cPalm_2::SetupHand(char * imageName, HANDKIND kind)
{
	cCube::SetupHand(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld, matRotY;
	D3DXMatrixScaling(&matS, 2.0f, 1.0f, 4.0f);
	D3DXMatrixRotationY(&matRotY, D3DX_PI / 6);
	D3DXMatrixTranslation(&matT, 3.0f, 2.0f, -4.0f);

	matWorld = matS * matRotY * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.x += 1.0f;
	m_vLocalPos.y += 6.0f;
}
