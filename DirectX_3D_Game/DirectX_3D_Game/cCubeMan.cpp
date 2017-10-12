#include "stdafx.h"
#include "cCubeMan.h"

#include "cHead.h"
#include "cBody.h"
#include "cLeftTopArm.h"
#include "cLeftBotArm.h"
#include "cRightTopArm.h"
#include "cRightBotArm.h"
#include "cLeftTopLeg.h"
#include "cLeftBotLeg.h"
#include "cRightTopLeg.h"
#include "cRightBotLeg.h"

#include "cBullet.h"

cCubeMan::cCubeMan()
	: m_pRoot(NULL)
	, m_pBullet(NULL)
	, m_fRotY(0.0f)
	, m_vPosition(0.0f, 0.0f, 0.0f)
	, m_vDirection(0.0f, 0.0f, 1.0f)
	, m_isAttack(false)
	, m_isFire(false)
	, m_isDie(false)
	, m_isRestart(false)
	, m_fSpeed(0.5f)
	, m_isWin(false)
	, m_fPhi(D3DX_PI / 6)
{
}

cCubeMan::~cCubeMan()
{
	SAFE_DELETE(m_pRoot);
	SAFE_DELETE(m_pBullet);
}

void cCubeMan::Setup()
{
	// ¸öÅë
	cBody* pBody = new cBody;
	pBody->Setup("body.png", BODY);
	pBody->SetParentWorldTM(&m_matWorld);
	pBody->SetTransY(0.01f);
	m_pRoot = pBody;

	// ¸Ó¸®
	cHead* pHead = new cHead;
	pHead->Setup("head.png", HEAD);
	m_pRoot->AddChild(pHead);
	pHead->SetRotateY(0.02f);
	pHead->SetRotateX(0.1f);
	pHead->SetTransY(0.01f);

	// ¿ÞÂÊ À­ ÆÈ
	cLeftTopArm* pLTArm = new cLeftTopArm;
	pLTArm->Setup("leftTopArm.png", L_TOP_ARM);
	m_pRoot->AddChild(pLTArm);
	pLTArm->SetRotateX(0.13f);
	pLTArm->SetbRotateX(0.02f);
	pLTArm->SetTransY(0.01f);
	pLTArm->SetRotateZ(-0.2f);
	// ¿ÞÂÊ ¾Æ·§ ÆÈ
	cLeftBotArm* pLBArm = new cLeftBotArm;
	pLBArm->Setup("leftBotArm.png", L_BOT_ARM);
	pLTArm->AddChild(pLBArm);
	pLBArm->SetRotateX(0.13f);
	pLBArm->SetbRotateX(0.02f);

	// ¿À¸¥ÂÊ À­ ÆÈ
	cRightTopArm* pRTArm = new cRightTopArm;
	pRTArm->Setup("rightTopArm.png", R_TOP_ARM);
	m_pRoot->AddChild(pRTArm);
	pRTArm->SetRotateX(0.13f);
	pRTArm->SetbRotateX(0.02f);
	pRTArm->SetTransY(0.01f);
	pRTArm->SetTransZ(0.3f);
	// ¿À¸¥ÂÊ ¾Æ·§ ÆÈ
	pRBArm = new cRightBotArm;
	pRBArm->Setup("rightBotArm.png", R_BOT_ARM);
	pRTArm->AddChild(pRBArm);
	pRBArm->SetRotateX(0.13f);
	pRBArm->SetbRotateX(0.02f);

	// ¿ÞÂÊ À­ ´Ù¸®
	cLeftTopLeg* pLTLeg = new cLeftTopLeg;
	pLTLeg->Setup("leftTopLeg.png", L_TOP_LEG);
	m_pRoot->AddChild(pLTLeg);
	pLTLeg->SetRotateX(0.14f);
	pLTLeg->SetbRotateX(0.01f);
	pLTLeg->SetTransY(-0.01f);
	// ¿ÞÂÊ ¾Æ·§ ´Ù¸®
	cLeftBotLeg* pLBLeg = new cLeftBotLeg;
	pLBLeg->Setup("leftBotLeg.png", L_BOT_LEG);
	pLTLeg->AddChild(pLBLeg);
	pLBLeg->SetRotateX(0.15f);
	pLBLeg->SetbRotateX(0.01f);

	// ¿À¸¥ÂÊ À­ ´Ù¸®
	cRightTopLeg* pRTLeg = new cRightTopLeg;
	pRTLeg->Setup("rightTopLeg.png", R_TOP_LEG);
	m_pRoot->AddChild(pRTLeg);
	pRTLeg->SetRotateX(0.14f);
	pRTLeg->SetbRotateX(0.01f);
	pRTLeg->SetTransY(-0.01f);
	// ¿À¸¥ÂÊ ¾Æ·§ ´Ù¸®
	cRightBotLeg* pRBLeg = new cRightBotLeg;
	pRBLeg->Setup("rightBotLeg.png", R_BOT_LEG);
	pRTLeg->AddChild(pRBLeg);
	pRBLeg->SetRotateX(0.15f);
	pRBLeg->SetbRotateX(0.01f);

	m_pBullet = new cBullet;

	m_vLeftEye = D3DXVECTOR3(0.0f, 9.0f, 0.0f);
	m_vRightEye = D3DXVECTOR3(5.0f, 9.0f, 5.0f);
}

