#pragma once

class cCube;

class cHand
{
private:
	cCube*			m_pRoot;
	D3DXMATRIXA16	m_matWorld;
	D3DXVECTOR3		m_vPosition;
	D3DXVECTOR3		m_vDirection;
	D3DXMATRIXA16	matR, matT;
	float			m_fRotY;
	bool			m_fMove;
	D3DXMATRIXA16 matRX;
	float m_fRotX;

	D3DXVECTOR3		m_on;

public:
	cHand();
	~cHand();

	void Setup();
	void Update();
	void Render();
};

