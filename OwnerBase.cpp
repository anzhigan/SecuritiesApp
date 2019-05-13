#include "pch.h"
#include "ownerBase.h"
#include "MarketBase.h"
#include <iostream>
#include <vector>
using namespace std;

OwnerBase::OwnerBase()
{
}

OwnerBase::~OwnerBase()
{
}

void OwnerBase::insertOwnerSecuritiesBase(MarketBase mb)
{
	int number1, number2;
	cout << "1)Stocks 2)Bonds" << endl;
	cin >> number1;
	cout << "Number of Security in MarketBase: ";
	cin >> number2;
	if (number1 == 1) {
		ownerSecuritiesBase.push_back(mb.returnMarketStocksBase(number2));
	}
	else if (number1 == 2) {
		ownerSecuritiesBase.push_back(mb.returnMarketBondsBase(number2));
	}
	
}

void OwnerBase::showOwnerSecuritiesBase() 
{
	cout << endl << "My Base: " << endl;
	int i = 0;
	for (Securities s : ownerSecuritiesBase) {
		cout << i << " |name: ";
		s.showName();
		cout << " |price: " << s.getPrice() << "$";
		cout << endl;
		i++;
	}
}