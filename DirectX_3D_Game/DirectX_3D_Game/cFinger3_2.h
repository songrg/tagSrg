#pragma once
#include "cCube.h"

class cFinger3_2 : public cCube
{
public:
	cFinger3_2();
	~cFinger3_2();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

