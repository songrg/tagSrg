#include "stdafx.h"
#include "cCube.h"

cCube::cCube()
	: m_pTB(NULL)
	, m_pParentWorldTM(NULL)
	, m_vLocalPos(0.0f, 0.0f, 0.0f)
	, m_fRotateX(0.0f)
	, m_fRotateY(0.0f)
	, m_fRotateZ(0.0f)
	, m_fTransY(0.0f)
	, m_fTransZ(0.0f)
	, move(false)
{
	D3DXMatrixIdentity(&m_matWorldTM);
	D3DXMatrixIdentity(&m_matLocalTM);
}

cCube::~cCube()
{
	SAFE_RELEASE(m_pTB);
}

void cCube::AddChild(cCube * pChild)
{
	pChild->m_pParentWorldTM = &m_matWorldTM;

	m_vecChild.push_back(pChild);
}

void cCube::Destroy()
{
	for each (auto p in m_vecChild)
	{
		p->Destroy();
	}

	delete this;
}

void cCube::Setup(char* imageName, BODYKIND kind)
{
	ST_PC_TEXTURE_VERTEXT v;

	D3DXCreateTextureFromFile(g_pD3DDevice, imageName, &m_pTB);
	m_eBKind = kind;

	// 뒤
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.0f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.16f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.0f, 1.0f);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.0f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.16f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.16f, 1.0f);
	m_vecVertex.push_back(v);
	

	// 왼쪽
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.16f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.32f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.16, 1.0f);
	m_vecVertex.push_back(v);
	
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.16f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.32f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.32f, 1.0f);
	m_vecVertex.push_back(v);
	
	
	// 앞
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.48f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.48f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.32f, 1.0f);
	m_vecVertex.push_back(v);
	
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.48f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.32f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.32f, 0.0f);
	m_vecVertex.push_back(v);
	
	
	// 오른쪽
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.64f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.64f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.48f, 1.0f);
	m_vecVertex.push_back(v);
	
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.64f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.48f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.48f, 0.0f);
	m_vecVertex.push_back(v);
	
	
	// 위쪽
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.65f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.81f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.65f, 1.0f);
	m_vecVertex.push_back(v);
	
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.65f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.81f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.81f, 1.0f);
	m_vecVertex.push_back(v);
	
	
	// 아래
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.81f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.81f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(1.0f, 1.0f);
	m_vecVertex.push_back(v);
	
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.81f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(1.0f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(1.0f, 0.0f);
	m_vecVertex.push_back(v);
}

