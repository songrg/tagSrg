#pragma once

class cCube;
class cBullet;
class cRightBotArm;

class cCubeMan
{
private:
	cCube*			m_pRoot;
	cBullet*		m_pBullet;
	D3DXMATRIXA16	m_matWorld;
	D3DXVECTOR3		m_vPosition;
	D3DXVECTOR3		m_vDirection;

	cRightBotArm*	pRBArm;
	D3DXMATRIXA16 matR, matT;

	D3DXVECTOR3   m_vLeftEye;
	D3DXVECTOR3   m_vRightEye;

private:
	float		m_fRotY;
	bool		m_isAttack;
	bool		m_isFire;
	bool        m_isDie;
	bool		m_isRestart;
	bool        m_isWin;
	float       m_fSpeed;
	float       m_fPhi;

public:
	cCubeMan();
	~cCubeMan();

	void Setup();
	void Update();
	void Render();

	D3DXVECTOR3 getPos() { return m_vPosition; }
	void setDie(bool die) { m_isDie = die; }
	void setWin(bool win) { m_isWin = win; }

	cBullet* getBullet() { return m_pBullet; }
};

