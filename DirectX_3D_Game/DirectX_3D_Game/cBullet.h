#pragma once

typedef struct tagBullet
{
	std::vector<ST_PC_TEXTURE_VERTEXT>	vecVertex;
	LPDIRECT3DTEXTURE9	pTB;
	D3DXMATRIXA16		matWorld;
	D3DXMATRIXA16		matS;
	D3DXMATRIXA16		matRY;
	D3DXMATRIXA16		matTrans;
	D3DXVECTOR3			vecCenter;
	D3DXVECTOR3			vecDirection;
	D3DXVECTOR3			vecFireStrat;
	D3DXVECTOR3			vecScal;
	float				angleY;
	float				speed;

} BULLET;

class cBullet
{
private:
	std::vector<BULLET>				m_vBullet;
	std::vector<BULLET>::iterator   m_viBullet;

public:
	cBullet();
	~cBullet();

	void BulletFire(char* imageName, D3DXVECTOR3 scal, D3DXVECTOR3 center, D3DXVECTOR3 direction, float angleY, float speed);
	void BulletMove();
	void BulletRender();
	void BulletDistroy(int arryNum);
	float getDistans(D3DXVECTOR3 vec1, D3DXVECTOR3 vec2);

	std::vector<BULLET> getBullet() { return m_vBullet; }
};

