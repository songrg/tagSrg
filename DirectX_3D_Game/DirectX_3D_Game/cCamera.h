#pragma once

#define g_Cam cCamera::GetInstance()

class cCamera
{
	SINGLETONE(cCamera)
private:
	D3DXVECTOR3 m_vEye;
	D3DXVECTOR3 m_vLookAt;
	D3DXVECTOR3 m_vUp;

	D3DXVECTOR3 m_vPlayerPos;
	D3DXMATRIXA16 m_vTest;

	POINT		m_ptPrevMouse;
	bool		m_isLButtonDown;
	float		m_fCameraDistance;
	D3DXVECTOR3 m_vCamRotAngle;
	bool		m_isRotCam;
	float       m_fAngleY;

private:
	D3DXMATRIXA16 matView;
	D3DXMATRIXA16 matProj;
	D3DVIEWPORT9 vp;
	bool		 m_isDie;
	bool         m_isWin;
	float		 moveCam;
	float        moveCamX;

public:
	void Setup();
	void Update();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void setLookAt(D3DXVECTOR3 playerPos) { m_vLookAt = playerPos; }
	void setEye(D3DXVECTOR3 playerPos) { m_vPlayerPos = playerPos; }
	void setCamDie(bool die) { m_isDie = die; }
	void setRotY(float angle) { m_fAngleY = angle; }
	void setCamWin(bool win) { m_isWin = win; }
};