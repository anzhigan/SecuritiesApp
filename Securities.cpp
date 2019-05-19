#include "pch.h"
#include "Securities.h"
#include <string>
#include <iostream>
using namespace std;

Securities::Securities()
{	
}

Securities::~Securities()
{
}

void Securities::setName(char *name)
{
	for (int i = 0; i < 5; ++i) {
		this -> name[i] = name[i];
	}
}

void Securities::setPrice(int price)
{
	this->price = price;
}

char* Securities::getName() {
	return this->name;
}

int Securities::getPrice()
{
	return price;
}

void Securities::showName()
{
	for (int i = 0; i < 5; ++i) {
		cout << name[i];
	}
}

