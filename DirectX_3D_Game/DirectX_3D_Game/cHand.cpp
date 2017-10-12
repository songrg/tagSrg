#include "stdafx.h"
#include "cHand.h"

#include "cWrist.h"

#include "cPalm_1.h"
#include "cPalm_2.h"
#include "cPalm_3.h"

#include "cFinger_1.h"
#include "cFinger_1_1.h"

#include "cFinger2.h"
#include "cFinger2_1.h"
#include "cFinger2_2.h"

#include "cFinger3.h"
#include "cFinger3_1.h"
#include "cFinger3_2.h"

#include "cFinger4.h"
#include "cFinger4_1.h"
#include "cFinger4_2.h"

#include "cFinger5.h"
#include "cFinger5_1.h"
#include "cFinger5_2.h"

cHand::cHand()
	: m_fMove(false)
	, m_pRoot(NULL)
	, m_fRotY(0.0f)
	, m_vPosition(0.0f, 0.0f, 0.0f)
{
	D3DXMatrixIdentity(&m_matWorld);
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);
}

cHand::~cHand()
{
	SAFE_DELETE(m_pRoot);
}

void cHand::Setup()
{

	/*
		손가락은 손바닥 1, 2, 3 의 자식들이다.
		손가락도 마디별로 부모 자식 간의 관계를 가진다.

		손가락1(엄지)의 부모는 손바닥2 이므로 	pPalm_2->AddChild(pFinger_1); 로 손바닥2의 자식은 손가락1(엄지)로 지정 한다.
		마찬가지로 손가락1의 자식은 손가락 1-1(마디 부분) 이다.	
		그러므로 pFinger_1->AddChild(pFinger_1_1); 로 하여 손가락1의 자식은 손가락1-1로 지정 한다.

		손가락2(집게 손가락)는 손바닥 1의 자식이다.
		pPalm_1->AddChild(pFinger2); 로 지정.

		손가락2의 자식 지정 : 	pFinger2->AddChild(pFinger2_1);
		손가락2-1의 자식지정:    	pFinger2_1->AddChild(pFinger2_2);
		

		집게손가락의 SetRotateX(0.01f);를 보면 전부다 SetRotateX(0.01f);로 해주었다.

		만약 전부 다 지정하지않고 손가락2만 SetRotateX(0.01f); 를 지정하고 cCube클래스에서 손가락2를 움직인다면
		손가락2, 손가락2-1, 손가락2-2 가 전부 동시에 동일하게 움직인다.

		하지만 손가락2-1에도 SetRotateX(0.01f); 손가락 2-2에도 SetRotateX(0.01f);를 지정하면

		cCube클래스에서 손가락2를 움직일경우 손가락2에는 0.01만 적용되지만 손가락2-1 에는 두배 손가락2-2에는 3배가 적용이된다.

		즉, 모두 같은 SetRotateX(0.01f);를 지정하면 자동으로 cCube내의 업데이트 안에 서 

		if (m_fRotateX < -D3DX_PI / 2)
		{
		m_fRotateX = -D3DX_PI / 2;
		angleX *= -1;
		}

		를 해주면 각 부위들은 모두 일정하게 앵글값이 증가하므로 손가락2를 기준으로 생각하고

		손가락2가 -90가 넘을때 까지 돌리고나서 다시 

		if (m_fRotateX > 0.0f)
		{
		m_fRotateX = 0.0f;
		angleX *= -1;
		}

		를 해주면 다른 부위들은 자기들만의 계산된 앵글값으로 돌아가면서 

		절묘하게 손가락2가 움직인대로 다시 손가락을 쥐웠다 펼 수 있다.
	*/
	// 손목
	cWrist* pWrist = new cWrist;
	pWrist->SetupHand("hand.png", WRIST);
	pWrist->SetParentWorldTM(&m_matWorld);
	m_pRoot = pWrist;

	// 손바닥 1	ㅡ
	cPalm_1* pPalm_1 = new cPalm_1;
	pPalm_1->SetupHand("hand.png", PALM_1);
	pPalm_1->SetRotateX(0.01f);
	m_pRoot->AddChild(pPalm_1);

	// 손바닥 2    |
	cPalm_2* pPalm_2 = new cPalm_2;
	pPalm_2->SetupHand("hand.png", PALM_2);
	pPalm_2->SetRotateZ(0.01f);
	m_pRoot->AddChild(pPalm_2);

	// 손바닥 3 |
	cPalm_3* pPalm_3 = new cPalm_3;
	pPalm_3->SetupHand("hand.png", PALM_3);
	m_pRoot->AddChild(pPalm_3);

	// 손가락 1
	cFinger_1* pFinger_1 = new cFinger_1;
	pFinger_1->SetupHand("hand.png", FINGER_1);
	pFinger_1->SetRotateZ(0.01f);
	pPalm_2->AddChild(pFinger_1);
	// 손가락 1-2
	cFinger_1_1* pFinger_1_1 = new cFinger_1_1;
	pFinger_1_1->SetupHand("hand.png", FINGER_1_1);
	pFinger_1_1->SetRotateZ(0.02f);
	pFinger_1->AddChild(pFinger_1_1);

	// 손가락 2
	cFinger2* pFinger2 = new cFinger2;
	pFinger2->SetupHand("hand.png", FINGER_2);
	pFinger2->SetRotateX(0.01f);
	pPalm_1->AddChild(pFinger2);						
	// 손가락 2-1
	cFinger2_1* pFinger2_1 = new cFinger2_1;
	pFinger2_1->SetupHand("hand.png", FINGER_2_1);
	pFinger2_1->SetRotateX(0.01f);
	pFinger2->AddChild(pFinger2_1);
	// 손가락 2-2
	cFinger2_2* pFinger2_2 = new cFinger2_2;
	pFinger2_2->SetupHand("hand.png", FINGER_2_2);
	pFinger2_2->SetRotateX(0.01f);
	pFinger2_1->AddChild(pFinger2_2);

	// 손가락 3
	cFinger3* pFinger3 = new cFinger3;
	pFinger3->SetupHand("hand.png", FINGER_3);
	pFinger3->SetRotateX(0.01f);
	pPalm_1->AddChild(pFinger3);
	// 손가락 3-1
	cFinger3_1* pFinger3_1 = new cFinger3_1;
	pFinger3_1->SetupHand("hand.png", FINGER_3_1);
	pFinger3_1->SetRotateX(0.01f);
	pFinger3->AddChild(pFinger3_1);
	// 손가락 3-2
	cFinger3_2* pFinger3_2 = new cFinger3_2;
	pFinger3_2->SetupHand("hand.png", FINGER_3_2);
	pFinger3_2->SetRotateX(0.01f);
	pFinger3_1->AddChild(pFinger3_2);

	// 손가락 4
	cFinger4* pFinger4 = new cFinger4;
	pFinger4->SetupHand("hand.png", FINGER_4);
	pFinger4->SetRotateX(0.01f);
	pPalm_1->AddChild(pFinger4);
	// 손가락 4-1
	cFinger4_1* pFinger4_1 = new cFinger4_1;
	pFinger4_1->SetupHand("hand.png", FINGER_4_1);
	pFinger4_1->SetRotateX(0.01f);
	pFinger4->AddChild(pFinger4_1);
	// 손가락 4-2
	cFinger4_2* pFinger4_2 = new cFinger4_2;
	pFinger4_2->SetupHand("hand.png", FINGER_4_2);
	pFinger4_2->SetRotateX(0.01f);
	pFinger4_1->AddChild(pFinger4_2);

	// 손가락 5
	cFinger5* pFinger5 = new cFinger5;
	pFinger5->SetupHand("hand.png", FINGER_5);
	pFinger5->SetRotateX(0.01f);
	pPalm_1->AddChild(pFinger5);
	// 손가락 5-1
	cFinger5_1* pFinger5_1 = new cFinger5_1;
	pFinger5_1->SetupHand("hand.png", FINGER_5_1);
	pFinger5_1->SetRotateX(0.01f);
	pFinger5->AddChild(pFinger5_1);
	// 손가락 5-2
	cFinger5_2* pFinger5_2 = new cFinger5_2;
	pFinger5_2->SetupHand("hand.png", FINGER_5_2);
	pFinger5_2->SetRotateX(0.01f);
	pFinger5_1->AddChild(pFinger5_2);

	m_on = D3DXVECTOR3(0.0f, 1.0f, 3.0f);
	m_vPosition.y = 10.0f;
}

