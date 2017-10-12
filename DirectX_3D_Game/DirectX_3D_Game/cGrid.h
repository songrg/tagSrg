#pragma once
class cGrid
{
private:
	int   m_iRow;			// 행 개수
	int   m_iCol;			// 열 개수
	int   m_iTotalVertex;	// 총 버텍스 개수
	int	  m_iTotalIndex;	// 총 인덱스 개수
	float m_fSize;			// 그리드 간격
	float m_fStartPosX;		// 버텍스 시작 x좌표 시작 지점
	float m_fStartPosZ;		// 버텍스 시작 z좌표 시작 지점

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVB;		// 버텍스 버퍼
	LPDIRECT3DINDEXBUFFER9  m_pIB;		// 인덱스 버퍼
	LPDIRECT3DTEXTURE9		m_pTB;		// 텍스처를 지정할 포인터
	D3DXMATRIXA16			m_matWorld; // 그리드 월드

	ST_PC_TEXTURE_VERTEXT*  m_pGridVertex; // 그리드 버텍스 포인터
	WORD*					m_pGridIndex;  // 그리드 인덱스 포인터

	std::vector<ST_PC_VERTEXT> m_vecAxis;	   // 중심 축 버텍스

public:
	cGrid();
	~cGrid();

	// 그리드 초기화
	void Setup(int iRow, int iCol, float fSize);
	// 그리드 렌더
	void Render(bool isShowWire);
};

