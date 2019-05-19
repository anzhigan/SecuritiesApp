#pragma once
#include "Securities.h"
class Bonds :
	public Securities
{
public:
	const string TYPE = "BOND";
	double factor = rand() % 2 + 0.8;
	Bonds();
	~Bonds();
};