void cHand::Update()
{
	//m_fMove = false;
	g_eSTATE->SetState(NONE);

	if (KEY->isStayKeyDown(VK_F6)) g_eSTATE->SetState(ALL);

	if (KEY->isStayKeyDown(VK_F5)) g_eSTATE->SetState(FINGHER1);
	
	if (KEY->isStayKeyDown(VK_F4)) g_eSTATE->SetState(FINGHER2);

	if (KEY->isStayKeyDown(VK_F3)) g_eSTATE->SetState(FINGHER3);

	if (KEY->isStayKeyDown(VK_F2)) g_eSTATE->SetState(FINGHER4);

	if (KEY->isStayKeyDown(VK_F1)) g_eSTATE->SetState(FINGHER5);

	if (GetKeyState('J') & 0x8000)
	{
		m_fRotY -= 0.05f;
	}

	if (GetKeyState('L') & 0x8000)
	{
		m_fRotY += 0.05f;
	}

	if (GetKeyState('I') & 0x8000)
	{
		m_vPosition = m_vPosition + (m_vDirection * 0.2);
	}

	if (GetKeyState('K') & 0x8000)
	{
		m_vPosition = m_vPosition - (m_vDirection * 0.2);
	}

	if (KEY->isStayKeyDown('P'))
	{
		m_fRotX -= 0.05f;
	}

	D3DXMatrixRotationX(&matRX, m_fRotX);
	D3DXMatrixRotationY(&matR, m_fRotY);
	m_vDirection = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_matWorld = matRX * matR * matT;
	 
	m_pRoot->Update(false, false, false, false, m_fMove);
}

