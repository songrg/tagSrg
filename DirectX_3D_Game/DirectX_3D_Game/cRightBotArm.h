#pragma once
#include "cCube.h"

class cRightBotArm : public cCube
{
private:
	D3DXVECTOR3 m_vTrans;

public:
	cRightBotArm();
	~cRightBotArm();

	virtual void Setup(char* imageName, BODYKIND kind) override;

	D3DXVECTOR3 getTrans() { return m_vTrans; }
};

