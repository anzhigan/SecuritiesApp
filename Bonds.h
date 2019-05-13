#pragma once
#include "Securities.h"
class Bonds :
	public Securities
{
public:
	const string TYPE = "BOND";
	float factor = rand() % 1;
	Bonds();
	~Bonds();
};

