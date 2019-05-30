#include "pch.h"
#include <iostream>
#include "Owner.h"
#include "MarketBase.h"
#include "OwnerBase.h"
#include <boost\variant.hpp>
#include <list>
#include <string>
using namespace std;

Owner createOwner() {
	string name;
	string pass;
	Owner owner;

	cout << "Enter name:\n";
	cin >> name;
	owner.setName(name);

	cout << "Enter password:\n";
	cin >> pass;
	owner.setPassword(pass);

	cout << "Registration completed successfully!\n";

	return owner;
}

Owner login(vector<Owner>& ownerList) {
	string password;
	string name;

Enterlogin:
	cout << "Enter your name:\n";
	cin >> name;
	cout << "Enter your password:\n";
	cin >> password;

	for (Owner o : ownerList) {
		if ((password == o.getPassword()) && (name == o.getName())) {
			cout << "Successfully!\n";
			return o;
		}
		else {
			cout << "Not successfully! Return\n" << endl;
			goto Enterlogin;
		}
	}
}

bool SW(vector<Owner>& pOwnerList, char num) {
	switch (num)
	{
	case '1':
		if (!pOwnerList.empty()) {
			login(pOwnerList).ownerMain();
		}
		else {
			cout << "Owner List is empty\n";
		}
		break;
	case '2':
		pOwnerList.push_back(createOwner());
		break;
	case '3':
		if (!pOwnerList.empty()) {
			cout << "Owner:\n";
			for (Owner o : pOwnerList) {
				cout << o.getName() << endl;
			}
		}
		else {
			cout << "Owner List is empty\n";
		}
		break;
	default:
		cout << "Not right!, return\n";
		break; 
		bool scan = false;
		return scan;
	}
}

int main() {
	vector<Owner> ownerList;
	char num;

	bool scan = true;
	while (scan)
	{
		cout << endl
			<< "Hello!" << endl
			<< "Please select button:" << endl
			<< "1 - login" << endl
			<< "2 - sign in" << endl
			<< "3 - Show all owner\n" << endl;
		cin >> num;
		scan = SW(ownerList, num);
	};
}

