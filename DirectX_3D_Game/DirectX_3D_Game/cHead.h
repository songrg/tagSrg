#pragma once
#include "cCube.h"

class cHead : public cCube
{
public:
	cHead();
	~cHead();

	virtual void Setup(char* imageName, BODYKIND kind) override;
};

