#pragma once
#include "cCube.h"

class cLeftBotArm : public cCube
{
public:
	cLeftBotArm();
	~cLeftBotArm();

	virtual void Setup(char* imageName, BODYKIND kind) override;
};

