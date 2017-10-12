#pragma once

enum HUMANBODY
{
	HEAD, BODY, LEFTARM, RIGHTARM, LEFTLEG, RIGHTLEG, DEFAULT
};

typedef struct tagCube
{
	HUMANBODY bodyKind;
	LPDIRECT3DVERTEXBUFFER9 pVB;
	LPDIRECT3DINDEXBUFFER9 pIB;
	D3DXMATRIX matWorld;
	D3DXMATRIX matRoY;
	D3DXMATRIX matTrans;
	D3DXVECTOR3 vecCenter;
	D3DXVECTOR3 vecDirection;

	float angle;
} CUBE;

class cCreatCube
{
private:
	std::vector<CUBE> vCube;
	std::vector<CUBE>::iterator viCube;

public:
	cCreatCube();
	~cCreatCube();

	void CreatCube(HUMANBODY bKind, D3DXVECTOR3 vecCenter, float width, float height, float angle);
	void Update();
	void Render();
};

