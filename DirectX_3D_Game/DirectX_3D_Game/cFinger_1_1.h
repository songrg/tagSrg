#pragma once
#include "cCube.h"

class cFinger_1_1 : public cCube
{
public:
	cFinger_1_1();
	~cFinger_1_1();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

