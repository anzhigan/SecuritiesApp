#pragma once
#include "OwnerBase.h"
#include <string>
class Owner
{
public:
private:
	int money;
	string name;
	string password;
	vector<Securities *> ownerSecuritiesBase;

	MarketBase mb;
	MarketBase* pmb = &mb;
public:
	void ownerMain();
	void SW(int num, bool& scan);
	void setName(string name);
	void setPassword(string pass);
	string getName();
	string getPassword();
	int sellSecurity();
	void insertOwnerSecuritiesBase();
	void showOwnerSecuritiesBase();
	Owner();
	~Owner();
};

