#pragma once
#include "Securities.h"
class Stocks :
	public Securities
{
public:
	const string TYPE = "STOCKS";
	double factor = rand() % 2 + 0.7;
	Stocks();
	~Stocks();
};

