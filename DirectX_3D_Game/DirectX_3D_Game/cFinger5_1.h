#pragma once
#include "cCube.h"

class cFinger5_1 : public cCube
{
public:
	cFinger5_1();
	~cFinger5_1();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

