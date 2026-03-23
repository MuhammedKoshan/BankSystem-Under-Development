#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;

class clsFindClientScreen : protected clsScreen {

private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public :

	static void ShowFindClient() {
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) {
			return;
		}

		string Title = "\t  Find Client Screen";
		string SubTitle = "";

		_DrawScreenHeader(Title, SubTitle);
		string AccountNumber = "";
		cout << "Enter Account Number: ";
		cin >> AccountNumber;
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "account number dores exist try another one: ";
			cin >> AccountNumber;
		}
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();

		for (clsBankClient C : vClients) {
			if (AccountNumber == C.AccountNumber()) {

				cout << "Yes We Find It\n ";
				_PrintClient(C);
				return;



			}

		}





	}




};
