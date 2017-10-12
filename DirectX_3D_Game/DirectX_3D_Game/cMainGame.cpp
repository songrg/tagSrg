#include "stdafx.h"
#include "cMainGame.h"
// 추가 해더
#include "cGrid.h"
#include "cCubeMan.h"
#include "cBullet.h"
#include "cWall.h"
#include "cHand.h"
#include "cCreatCube.h"

cMainGame::cMainGame()
	: m_isWireframe(false)
	, m_isFire(false)
	, m_iFireCount(0)
	, m_pGrid(NULL)
	, m_pCubeMan(NULL)
	, m_iWinCount(0)
	, m_pHand(NULL)
	, m_isLightOn(false)
{
}

cMainGame::~cMainGame()
{
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pCubeMan);
	SAFE_DELETE(m_pBullet);
	SAFE_DELETE(m_pHand);
	SAFE_DELETE(m_pWall);
	SAFE_DELETE(m_pCreatCube);
	g_pDeviceManager->Destroy();
}

void cMainGame::Setup()
{
	g_Cam->Setup();

	m_pGrid = new cGrid;
	m_pGrid->Setup(200, 200, 3.0f);

	m_pHand = new cHand;
	m_pHand->Setup();

	m_pCubeMan = new cCubeMan;
	m_pCubeMan->Setup();

	m_pWall = new cWall;
	m_pWall->Setup(200, 200, 1.0f);

	m_vCubeLightPos = D3DXVECTOR3(-50.0f, 2.0f, 10.0f);

	m_pCreatCube = new cCreatCube;
	m_pCreatCube->CreatCube(DEFAULT, m_vCubeLightPos, 4.0f, 4.0f, 0.0f);

	//m_pBullet = new cBullet;
	//m_pBullet->BulletFire("eBullet.png", D3DXVECTOR3(0.0f, 0.0f, 500.0f), D3DXVECTOR3(0.0f, 0.0f, -1.0f), 0.0f);
}