void cCube::SetupHand(char * imageName, HANDKIND kind)
{
	ST_PC_TEXTURE_VERTEXT v;

	D3DXCreateTextureFromFile(g_pD3DDevice, imageName, &m_pTB);
	m_eHkind = kind;

	// 뒤
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.0f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.17f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.0f, 1.0f);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.0f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.17f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.17f, 1.0f);
	m_vecVertex.push_back(v);


	// 왼쪽
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.17f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.34f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.17, 1.0f);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.17f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.34f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.34f, 1.0f);
	m_vecVertex.push_back(v);


	// 앞
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.51f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.51f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.34f, 1.0f);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.51f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.34f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.34f, 0.0f);
	m_vecVertex.push_back(v);


	// 오른쪽
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.68f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.68f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.51f, 1.0f);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.68f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.51f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.51f, 0.0f);
	m_vecVertex.push_back(v);


	// 위쪽
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.65f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.81f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.65f, 1.0f);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.65f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.81f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.81f, 1.0f);
	m_vecVertex.push_back(v);


	// 아래
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.81f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(0.81f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(1.0f, 1.0f);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(0.81f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
	v.T = D3DXVECTOR2(1.0f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
	v.T = D3DXVECTOR2(1.0f, 0.0f);
	m_vecVertex.push_back(v);

}

void cCube::Update(bool attack, bool fire, bool die, bool win, bool move)
{
	D3DXMatrixIdentity(&m_matWorldTM);
	D3DXMATRIXA16 matRX, matRY, matRZ, matT, matMT;
	D3DXMatrixIdentity(&matRX);
	D3DXMatrixIdentity(&matRY);
	D3DXMatrixIdentity(&matRZ);
	D3DXMatrixIdentity(&matT);
	D3DXMatrixIdentity(&matMT);
	///=================================================================

	switch (g_eSTATE->GetState())
	{
	case FINGHER1:
		m_fRotateZ += angleZ;
	
		if (m_eHkind == FINGER_1_1)
		{
			if (m_fRotateZ > D3DX_PI / 2)
			{
				m_fRotateZ = D3DX_PI / 2;
				angleZ *= -1;
			}
		}
		else
		{
			if (m_fRotateZ > D3DX_PI / 4)
			{
				m_fRotateZ = D3DX_PI / 4;
				angleZ *= -1;
			}
		}

		if (m_fRotateZ < 0.0f)
		{
			m_fRotateZ = 0.0f;
			angleZ *= -1;
		}
		break;

	case FINGHER2:	// 두번째 손가락만 움직이기 위해 지정
		if (m_eHkind != PALM_1 && (m_eHkind == FINGER_2 || m_eHkind == FINGER_2_1 || m_eHkind == FINGER_2_2))
		{
			m_fRotateX -= angleX;

			if (m_fRotateX < -D3DX_PI / 2)
			{
				m_fRotateX = -D3DX_PI / 2;
				angleX *= -1;
			}

			if (m_fRotateX > 0.0f)
			{
				m_fRotateX = 0.0f;
				angleX *= -1;
			}
		}
		break;

	case FINGHER3:
		if (m_eHkind != PALM_1 && (m_eHkind == FINGER_3 || m_eHkind == FINGER_3_1 || m_eHkind == FINGER_3_2))
		{
			m_fRotateX -= angleX;

			if (m_fRotateX < -D3DX_PI / 2)
			{
				m_fRotateX = -D3DX_PI / 2;
				angleX *= -1;
			}

			if (m_fRotateX > 0.0f)
			{
				m_fRotateX = 0.0f;
				angleX *= -1;
			}
		}
		break;

	case FINGHER4:
		if (m_eHkind != PALM_1 && (m_eHkind == FINGER_4 || m_eHkind == FINGER_4_1 || m_eHkind == FINGER_4_2))
		{
			m_fRotateX -= angleX;

			if (m_fRotateX < -D3DX_PI / 2)
			{
				m_fRotateX = -D3DX_PI / 2;
				angleX *= -1;
			}

			if (m_fRotateX > 0.0f)
			{
				m_fRotateX = 0.0f;
				angleX *= -1;
			}
		}
		break;

	case FINGHER5:
		if (m_eHkind != PALM_1 && (m_eHkind == FINGER_5 || m_eHkind == FINGER_5_1 || m_eHkind == FINGER_5_2))
		{
			m_fRotateX -= angleX;

			if (m_fRotateX < -D3DX_PI / 2)
			{
				m_fRotateX = -D3DX_PI / 2;
				angleX *= -1;
			}

			if (m_fRotateX > 0.0f)
			{
				m_fRotateX = 0.0f;
				angleX *= -1;
			}
		}
		break;

	case ALL:
		m_fRotateX -= angleX;

		if (m_fRotateX < -D3DX_PI / 2)
		{
			m_fRotateX = -D3DX_PI / 2;
			angleX *= -1;
		}

		if (m_fRotateX > 0.0f)
		{
			m_fRotateX = 0.0f;
			angleX *= -1;
		}
		break;
	}

	if (!win)
	{
		if (!die)
		{
			switch (g_eSTATE->GetState())
			{
			case STAND:
				if (m_eBKind == HEAD)
				{
					m_fRotateY += angleY;
					D3DXMatrixRotationY(&matRY, cosf(m_fRotateY));
				}

				// 숨 쉬기
				m_fTransY += moveY;

				if (m_fTransY > 0.2f)
				{
					m_fTransY = 0.2f;
					moveY *= -1;
				}

				if (m_fTransY < -0.2f)
				{
					m_fTransY = -0.2f;
					moveY *= -1;
				}

				// 팔, 다리 원 상태
				if (m_fRotateX > 0.0f)
				{
					m_fRotateX -= 0.08f;
				}

				if (m_fRotateX < 0.0f)
				{
					m_fRotateX += 0.08f;
				}

				if (m_fRotateX == 0.0f) m_fRotateX = 0.0f;

				if (angleX < 0.0f) angleX *= -1;

				if (bAngleX < 0.0f) bAngleX *= -1;

				break;

			case RUN:
				// 숨 쉬기
				m_fTransY += moveY;

				if (m_fTransY > 0.1f)
				{
					m_fTransY = 0.1f;
					moveY *= -1;
				}

				if (m_fTransY < -0.1f)
				{
					m_fTransY = -0.1f;
					moveY *= -1;
				}

				switch (m_eBKind)
				{
				case L_TOP_ARM: case L_BOT_ARM:
					if (attack)
					{
						m_fRotateX = D3DX_PI / 3;
						m_fRotateZ = angleZ;
					}
					else
					{
						m_fRotateZ = 0.0f;
						m_fRotateX -= angleX;

						if (m_fRotateX < -D3DX_PI / 2)
						{
							m_fRotateX = -D3DX_PI / 2;
							angleX *= -1;
						}

						if (m_fRotateX > D3DX_PI / 3)
						{
							m_fRotateX = D3DX_PI / 3;
							angleX *= -1;
						}
					}
					break;

				case R_TOP_ARM:
					if (attack)
					{
						m_fRotateX = -D3DX_PI / 2;

						if (fire)
						{
							move = true;
						}

						if (move)
						{
							m_fTransZ -= moveZ;

							if (m_fTransZ < -3.0f) move = false;
						}

						if (!move) m_fTransZ = 0.0f;
					}
					else
					{
						m_fRotateX += angleX;

						if (m_fRotateX < -D3DX_PI / 2)
						{
							m_fRotateX = -D3DX_PI / 2;
							angleX *= -1;
						}

						if (m_fRotateX > D3DX_PI / 3)
						{
							m_fRotateX = D3DX_PI / 3;
							angleX *= -1;
						}
					}
					break;

				case R_BOT_ARM:
					if (attack)
					{
						m_fRotateX = -D3DX_PI;
					}
					else
					{
						m_fRotateX += angleX;

						if (m_fRotateX < -D3DX_PI / 2)
						{
							m_fRotateX = -D3DX_PI / 2;
							angleX *= -1;
						}

						if (m_fRotateX > D3DX_PI / 3)
						{
							m_fRotateX = D3DX_PI / 3;
							angleX *= -1;
						}
					}
					break;

				case L_TOP_LEG:
					m_fRotateX += angleX;

					if (m_fRotateX < -D3DX_PI / 2)
					{
						m_fRotateX = -D3DX_PI / 2;
						angleX *= -1;
					}

					if (m_fRotateX > D3DX_PI / 3)
					{
						m_fRotateX = D3DX_PI / 3;
						angleX *= -1;
					}
					break;

				case R_TOP_LEG:
					m_fRotateX -= angleX;

					if (m_fRotateX < -D3DX_PI / 2)
					{
						m_fRotateX = -D3DX_PI / 2;
						angleX *= -1;
					}

					if (m_fRotateX > D3DX_PI / 3)
					{
						m_fRotateX = D3DX_PI / 3;
						angleX *= -1;
					}
					break;

				case R_BOT_LEG:
					m_fRotateX += angleX;

					if (m_fRotateX > D3DX_PI / 2)
					{
						m_fRotateX = D3DX_PI / 2;
						angleX *= -1;
					}

					if (m_fRotateX < -D3DX_PI / 7)
					{
						m_fRotateX = -D3DX_PI / 7;
						angleX *= -1;
					}
					break;

				case L_BOT_LEG:
					m_fRotateX -= angleX;

					if (m_fRotateX > D3DX_PI / 2)
					{
						m_fRotateX = D3DX_PI / 2;
						angleX *= -1;
					}

					if (m_fRotateX < -D3DX_PI / 7)
					{
						m_fRotateX = -D3DX_PI / 7;
						angleX *= -1;
					}
					break;
				}
				break;

			case BACK:
				switch (m_eBKind)
				{
				case L_TOP_ARM: case L_BOT_ARM: case R_TOP_LEG: case R_BOT_LEG:
					m_fRotateX += bAngleX;
					break;

				case R_TOP_ARM: case R_BOT_ARM: case L_TOP_LEG: case L_BOT_LEG:
					m_fRotateX -= bAngleX;
					break;
				}

				// 뒷 휘둘
				if (m_fRotateX > D3DX_PI / 7)
				{
					m_fRotateX = D3DX_PI / 7;
					bAngleX *= -1;
				}

				// 앞 휘둘
				if (m_fRotateX < -D3DX_PI / 7)
				{
					m_fRotateX = -D3DX_PI / 7;
					bAngleX *= -1;
				}
				break;
			}
		}
		else
		{
			if (m_vLocalPos.y >= -3.0f) m_vLocalPos.y -= 0.01f;

			switch (m_eBKind)
			{
			case HEAD:
				break;

			case BODY:
				break;
			case L_TOP_ARM: case L_BOT_ARM:
				m_vLocalPos.x -= 0.01f;
				break;
			case R_TOP_ARM: case R_BOT_ARM:
				m_vLocalPos.x += 0.01f;
				break;

			case L_TOP_LEG: case L_BOT_LEG:

				break;
			case R_TOP_LEG: case R_BOT_LEG:

				break;
			}
		}
	}
	//else if (win)
	//{
	//	switch (m_eBKind)
	//	{
	//	case HEAD:
	//		break;

	//	case BODY:

	//		break;

	//	case L_TOP_ARM:
	//		if (m_fRotateZ < -1.8f) m_fRotateZ -= angleZ;
	//		break;
	//	
	//	case L_BOT_ARM:

	//		break;
	//	case R_TOP_ARM: 
	//	
	//		break;
	//	case R_BOT_ARM:

	//		break;

	//	case L_TOP_LEG: case L_BOT_LEG:

	//		break;
	//	case R_TOP_LEG: case R_BOT_LEG:

	//		break;
	//	}
	//}


	///=================================================================
	//D3DXMatrixTranslation(&matMT, 0.0f, m_fTransY, m_fTransZ);
	D3DXMatrixRotationZ(&matRZ, m_fRotateZ);
	D3DXMatrixRotationX(&matRX, m_fRotateX);
	D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);
	
	//m_matLocalTM = matRZ * matRX * matRY * matT * matMT;

	m_matLocalTM = matRZ * matRX * matT;
	m_matWorldTM = m_matLocalTM;

	if (m_pParentWorldTM) m_matWorldTM *= (*m_pParentWorldTM);

	for each (auto p in m_vecChild)
	{
		p->Update(attack, fire, die, win, move);
	}
}

void cCube::Render()
{
	g_pD3DDevice->SetTexture(0, m_pTB);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
	g_pD3DDevice->SetFVF(ST_PC_TEXTURE_VERTEXT::FVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PC_TEXTURE_VERTEXT));

	for each (auto p in m_vecChild)
	{
		p->Render();
	}
}
