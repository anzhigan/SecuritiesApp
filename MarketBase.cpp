#include "pch.h"
#include "MarketBase.h"

MarketBase::MarketBase()
{
	defaultInsertMarketSecutitiesBase();
}

MarketBase::~MarketBase()
{
} 

//заполним рынок рандомными цб
void MarketBase::defaultInsertMarketSecutitiesBase() 
{
	for (int i = 0; i < 10; ++i) {
		const int price = rand() % 999999;
		//const int len = rand() % 7;
		const int len = 5;
		char name[len];
		//заполним объявленные выше переменные рандомными значениями
		gen_randomString(name, len);

		//создаем цб и кидаем туда рандомные значения
		Stocks s;
		s.setName(name);
		s.setPrice(price);
		marketStocksBase.push_back(s);
	}
	for (int i = 0; i < 10; ++i) {
		const int price = rand() % 90 - 110;
		//const int len = rand() % 7;
		const int len = 5;
		char name[len];
		//заполним объявленные выше переменные рандомными значениями
		gen_randomString(name, len);

		//создаем цб и кидаем туда рандомные значения
		Bonds b;
		b.setName(name);
		b.setPrice(price);
		marketBondsBase.push_back(b);
	}
}

//генерация рандомного имени
void MarketBase::gen_randomString(char *name, const int len) {
	static const char alpanum[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < len; ++i) {
		name[i] = alpanum[rand() % (sizeof(alpanum) - 1)];
	}
	name[len] = 0;
}
//Добавление своей цб на рынок


void MarketBase::insertYourselfMarketBase()
{	//Создаем ценную бумагу 
	//и устанавливаем имя с цб
	int num;
	cout << "1)Stocks 2)Bonds";
	cin >> num;
	const int len = 5;
	char name[len];
	int price;
	cout << "Enter name: ";
	for (int i = 0; i < len; ++i) {
		cin >> name[i];
	}
	cout << "Enter price: ";
	cin >> price;

	if (num == 1) {
		Stocks s;

		s.setName(name);
		s.setPrice(price);

		//Кидаем эту бумагу в базу на Рынок
		marketStocksBase.push_back(s);
	}
	else if (num == 2) {

		Bonds b;

		b.setName(name);
		b.setPrice(price);

		//Кидаем эту бумагу в базу на Рынок
		marketBondsBase.push_back(b);
	}
	
}

Stocks MarketBase::returnMarketStocksBase(int number)
{
	return marketStocksBase[number];
}
Bonds MarketBase::returnMarketBondsBase(int number)
{
	return marketBondsBase[number];
}

void MarketBase::updateMarketBase() {
	for (int i = 0; i < 10; ++i) {
		marketStocksBase[i].setPrice(
			marketStocksBase[i].factor *
			marketStocksBase[i].getPrice());
		marketBondsBase[i].setPrice(
			marketBondsBase[i].factor *
			marketBondsBase[i].getPrice());
	}
} 

void MarketBase::showMarketStockBase()
{
	cout << endl << "Stocks: " << endl;
	for (int i = 0; i < 10; ++i) 
	{
		cout << i << " |name: ";
		marketStocksBase[i].showName();
		cout << " |price: " << marketStocksBase[i].getPrice() 
			<< "$" <<endl;
	}
}

void MarketBase::showMarketBondsBase()
{
	cout << endl << "Bonds: " << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << i << " |name: ";
		marketBondsBase[i].showName();
		cout << " |value: " << marketBondsBase[i].getPrice()
			<< "%" << endl;
	}
}
