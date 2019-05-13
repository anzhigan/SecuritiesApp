#pragma once
#include <string>
using namespace std;
class Securities
{
private:
	char name[5];
	int price;
public:
	Securities();
	~Securities();
	void setName(char *name);
	void setPrice(int price);
	char* getName();
	int getPrice();
	void showName();
};

