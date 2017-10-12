#include "stdafx.h"
#include "cPalm_3.h"


cPalm_3::cPalm_3()
{
}


cPalm_3::~cPalm_3()
{
}

void cPalm_3::SetupHand(char * imageName, HANDKIND kind)
{
	cCube::SetupHand(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld, matRotY;
	D3DXMatrixScaling(&matS, 2.0f, 1.0f, 5.0f);
	D3DXMatrixRotationY(&matRotY, -D3DX_PI / 7);
	D3DXMatrixTranslation(&matT, -3.0f, 9.0f, -4.0f);

	matWorld = matS * matRotY * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}
