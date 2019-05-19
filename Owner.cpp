#include "pch.h"
#include "Owner.h"


void Owner::ownerMain()
{
	int num;

	bool scan = true;
	while (scan)
	{
		cout << endl
			<< "\nPlease select button:" << endl
			<< "1 - show my Portfolio" << endl
			<< "2 - show Market" << endl
			<< "3 - insert Securities in Portfolio" << endl
			<< "4 - update price" << endl
			<< "5 - Sell" << endl
			<< "6 - show my money" << endl
			<< "7 - End" << endl;
		cin >> num;
		SW(num, scan);

	};
}

void Owner::SW(int num, bool& scan) {
	switch (num)
	{
	case 1:
		showOwnerSecuritiesBase();
		break;
	case 2:
		cout << endl << "Market Base: " << endl;
		mb.showMarketStockBase();
		mb.showMarketBondsBase();
		break;
	case 3:
		insertOwnerSecuritiesBase();
		break;
	case 4:
		mb.updateMarketBase();
		break;
	case 5:
		money += sellSecurity();
		break;
	case 6:
		cout << endl << money << "$" << endl;
		break;
	case 7:
		scan = false;
		break;
	default:
		cout << "Not right!, return" << endl;
		break;
	}
}

int Owner::sellSecurity(){
	int num;
	cout << "Select Security for sell:\n";
	cin >> num;
	if (num < ownerSecuritiesBase.size()) {
		int price = ownerSecuritiesBase[num]->getPrice();
		ownerSecuritiesBase.erase(ownerSecuritiesBase.begin() + num);
		return price;
	}
	else {
		cout << "You have not " << num << "Security\n";
	}
}

void Owner::setName(string name)
{
	this->name = name;
}

void Owner::setPassword(string pass)
{
	this->password = pass;
}

string Owner::getName()
{
	return this->name;
}

string Owner::getPassword()
{
	return this->password;
}


void Owner::insertOwnerSecuritiesBase()
{
	int num, scan;
Flag:
	cout << "1 - Stocks\n2 - Bonds\n" << endl;
	cin >> scan;
	cout << "Number of Security in MarketBase:\n";
	cin >> num;
	switch (scan) {
	case 1:
		ownerSecuritiesBase.push_back(mb.returnMarketStocksBase(num));
		cout << "stock: "; 
		mb.returnMarketStocksBase(num)->showName();
		cout << " was added";
		break;
	case 2:
		ownerSecuritiesBase.push_back(mb.returnMarketBondsBase(num));
		cout << "bond: ";
		mb.returnMarketBondsBase(num)->showName();
		cout << " was added"; 
		break;
	default:
		cout << "Error! Return\n";
		goto Flag;
	}
}

void Owner::showOwnerSecuritiesBase()
{
	if (!ownerSecuritiesBase.empty()) {
		cout << endl << "My Base: " << endl;
		int i = 0;
		for (Securities* s : ownerSecuritiesBase) {
			cout << i << " |name: ";
			(*s).showName();
			cout << " |price: " << (*s).getPrice() << "$";
			cout << endl;
			i++;
		}
	}
	else {
		cout << endl << "Your base is empty\n";
	}
}

Owner::Owner()
{
}

Owner::~Owner()
{
}



