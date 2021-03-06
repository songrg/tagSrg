#include "stdafx.h"
#include "cFinger2.h"


cFinger2::cFinger2()
{
}


cFinger2::~cFinger2()
{
}

void cFinger2::SetupHand(char * imageName, HANDKIND kind)
{
	cCube::SetupHand(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld, matRotY;
	D3DXMatrixScaling(&matS, 2.0f, 2.0f, 3.0f);
	D3DXMatrixRotationY(&matRotY, 0.0f);
	D3DXMatrixTranslation(&matT, 3.0f, -1.0f, 4.0f);

	matWorld = matS * matRotY * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.x += 4.0f;
	m_vLocalPos.y += 3.0f;
	m_vLocalPos.z += 2.0f;
}
