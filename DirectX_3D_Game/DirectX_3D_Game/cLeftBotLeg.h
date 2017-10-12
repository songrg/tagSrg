#pragma once
#include "cCube.h"

class cLeftBotLeg : public cCube
{
public:
	cLeftBotLeg();
	~cLeftBotLeg();

	virtual void Setup(char* imageName, BODYKIND kind) override;
};

