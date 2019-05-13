#pragma once
#include "pch.h"
#include "Securities.h"
#include "MarketBase.h"
#include <string>
#include <vector>

class OwnerBase
{
private:
	vector<Securities> ownerSecuritiesBase;
public:
	OwnerBase();
	~OwnerBase();
	void insertOwnerSecuritiesBase(MarketBase mb);
	void showOwnerSecuritiesBase();
};

