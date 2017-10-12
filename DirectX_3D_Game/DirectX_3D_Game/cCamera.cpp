#include "stdafx.h"
#include "cCamera.h"


cCamera::cCamera()
	: m_vEye(0.0f, 8.0f, -35.0f)
	, m_vLookAt(0.0f, 0.0f, 0.0f)
	, m_vUp(0.0f, 1.0f, 0.0f)
	, m_fCameraDistance(50.0f)
	, m_isLButtonDown(false)
	, m_vCamRotAngle(0.0f, 0.0f, 0.0f)
	, m_vPlayerPos(0.0f, 0.0f, 0.0f)
	, m_isDie(false)
	, moveCam(0.0f)
	, m_fAngleY(0.0f)
	, m_isWin(false)
	, moveCamX(0.0f)
{
	m_ptPrevMouse.x = 0;
	m_ptPrevMouse.y = 0;
	D3DXMatrixIdentity(&m_vTest);
}

cCamera::~cCamera()
{
}

void cCamera::Setup()
{
	// ºä
	D3DXMatrixLookAtLH(&matView, &m_vEye, &m_vLookAt, &m_vUp);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

	// ÇÁ·ÎÁ§¼Ç
	RECT rc;
	GetClientRect(g_hWnd, &rc);
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 3.0f, rc.right / (float)rc.bottom, 1.0f, 1000.0f);
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);

	// ºä Æ÷Æ®
	vp.X = 0;
	vp.Y = 0;
	vp.Width = rc.right - rc.left;
	vp.Height = rc.bottom - rc.top;
	vp.MinZ = 0.0f;
	vp.MaxZ = 1.0f;
	g_pD3DDevice->SetViewport(&vp);
}

void cCamera::Update()
{
	//D3DXMATRIXA16 matR, matRX, matRY;
	//D3DXMatrixRotationX(&matRX, m_vCamRotAngle.x);
	//D3DXMatrixRotationY(&matRY, m_vCamRotAngle.y);
	//matR = matRX * matRY;
	//
	//m_vEye = D3DXVECTOR3(0, 10.0f, -m_fCameraDistance);
	//D3DXVec3TransformCoord(&m_vEye, &m_vEye, &matR);
	//
	//D3DXMatrixLookAtLH(&matView, &m_vEye, &m_vLookAt, &m_vUp);
	//g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

		//D3DXMatrixTranslation(&m_vTest, m_vPlayerPos.x, m_vPlayerPos.y, m_vPlayerPos.z);
		//m_vEye = D3DXVECTOR3(0.0f, 15.0f, -20.0f);
		//D3DXVec3TransformCoord(&m_vEye, &m_vEye, &m_vTest);


	if (!m_isWin)
	{
		if (!m_isDie)
		{
			D3DXMATRIXA16 matR, matRY;
			D3DXMatrixIdentity(&matRY);
			D3DXMatrixIdentity(&matR);
	
			D3DXMatrixTranslation(&m_vTest, m_vPlayerPos.x, m_vPlayerPos.y, m_vPlayerPos.z);
	
			if (KEY->isOnceKeyDown('E'))
			{
				if (!m_isRotCam) m_isRotCam = true;
				else if (m_isRotCam) m_isRotCam = false;
			}
	
			if (m_isRotCam) D3DXMatrixRotationY(&matRY, m_fAngleY);
	
			matR = matRY * m_vTest;
	
			m_vEye = D3DXVECTOR3(0.0f, 20.0f, -40.0f);
			D3DXVec3TransformCoord(&m_vEye, &m_vEye, &matR);
		}
		else
		{
			if (moveCam <= 20.0f) moveCam += 0.5f;
	
			m_vEye = D3DXVECTOR3(0.0f, 15.0f + moveCam, -20.0f);
			D3DXVec3TransformCoord(&m_vEye, &m_vEye, &m_vTest);
		}
	}
	else
	{
		if (moveCam <= 20.0f) moveCam += 0.05f;
		moveCamX += 0.2f;
		m_vEye = D3DXVECTOR3(moveCam, 15.0f + moveCamX, -20.0f);
		D3DXVec3TransformCoord(&m_vEye, &m_vEye, &m_vTest);
	}
	
	D3DXMatrixLookAtLH(&matView, &m_vEye, &m_vLookAt, &m_vUp);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);
}

void cCamera::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		m_ptPrevMouse.x = LOWORD(lParam);
		m_ptPrevMouse.y = HIWORD(lParam);
		m_isLButtonDown = true;
		break;

	case WM_LBUTTONUP:
		m_isLButtonDown = false;
		break;

	case WM_MOUSEMOVE:
		if (m_isLButtonDown)
		{
			POINT ptCurrMouse;
			ptCurrMouse.x = LOWORD(lParam);
			ptCurrMouse.y = HIWORD(lParam);

			float fDeltaX = (float)ptCurrMouse.x - m_ptPrevMouse.x;
			float fDeltaY = (float)ptCurrMouse.y - m_ptPrevMouse.y;

			m_vCamRotAngle.y += (fDeltaX / 100.f);
			m_vCamRotAngle.x += (fDeltaY / 100.f);
			if (m_vCamRotAngle.x < -D3DX_PI / 2.0f + 0.0001f)
				m_vCamRotAngle.x = -D3DX_PI / 2.0f + 0.0001f;
			if (m_vCamRotAngle.x > D3DX_PI / 2.0f - 0.0001f)
				m_vCamRotAngle.x = D3DX_PI / 2.0f - 0.0001f;
			m_ptPrevMouse = ptCurrMouse;
		}
		break;

	case WM_MOUSEWHEEL:
		m_fCameraDistance -= (GET_WHEEL_DELTA_WPARAM(wParam) / 30.f);
		if (m_fCameraDistance < 0.0001f)
			m_fCameraDistance = 0.0001f;
		break;
	}
}
