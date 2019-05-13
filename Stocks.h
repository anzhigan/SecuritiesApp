#pragma once
#include "Securities.h"
class Stocks :
	public Securities
{
public:
	const string TYPE = "STOCKS";
	float factor = rand() % 2;
	Stocks();
	~Stocks();
};

