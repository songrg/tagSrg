#pragma once
#include "cCube.h"

class cFinger5 : public cCube
{
public:
	cFinger5();
	~cFinger5();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