void cHand::Render()
{
	// light
	D3DMATERIAL9 mtrl;
	ZeroMemory(&mtrl, sizeof(D3DMATERIAL9));
	mtrl.Diffuse.r = mtrl.Ambient.r = 1.0f;
	mtrl.Diffuse.g = mtrl.Ambient.g = 1.0f;
	mtrl.Diffuse.b = mtrl.Ambient.b = 1.0f;
	mtrl.Diffuse.a = mtrl.Ambient.a = 1.0f;
	g_pD3DDevice->SetMaterial(&mtrl);

	D3DLIGHT9 lightLeft;
	//D3DLIGHT9 lightRight;
	//D3DXVECTOR3 pos(0.0f, 10.0f, 0.0f);
	//D3DXVECTOR3 dir(0.0f, 0.0f, 0.0f);
	D3DXCOLOR c;
	c.r = 1.0f;
	c.g = 1.0f;
	c.b = 1.0f;

	lightLeft = g_Light->SpotLight(&m_vPosition, &m_on, &-m_vDirection, &c, D3DX_PI / 6);
	//lightRight = g_Light->SpotLight(&m_vPosition, &m_vRightEye, &m_vDirection, &c);

	g_pD3DDevice->SetLight(2, &lightLeft);
	//g_pD3DDevice->SetLight(1, &lightRight);

	g_pD3DDevice->LightEnable(2, TRUE);
	//g_pD3DDevice->LightEnable(1, TRUE);
	m_pRoot->Render();
}
