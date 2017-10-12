#pragma once
#include "cCube.h"

class cLeftTopArm : public cCube
{
public:
	cLeftTopArm();
	~cLeftTopArm();

	virtual void Setup(char* imageName, BODYKIND kind) override;
};

