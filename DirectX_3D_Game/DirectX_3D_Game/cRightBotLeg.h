#pragma once
#include "cCube.h"

class cRightBotLeg : public cCube
{
public:
	cRightBotLeg();
	~cRightBotLeg();

	virtual void Setup(char* imageName, BODYKIND kind) override;
};

