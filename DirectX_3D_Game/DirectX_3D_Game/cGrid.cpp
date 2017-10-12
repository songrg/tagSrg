#include "stdafx.h"
#include "cGrid.h"

cGrid::cGrid()
	: m_pVB(NULL)
	, m_pIB(NULL)
	, m_pTB(NULL)
{
	D3DXMatrixIdentity(&m_matWorld);
	D3DXCreateTextureFromFile(g_pD3DDevice, "field.png", &m_pTB);	// �ؽ�ó �̹��� �¾�
}

cGrid::~cGrid()
{
	SAFE_RELEASE(m_pVB);
	SAFE_RELEASE(m_pTB);
	SAFE_RELEASE(m_pIB);
}

void cGrid::Setup(int iRow, int iCol, float fSize)
{  
	m_iRow = iRow;
	m_iCol = iCol;
	m_fSize = fSize;

	m_iTotalVertex = (m_iRow + 1) * (m_iCol + 1);   // �� ���ؽ��� ���� = (���� ���� + 1) x (���� ���� + 1)
	m_iTotalIndex = m_iRow * m_iCol * 6;	        // �� �ε����� ���� = �� x �� x 6
	m_fStartPosX = -1.0f * m_iCol * m_fSize * 0.5f; // x��ǥ ���� ��ġ = -1.0f x �� x ũ��(����) x 0.5f(1/2)												
	m_fStartPosZ = m_iRow * m_fSize * 0.5f;			// z��ǥ ���� ��ġ = �� x ũ��(����) x 0.5f(1/2)

	m_pGridVertex = new ST_PC_TEXTURE_VERTEXT[m_iTotalVertex];	// �� ���ؽ��� ���� ��ŭ ���� �Ҵ�
	int vIndex = 0;	// ���ؽ� �迭�� �ε���

	for (int z = 0; z <= m_iRow; z++)		// �� = z��
	{
		for (int x = 0; x <= m_iCol; x++)   // �� = x��
		{
			// ���ؽ� ����
			m_pGridVertex[vIndex].p.x = m_fStartPosX + (x * m_fSize);
			m_pGridVertex[vIndex].p.y = 0.0f;
			m_pGridVertex[vIndex].p.z = m_fStartPosZ + -1.0f * (z * m_fSize);
			// �ؽ�ó ��ǥ ����
			m_pGridVertex[vIndex].T.x = x;
			m_pGridVertex[vIndex].T.y = z;
			// �ε��� ����
			vIndex++;
		}
	}

	m_pGridIndex = new WORD[m_iTotalIndex];		// �� �ε��� ���� ��ŭ ���� �Ҵ�
	int nIndex = 0;	// �ε��� �迭�� �ε���

	for (int z = 0; z < m_iRow; z++)
	{
		for (int x = 0; x < m_iCol; x++)
		{
			m_pGridIndex[nIndex++] = WORD(z * (m_iCol + 1) + x);
			m_pGridIndex[nIndex++] = WORD((z + 1) * (m_iCol + 1) + x + 1);
			m_pGridIndex[nIndex++] = WORD((z + 1) * (m_iCol + 1) + x);

			m_pGridIndex[nIndex++] = WORD(z * (m_iCol + 1) + x);
			m_pGridIndex[nIndex++] = WORD(z * (m_iCol + 1) + x + 1);
			m_pGridIndex[nIndex++] = WORD((z + 1) * (m_iCol + 1) + x + 1);
		}
	}

	// ���ؽ� ����
	g_pD3DDevice->CreateVertexBuffer(m_iTotalVertex * sizeof(ST_PC_TEXTURE_VERTEXT), 0, ST_PC_TEXTURE_VERTEXT::FVF, D3DPOOL_DEFAULT, &m_pVB, NULL);
	void* pVerTex;
	m_pVB->Lock(0, 0, &pVerTex, 0);
	memcpy(pVerTex, m_pGridVertex, m_iTotalVertex * sizeof(ST_PC_TEXTURE_VERTEXT));
	m_pVB->Unlock();

	// �ε��� ����
	g_pD3DDevice->CreateIndexBuffer(m_iTotalIndex * sizeof(WORD), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &m_pIB, NULL);
	void* pIndex;
	m_pIB->Lock(0, 0, &pIndex, 0);
	memcpy(pIndex, m_pGridIndex, m_iTotalIndex * sizeof(WORD));
	m_pIB->Unlock();

	// �߽� ��
	ST_PC_VERTEXT v;	
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(m_iTotalVertex, 0.0f, 0.0f);	m_vecAxis.push_back(v);
	v.p = D3DXVECTOR3(-m_iTotalVertex, 0.0f, 0.0f);	m_vecAxis.push_back(v);
	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(0.0f, m_iTotalVertex, 0.0f);	m_vecAxis.push_back(v);
	v.p = D3DXVECTOR3(0.0f, -m_iTotalVertex, 0.0f);	m_vecAxis.push_back(v);
	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(0.0f, 0.0f, m_iTotalVertex);	m_vecAxis.push_back(v);
	v.p = D3DXVECTOR3(0.0f, 0.0f,-m_iTotalVertex);	m_vecAxis.push_back(v);
}

void cGrid::Render(bool isShowWire)
{
	g_pD3DDevice->SetTexture(0, m_pTB);		
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetStreamSource(0, m_pVB, 0, sizeof(ST_PC_TEXTURE_VERTEXT));
	g_pD3DDevice->SetIndices(m_pIB);
	g_pD3DDevice->SetFVF(ST_PC_TEXTURE_VERTEXT::FVF);

	// �ε����� �׸���
	g_pD3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_iTotalVertex, 0, m_iTotalIndex / 3);

	// �� �׸���
	if (isShowWire)
	{
		g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecAxis.size() / 2, &m_vecAxis[0], sizeof(ST_PC_VERTEXT));
	}
}
