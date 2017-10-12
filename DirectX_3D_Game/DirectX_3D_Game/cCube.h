#pragma once

enum BODYKIND
{
	HEAD, BODY,
	L_TOP_ARM, L_BOT_ARM,
	R_TOP_ARM, R_BOT_ARM,
	L_TOP_LEG, L_BOT_LEG,
	R_TOP_LEG, R_BOT_LEG,
	R_GUN
};

enum HANDKIND
{
	WRIST, PALM_1, PALM_2, PALM_3,
	FINGER_1, FINGER_1_1,
	FINGER_2, FINGER_2_1, FINGER_2_2,
	FINGER_3, FINGER_3_1, FINGER_3_2,
	FINGER_4, FINGER_4_1, FINGER_4_2,
	FINGER_5, FINGER_5_1, FINGER_5_2
};

class cCube
{
protected:
	std::vector<ST_PC_TEXTURE_VERTEXT>	m_vecVertex;
	LPDIRECT3DTEXTURE9			m_pTB;
	D3DXMATRIXA16				m_matWorldTM;
	D3DXMATRIXA16				m_matLocalTM;
	D3DXVECTOR3					m_vLocalPos;
	std::vector<cCube*>			m_vecChild;
	BODYKIND					m_eBKind;
	HANDKIND					m_eHkind;

protected:
	float		m_fRotateX;
	float		m_fRotateY;
	float		m_fRotateZ;

	float		m_fTransY;
	float		m_fTransZ;

protected:
	SYNTHSIZE(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM)
	SYNTHSIZE(float, angleX, RotateX)
	SYNTHSIZE(float, angleY, RotateY)
	SYNTHSIZE(float, angleZ, RotateZ)

	SYNTHSIZE(float, bAngleX, bRotateX)

	SYNTHSIZE(float, moveY, TransY)
	SYNTHSIZE(float, moveZ, TransZ)

private:
	bool move;
	bool aniStart;

public:
	cCube();
	virtual ~cCube();

	void AddChild(cCube* pChild);
	void Destroy();

	virtual void Setup(char* imageName, BODYKIND kind);
	virtual void SetupHand(char* imageName, HANDKIND kind);

	void Update(bool attack, bool fire, bool die, bool win, bool move);
	void Render();
};

