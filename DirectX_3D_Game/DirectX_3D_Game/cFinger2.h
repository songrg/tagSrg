#pragma once
#include "cCube.h"

class cFinger2 : public cCube
{
public:
	cFinger2();
	~cFinger2();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

