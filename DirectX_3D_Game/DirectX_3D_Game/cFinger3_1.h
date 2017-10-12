#pragma once
#include "cCube.h"

class cFinger3_1 : public cCube
{
public:
	cFinger3_1();
	~cFinger3_1();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

