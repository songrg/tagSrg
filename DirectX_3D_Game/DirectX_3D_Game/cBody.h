#pragma once
#include "cCube.h"

class cBody : public cCube
{
public:
	cBody();
	~cBody();

	virtual void Setup(char* imageName, BODYKIND kind) override;
};

