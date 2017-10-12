#include "stdafx.h"
#include "cCreatCube.h"


cCreatCube::cCreatCube()
{
}


cCreatCube::~cCreatCube()
{
}

void cCreatCube::CreatCube(HUMANBODY bKind, D3DXVECTOR3 vecCenter, float width, float height, float angle)
{
	CUBE cube;
	ZeroMemory(&cube, sizeof(CUBE));

	D3DXMatrixIdentity(&cube.matWorld);
	D3DXMatrixIdentity(&cube.matRoY);
	D3DXMatrixIdentity(&cube.matTrans);

	cube.bodyKind = bKind;
	cube.pVB = NULL;
	cube.pIB = NULL;
	cube.vecCenter = D3DXVECTOR3(vecCenter.x, vecCenter.y, vecCenter.z);
	cube.vecDirection = D3DXVECTOR3(0.0f, 0.0f, 0.1f);
	cube.angle = angle;

	int r = rand() % 256;
	int g = rand() % 256;
	int b = rand() % 256;

	ST_PC_VERTEXT verTex[] = {
		{ D3DXVECTOR3(vecCenter.x - (width - 1.0f), vecCenter.y + (height - 1.0f), vecCenter.z - (width - 1.0f)), D3DCOLOR_XRGB(r, g, b) },
		{ D3DXVECTOR3(vecCenter.x + (width - 1.0f), vecCenter.y + (height - 1.0f), vecCenter.z - (width - 1.0f)), D3DCOLOR_XRGB(r, g, b) },
		{ D3DXVECTOR3(vecCenter.x + (width - 1.0f), vecCenter.y - (height - 1.0f), vecCenter.z - (width - 1.0f)), D3DCOLOR_XRGB(r, g, b) },
		{ D3DXVECTOR3(vecCenter.x - (width - 1.0f), vecCenter.y - (height - 1.0f), vecCenter.z - (width - 1.0f)), D3DCOLOR_XRGB(r, g, b) },

		{ D3DXVECTOR3(vecCenter.x - (width - 1.0f), vecCenter.y + (height - 1.0f), vecCenter.z + (width - 1.0f)), D3DCOLOR_XRGB(r, g, b) },
		{ D3DXVECTOR3(vecCenter.x + (width - 1.0f), vecCenter.y + (height - 1.0f), vecCenter.z + (width - 1.0f)), D3DCOLOR_XRGB(r, g, b) },
		{ D3DXVECTOR3(vecCenter.x + (width - 1.0f), vecCenter.y - (height - 1.0f), vecCenter.z + (width - 1.0f)), D3DCOLOR_XRGB(r, g, b) },
		{ D3DXVECTOR3(vecCenter.x - (width - 1.0f), vecCenter.y - (height - 1.0f), vecCenter.z + (width - 1.0f)), D3DCOLOR_XRGB(r, g, b) }
	};

	WORD index[] = {
		0, 2, 3,
		0, 1, 2,

		1, 6, 2,
		1, 5, 6,

		4, 1, 0,
		4, 5, 1,

		4, 7, 6, // ccw
		4, 6, 5,

		0, 3, 7,
		0, 7, 4,

		7, 3, 2,
		7, 2, 6
	};

	g_pD3DDevice->CreateVertexBuffer(sizeof(verTex), 0, ST_PC_VERTEXT::FVF, D3DPOOL_DEFAULT, &cube.pVB, NULL);
	void* pVerTex;
	cube.pVB->Lock(0, sizeof(verTex), &pVerTex, 0);
	memcpy(pVerTex, verTex, sizeof(verTex));
	cube.pVB->Unlock();

	g_pD3DDevice->CreateIndexBuffer(sizeof(index), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &cube.pIB, NULL);
	void* pIndex;
	cube.pIB->Lock(0, sizeof(index), &pIndex, 0);
	memcpy(pIndex, index, sizeof(index));
	cube.pIB->Unlock();

	vCube.push_back(cube);
}

void cCreatCube::Update()
{
	if (vCube.size() == 0) return;

	for (viCube = vCube.begin(); viCube != vCube.end(); ++viCube)
	{
		viCube->matWorld = viCube->matRoY * viCube->matTrans;
	}
}

void cCreatCube::Render()
{
	if (vCube.size() == 0) return;

	for (viCube = vCube.begin(); viCube != vCube.end(); ++viCube)
	{
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &viCube->matWorld);
		g_pD3DDevice->SetStreamSource(0, viCube->pVB, 0, sizeof(ST_PC_VERTEXT));
		g_pD3DDevice->SetIndices(viCube->pIB);
		g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);
		g_pD3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 6 * 2);
	}
}
