#pragma once
#include "cCube.h"

class cFinger5_2 : public cCube
{
public:
	cFinger5_2();
	~cFinger5_2();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

