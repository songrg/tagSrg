#include "stdafx.h"
#include "cFinger5_2.h"


cFinger5_2::cFinger5_2()
{
}


cFinger5_2::~cFinger5_2()
{
}

void cFinger5_2::SetupHand(char * imageName, HANDKIND kind)
{
	cCube::SetupHand(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld, matRotY;
	D3DXMatrixScaling(&matS, 0.8f, 0.8f, 1.8f);
	D3DXMatrixRotationY(&matRotY, 0.0f);
	D3DXMatrixTranslation(&matT, -18.0f, -1.0f, 1.0f);

	matWorld = matS * matRotY * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.x += 4.0f;
	m_vLocalPos.y += 0.0f;
	m_vLocalPos.z += 6.0f;
}
