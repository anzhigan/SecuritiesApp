#include "pch.h"
#include <iostream>
#include "MarketBase.h"
#include "OwnerBase.h"
#include <boost\variant.hpp>
using namespace std;

void SW(int num, OwnerBase ob, MarketBase mb, bool scan) {
	switch (num)
	{
	case 1:
		ob.showOwnerSecuritiesBase();
		break;
	case 2:
		cout << endl << "Market Base: " << endl;
		mb.showMarketStockBase();
		mb.showMarketBondsBase();
		break;
	case 3:
		ob.insertOwnerSecuritiesBase(mb);
		ob.showOwnerSecuritiesBase();
		break;
	case 4:
		mb.insertYourselfMarketBase();
		break;
	case 5:
		mb.updateMarketBase();
	case 6:
		//scan = false;
		break;
	default:
		scan = true;
	}
}

int main() {
	MarketBase mb;
	OwnerBase ob;
	int num;
	
	cout << "Hello!" << endl
		<< "Please select button:" << endl
		<< "1 - show my Portfolio" << endl
		<< "2 - show Market" << endl
		<< "3 - insert Securities in Portfolio" << endl
		<< "4 - insert Yourself Securities in Market" << endl
		<< "5 - update price" << endl
		<< "6 - End" << endl;
	cin >> num;
	
	bool scan = true;
	while(scan)
	{
		SW(num, ob, mb, scan);
	};
	system("pause");
}

