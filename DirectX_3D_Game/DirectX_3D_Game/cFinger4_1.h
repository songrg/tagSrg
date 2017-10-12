#pragma once
#include "cCube.h"

class cFinger4_1 : public cCube
{
public:
	cFinger4_1();
	~cFinger4_1();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

