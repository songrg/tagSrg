#pragma once
#include "cCube.h"

class cWrist : public cCube
{
public:
	cWrist();
	~cWrist();

	virtual void SetupHand(char* imageName, HANDKIND kind) override;
};

