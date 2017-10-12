#pragma once
#include "cCube.h"

class cRightTopArm : public cCube
{
public:
	cRightTopArm();
	~cRightTopArm();

	virtual void Setup(char* imageName, BODYKIND kind) override;
};

