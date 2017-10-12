#pragma once
#include "cCube.h"

class cRightTopLeg : public cCube
{
public:
	cRightTopLeg();
	~cRightTopLeg();

	virtual void Setup(char* imageName, BODYKIND kind) override;
};

