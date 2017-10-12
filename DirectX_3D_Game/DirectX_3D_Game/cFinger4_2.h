#pragma once
#include "cCube.h"

class cFinger4_2 : public cCube
{
public:
	cFinger4_2();
	~cFinger4_2();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

