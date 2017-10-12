#pragma once
#include "cCube.h"

class cPalm_2 : public cCube
{
public:
	cPalm_2();
	~cPalm_2();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

