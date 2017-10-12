#pragma once
#include "cCube.h"

class cPalm_3 : public cCube
{
public:
	cPalm_3();
	~cPalm_3();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

