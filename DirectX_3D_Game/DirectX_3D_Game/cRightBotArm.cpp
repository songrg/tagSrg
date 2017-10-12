#include "stdafx.h"
#include "cRightBotArm.h"


cRightBotArm::cRightBotArm()
	: m_vTrans(1.9f, -0.5f, 0.0f)
{
}


cRightBotArm::~cRightBotArm()
{
}

void cRightBotArm::Setup(char * imageName, BODYKIND kind)
{
	cCube::Setup(imageName, kind);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.5f, 1.0f, 0.5f);
	D3DXMatrixTranslation(&matT, m_vTrans.x, m_vTrans.y, m_vTrans.z);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.y -= 2.5f;
}
