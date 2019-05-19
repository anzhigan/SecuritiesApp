#pragma once
#include "pch.h"
#include "Stocks.h"
#include "Bonds.h"
#include <string>
#include <vector>
#include <iostream>
#include <boost\variant.hpp>
using namespace std;

class MarketBase 
{
private:
	Stocks **marketStocksBase = new Stocks*[10];
	Bonds **marketBondsBase = new Bonds*[10];
public:
	MarketBase();
	~MarketBase();
	void defaultInsertMarketSecutitiesBase();
	//void insertYourselfMarketBase();
	Stocks* returnMarketStocksBase(int number);
	Bonds* returnMarketBondsBase(int number);
	void showMarketStockBase();
	void showMarketBondsBase();
	void gen_randomString(char *s, const int len);
	void updateMarketBase();
};