void cCubeMan::Update()
{
	g_eSTATE->SetState(STAND);
	g_Cam->setCamDie(m_isDie);
	m_isAttack = false;
	m_isFire = false;

	//if (m_fRotY >= D3DX_PI) m_fRotY = 0.0f;
 
	if (GetKeyState('A') & 0x8000)
	{
		m_fRotY -= 0.05f;
		g_Cam->setRotY(m_fRotY);
	}

	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.05f;
		g_Cam->setRotY(m_fRotY);
	}

	if (GetKeyState('W') & 0x8000)
	{
		if (!m_isAttack) m_fSpeed = 0.8f;
		else m_fSpeed = 0.3f;
		m_vPosition = m_vPosition + (m_vDirection * m_fSpeed);
		g_Cam->setLookAt(m_vPosition);
		g_Cam->setEye(m_vPosition);
		g_eSTATE->SetState(RUN);
	}

	if (GetKeyState('S') & 0x8000)
	{
		m_fSpeed = 0.3f;
		m_vPosition = m_vPosition - (m_vDirection * m_fSpeed);
		g_Cam->setLookAt(m_vPosition);
		g_Cam->setEye(m_vPosition);
		g_eSTATE->SetState(BACK);
	}

	if (GetKeyState(VK_LBUTTON) & 0x8000)
	{
		m_isAttack = true;
	}

	if (KEY->isOnceKeyDown('Q') && m_isAttack)
	{
		m_isFire = true;
		D3DXVECTOR3 scal;
		scal.x = 1.5f;
		scal.y = 1.5f;
		scal.z = 1.5f;

		m_pBullet->BulletFire("bullet.png", scal, m_vPosition + pRBArm->getTrans(), m_vDirection, m_fRotY, 3.0f);
	}
	
	D3DXMatrixRotationY(&matR, m_fRotY);
	m_vDirection = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_matWorld = matR * matT;

	if (m_pRoot) m_pRoot->Update(m_isAttack, m_isFire, m_isDie, m_isWin, false);
	if (m_pBullet) m_pBullet->BulletMove();
}

void cCubeMan::Render()
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

	lightLeft = g_Light->SpotLight(&m_vPosition, &m_vLeftEye, &m_vDirection, &c, m_fPhi);
	//lightRight = g_Light->SpotLight(&m_vPosition, &m_vRightEye, &m_vDirection, &c);

	g_pD3DDevice->SetLight(0, &lightLeft);
	//g_pD3DDevice->SetLight(1, &lightRight);

	g_pD3DDevice->LightEnable(0, TRUE);
	//g_pD3DDevice->LightEnable(1, TRUE);

	//g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	//g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);
	//g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	//g_pD3DDevice->SetRenderState(D3DRS_AMBIENT, 0x00202020);

	if (m_pRoot) m_pRoot->Render();
	if (m_pBullet) m_pBullet->BulletRender();
}