void cMainGame::Update()
{
	if (GetAsyncKeyState('Z') & 0x0001)	// 와이어 보여주기
	{
		if (!m_isWireframe) m_isWireframe = true;
		else m_isWireframe = false;
	}

	g_Cam->Update();

	m_pHand->Update();
	m_pCreatCube->Update();
	if (m_pCubeMan) m_pCubeMan->Update();

	if (cubeCollision(m_vCubeLightPos, m_pCubeMan->getPos()) < 20) m_isLightOn = true;
	if (cubeCollision(m_vCubeLightPos, m_pCubeMan->getPos()) > 20) m_isLightOn = false;


	//if (m_pBullet)  m_pBullet->BulletMove();

	//m_dTimeCount = GetTickCount();

	//if (m_dTimeCount % 1000 == 0)
	//{
	//	int x = getFromIntTo(-300.0f, 300.0f);
	//	int x1 = getFromIntTo(-300.0f, 300.0f);
	//	float speed = getFromFloatTo(0.5f, 4.5f);
	//	float scal = getFromFloatTo(1.0f, 2.0f);
	//	float angle = getFromFloatTo(-3.0f, 3.14f);

	//	m_pBullet->BulletFire("eBullet.png", D3DXVECTOR3(scal, scal, scal), D3DXVECTOR3(x, 0.0f, 400.0f), D3DXVECTOR3(0.0f, 0.0f, -1.0f), angle, speed);
	//	//m_pBullet->BulletFire("eBullet.png", D3DXVECTOR3(scal, scal, scal), D3DXVECTOR3(x1, 0.0f, 400.0f), D3DXVECTOR3(0.0f, 0.0f, -1.0f), angle, speed);
	//}

	//if (m_dTimeCount % 2000 == 0)
	//{
	//	int z = getFromIntTo(-300.0f, 300.0f);
	//	int z1 = getFromIntTo(-300.0f, 300.0f);
	//	float speed = getFromFloatTo(0.5f, 4.5f);
	//	float scal = getFromFloatTo(1.0f, 2.0f);
	//	float angle = getFromFloatTo(-3.0f, 3.14f);

	//	m_pBullet->BulletFire("eBullet.png", D3DXVECTOR3(scal, scal, scal), D3DXVECTOR3(-400.0f, 0.0f, z), D3DXVECTOR3(1.0f, 0.0f, 0.0f), angle, speed);
	//	//m_pBullet->BulletFire("eBullet.png", D3DXVECTOR3(scal, scal, scal), D3DXVECTOR3(-400.0f, 0.0f, z1), D3DXVECTOR3(1.0f, 0.0f, 0.0f), angle, speed);
	//}

	//if (m_dTimeCount % 3000 == 0)
	//{
	//	int x = getFromIntTo(-300.0f, 300.0f);
	//	int x1 = getFromIntTo(-300.0f, 300.0f);
	//	float speed = getFromFloatTo(0.5f, 4.5f);
	//	float scal = getFromFloatTo(1.0f, 2.0f);
	//	float angle = getFromFloatTo(-3.0f, 3.14f);

	//	m_pBullet->BulletFire("eBullet.png", D3DXVECTOR3(scal, scal, scal), D3DXVECTOR3(x, 0.0f, -400.0f), D3DXVECTOR3(0.0f, 0.0f, 1.0f), angle, speed);
	//	//m_pBullet->BulletFire("eBullet.png", D3DXVECTOR3(scal, scal, scal), D3DXVECTOR3(x1, 0.0f, -400.0f), D3DXVECTOR3(0.0f, 0.0f, 1.0f), angle, speed);
	//}

	//if (m_dTimeCount % 4000 == 0)
	//{
	//	int z = getFromIntTo(-300.0f, 300.0f);
	//	int z1 = getFromIntTo(-300.0f, 300.0f);
	//	float speed = getFromFloatTo(0.5f, 4.5f);
	//	float scal = getFromFloatTo(1.0f, 2.0f);
	//	float angle = getFromFloatTo(-3.0f, 3.14f);

	//	m_pBullet->BulletFire("eBullet.png", D3DXVECTOR3(scal, scal, scal), D3DXVECTOR3(0.0f, 0.0f, -z), D3DXVECTOR3(-1.0f, 0.0f, 0.0f), angle, speed);
	//	//m_pBullet->BulletFire("eBullet.png", D3DXVECTOR3(scal, scal, scal), D3DXVECTOR3(0.0f, 0.0f, -z1), D3DXVECTOR3(-1.0f, 0.0f, 0.0f), angle, speed);
	//}

	//if (m_dTimeCount % 5000 == 0)
	//{
	//	int z = getFromIntTo(-300.0f, 300.0f);
	//	float speed = getFromFloatTo(0.5f, 5.0f);
	//	float scal = getFromFloatTo(1.0f, 2.0f);
	//	float angle = getFromFloatTo(-3.0f, 3.14f);

	//	float dX = getFromFloatTo(0.1f, D3DX_PI / 2);
	//	float dZ = getFromFloatTo(-0.1f, D3DX_PI / 2);

	//	//m_pBullet->BulletFire("eBullet.png", D3DXVECTOR3(scal, scal, scal), D3DXVECTOR3(-500.0f, 0.0f, z), D3DXVECTOR3(dX, 0.0f, dZ), angle, speed);
	//}

	//if (m_dTimeCount % 6000 == 0)
	//{
	//	int z = getFromIntTo(-300.0f, 300.0f);
	//	float speed = getFromFloatTo(0.5f, 5.0f);
	//	float scal = getFromFloatTo(1.0f, 2.0f);
	//	float angle = getFromFloatTo(-3.0f, 3.14f);

	//	float dX = getFromFloatTo(0.1f, D3DX_PI / 2);
	//	float dZ = getFromFloatTo(-0.1f, D3DX_PI / 2);

	//	//m_pBullet->BulletFire("eBullet.png", D3DXVECTOR3(scal, scal, scal), D3DXVECTOR3(-500.0f, 0.0f, z), D3DXVECTOR3(dX, 0.0f, dZ), angle, speed);
	//}

	//if (m_dTimeCount % 7000 == 0)
	//{
	//	int z = getFromIntTo(-300.0f, 300.0f);
	//	float speed = getFromFloatTo(0.5f, 5.0f);
	//	float scal = getFromFloatTo(1.0f, 2.0f);
	//	float angle = getFromFloatTo(-3.0f, 3.14f);

	//	float dX = getFromFloatTo(0.1f, D3DX_PI / 2);
	//	float dZ = getFromFloatTo(-0.1f, D3DX_PI / 2);

	//	//m_pBullet->BulletFire("eBullet.png", D3DXVECTOR3(scal, scal, scal), D3DXVECTOR3(-500.0f, 0.0f, z), D3DXVECTOR3(dX, 0.0f, dZ), angle, speed);
	//}

	//for (int i = 0; i < m_pBullet->getBullet().size(); i++)
	//{
	//	if (cubeCollision(m_pCubeMan->getPos(), m_pBullet->getBullet()[i].vecCenter) <= 5.0f)
	//	{
	//		m_pBullet->BulletDistroy(i);
	//		m_pCubeMan->setDie(true);
	//		break;
	//	}

	//	for (int j = 0; j < m_pCubeMan->getBullet()->getBullet().size(); j++)
	//	{
	//		if (cubeCollision(m_pCubeMan->getBullet()->getBullet()[j].vecCenter, m_pBullet->getBullet()[i].vecCenter) <= 8.0f)
	//		{
	//			m_pCubeMan->getBullet()->BulletDistroy(j);
	//			m_pBullet->BulletDistroy(i);
	//			m_iWinCount++;
	//			break;
	//		}
	//	}
	//}

	//if (m_iWinCount >= 5)
	//{
	//	m_pCubeMan->setWin(true);
	//	g_Cam->setCamWin(true);
	//}
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	g_pD3DDevice->BeginScene();
	///======================================================
	if (m_isWireframe) g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	else g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	m_pCreatCube->Render();
	if (m_pGrid) m_pGrid->Render(m_isWireframe);
	m_pWall->Render(m_isWireframe);
	m_pHand->Render();
	//if (m_pBullet)  m_pBullet->BulletRender();
	if (m_pCubeMan) m_pCubeMan->Render();


		// light
		D3DMATERIAL9 mtrl;
		ZeroMemory(&mtrl, sizeof(D3DMATERIAL9));
		mtrl.Diffuse.r = mtrl.Ambient.r = 1.0f;
		mtrl.Diffuse.g = mtrl.Ambient.g = 1.0f;
		mtrl.Diffuse.b = mtrl.Ambient.b = 1.0f;
		mtrl.Diffuse.a = mtrl.Ambient.a = 1.0f;
		g_pD3DDevice->SetMaterial(&mtrl);

		D3DLIGHT9 light;
		D3DXCOLOR c;
		c.r = 1.0f;
		c.g = 1.0f;
		c.b = 1.0f;

		light = g_Light->PointLight(&m_vCubeLightPos, &c);

		g_pD3DDevice->SetLight(1, &light);
		g_pD3DDevice->LightEnable(1, m_isLightOn);
	

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	g_pD3DDevice->SetRenderState(D3DRS_AMBIENT, 0x00202020);

	///======================================================
	g_pD3DDevice->EndScene();
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//if (g_Cam) g_Cam->WndProc(hWnd, message, wParam, lParam);
}

float cMainGame::cubeCollision(D3DXVECTOR3 vec1, D3DXVECTOR3 vec2)
{
	float x = vec2.x - vec1.x;
	float z = vec2.z - vec1.z;

	return sqrtf(x * x + z * z);
}

int cMainGame::getFromIntTo(int fromNum, int toNum)
{
	return rand() % (toNum - fromNum + 1) + fromNum;
}

float cMainGame::getFromFloatTo(float fromNum, float toNum)
{
	float rnd = (float)rand() / (float)RAND_MAX;
	return (rnd * (toNum - fromNum) + fromNum);
}
