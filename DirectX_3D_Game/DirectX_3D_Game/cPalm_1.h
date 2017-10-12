#pragma once
#include "cCube.h"

class cPalm_1 : public cCube
{
public:
	cPalm_1();
	~cPalm_1();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

