#pragma once
#include "cCube.h"

class cFinger2_2 : public cCube
{
public:
	cFinger2_2();
	~cFinger2_2();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

