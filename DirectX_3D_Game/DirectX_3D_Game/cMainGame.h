#pragma once

class cGrid;
class cCubeMan;
class cBullet;
class cHand;
class cWall;
class cCreatCube;

typedef struct tagLightCube
{
	D3DXVECTOR3 vPos;
	bool fLightOn;
} LIGHTCUBE;

class cMainGame
{
private:
	bool m_isWireframe;
	bool m_isFire;
	int  m_iWinCount;
	int  m_iFireCount;
	DWORD m_dTimeCount;
	bool m_isLightOn;

	LIGHTCUBE m_sCube[3];

private:
	cGrid*    m_pGrid;
	cCubeMan* m_pCubeMan;
	cBullet*  m_pBullet;
	cWall*    m_pWall;
	cHand*    m_pHand;
	cCreatCube* m_pCreatCube;

private:
	D3DXVECTOR3 m_vCubeLightPos;

public:
	cMainGame();
	~cMainGame();

	void Setup();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	float cubeCollision(D3DXVECTOR3 vec1, D3DXVECTOR3 vec2);
	int getFromIntTo(int fromNum, int toNum);
	float getFromFloatTo(float fromNum, float toNum);
};

