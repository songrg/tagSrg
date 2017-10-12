#include "stdafx.h"
#include "cFinger_1.h"


cFinger_1::cFinger_1()
{
}


cFinger_1::~cFinger_1()
{
}

void cFinger_1::SetupHand(char * imageName, HANDKIND kind)
{
	cCube::SetupHand(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld, matRotY;
	D3DXMatrixScaling(&matS, 2.0f, 2.0f, 3.0f);
	D3DXMatrixRotationY(&matRotY, D3DX_PI / 2);
	D3DXMatrixTranslation(&matT, 3.0f, 2.0f, -4.0f);

	matWorld = matS * matRotY * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.x += 7.0f;
	m_vLocalPos.y += 0.0f;
}
