#include "stdafx.h"
#include "cFinger3.h"


cFinger3::cFinger3()
{
}


cFinger3::~cFinger3()
{
}

void cFinger3::SetupHand(char * imageName, HANDKIND kind)
{
	cCube::SetupHand(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld, matRotY;
	D3DXMatrixScaling(&matS, 2.2f, 2.2f, 3.2f);
	D3DXMatrixRotationY(&matRotY, 0.0f);
	D3DXMatrixTranslation(&matT, -1.5f, -1.0f, 4.0f);

	matWorld = matS * matRotY * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.x += 4.0f;
	m_vLocalPos.y += 3.0f;
	m_vLocalPos.z += 2.0f;
}
