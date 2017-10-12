#include "stdafx.h"
#include "cLeftBotArm.h"


cLeftBotArm::cLeftBotArm()
{
}


cLeftBotArm::~cLeftBotArm()
{
}

void cLeftBotArm::Setup(char * imageName, BODYKIND kind)
{
	cCube::Setup(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.5f, 1.0f, 0.5f);
	D3DXMatrixTranslation(&matT, -1.9f, -0.5f, 0.0f);
	
	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.y -= 2.5f;
}
