#pragma once
#include "cCube.h"

class cFinger4 : public cCube
{
public:
	cFinger4();
	~cFinger4();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

