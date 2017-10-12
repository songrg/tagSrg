#pragma once
#include "cCube.h"

class cFinger3 : public cCube
{
public:
	cFinger3();
	~cFinger3();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

