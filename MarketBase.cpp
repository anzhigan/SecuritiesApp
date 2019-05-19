#include "pch.h"
#include "MarketBase.h"

MarketBase::MarketBase()
{
	defaultInsertMarketSecutitiesBase();
}

MarketBase::~MarketBase()
{
} 

//�������� ����� ���������� ��
void MarketBase::defaultInsertMarketSecutitiesBase() 
{
	for (int i = 0; i < 10; ++i) {
		const int price = rand() % 9999999;
		const int len = 5;
		char name[len];
		//�������� ����������� ���� ���������� ���������� ����������
		gen_randomString(name, len);

		//������� �� � ������ ���� ��������� ��������
		marketStocksBase[i] = new Stocks;
		marketStocksBase[i]->setName(name);
		marketStocksBase[i]->setPrice(price);
	}
	for (int i = 0; i < 10; ++i) {
		const int price = rand() % 110 + 90;
		const int len = 5;
		char name[len];
		//�������� ����������� ���� ���������� ���������� ����������
		gen_randomString(name, len);

		//������� �� � ������ ���� ��������� ��������
		marketBondsBase[i] = new Bonds;
		marketBondsBase[i]->setName(name);
		marketBondsBase[i]->setPrice(price);
	}
}

//��������� ���������� �����
void MarketBase::gen_randomString(char *name, const int len) {
	static const char alpanum[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < len; ++i) {
		name[i] = alpanum[rand() % (sizeof(alpanum) - 1)];
	}
	name[len] = 0;
}
Stocks *MarketBase::returnMarketStocksBase(int number)
{
	return marketStocksBase[number];
}
Bonds *MarketBase::returnMarketBondsBase(int number)
{
	return marketBondsBase[number];
}

void MarketBase::updateMarketBase() {
	for (int i = 0; i < 10; ++i) {
		auto forStocks = marketStocksBase[i]->factor *
			marketStocksBase[i]->getPrice(); 
		auto forBonds = marketBondsBase[i]->factor *
			marketBondsBase[i]->getPrice();

		marketStocksBase[i]->setPrice(forStocks);
		marketBondsBase[i]->setPrice(forBonds);
	}
	 
}

void MarketBase::showMarketStockBase()
{
	cout << endl << "Stocks: " << endl;
	for (int i = 0; i < 10; ++i) 
	{
		cout << i << " |name: ";
		marketStocksBase[i]->showName();
		cout << " |price: " << marketStocksBase[i]->getPrice() 
			<< "$" <<endl;
	}
}

void MarketBase::showMarketBondsBase()
{
	cout << endl << "Bonds: " << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << i << " |name: ";
		marketBondsBase[i]->showName();
		cout << " |value: " << marketBondsBase[i]->getPrice()
			<< "%" << endl;
	}
}
