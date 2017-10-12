#pragma once
class cGrid
{
private:
	int   m_iRow;			// �� ����
	int   m_iCol;			// �� ����
	int   m_iTotalVertex;	// �� ���ؽ� ����
	int	  m_iTotalIndex;	// �� �ε��� ����
	float m_fSize;			// �׸��� ����
	float m_fStartPosX;		// ���ؽ� ���� x��ǥ ���� ����
	float m_fStartPosZ;		// ���ؽ� ���� z��ǥ ���� ����

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVB;		// ���ؽ� ����
	LPDIRECT3DINDEXBUFFER9  m_pIB;		// �ε��� ����
	LPDIRECT3DTEXTURE9		m_pTB;		// �ؽ�ó�� ������ ������
	D3DXMATRIXA16			m_matWorld; // �׸��� ����

	ST_PC_TEXTURE_VERTEXT*  m_pGridVertex; // �׸��� ���ؽ� ������
	WORD*					m_pGridIndex;  // �׸��� �ε��� ������

	std::vector<ST_PC_VERTEXT> m_vecAxis;	   // �߽� �� ���ؽ�

public:
	cGrid();
	~cGrid();

	// �׸��� �ʱ�ȭ
	void Setup(int iRow, int iCol, float fSize);
	// �׸��� ����
	void Render(bool isShowWire);
};

