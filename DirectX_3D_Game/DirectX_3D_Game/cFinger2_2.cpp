#include "stdafx.h"
#include "cFinger2_2.h"


cFinger2_2::cFinger2_2()
{
}


cFinger2_2::~cFinger2_2()
{
}

void cFinger2_2::SetupHand(char * imageName, HANDKIND kind)
{
	cCube::SetupHand(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld, matRotY;
	D3DXMatrixScaling(&matS, 1.0f, 1.0f, 2.0f);
	D3DXMatrixRotationY(&matRotY, 0.0f);
	D3DXMatrixTranslation(&matT, -5.0f, -1.0f, 3.0f);

	matWorld = matS * matRotY * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.x += 4.0f;
	m_vLocalPos.y += 0.0f;
	m_vLocalPos.z += 6.0f;
}
