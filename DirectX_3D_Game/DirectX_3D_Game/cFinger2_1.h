#pragma once
#include "cCube.h"

class cFinger2_1 : public cCube
{
public:
	cFinger2_1();
	~cFinger2_1();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

