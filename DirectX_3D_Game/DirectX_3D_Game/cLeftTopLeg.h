#pragma once
#include "cCube.h"

class cLeftTopLeg : public cCube
{
public:
	cLeftTopLeg();
	~cLeftTopLeg();

	virtual void Setup(char* imageName, BODYKIND kind) override;
};

