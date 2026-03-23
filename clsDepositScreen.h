#pragma once
#include  <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

#include "clsInputValidate.h"
using namespace std;
class clsDepositScreen : protected clsScreen {

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

	static void ShowDepositScreen() {

		_DrawScreenHeader("\tDeposit Screen");
		cout << "Enter Account Number to deposit";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "No client in this Account Number try another one: ";
			cin >> AccountNumber;
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		cout << "How Much you want to deposit: ";
		int Amount = clsInputValidate::ReadDblNumber();
		cout << "Are you sure you want to perform this transaction? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{

			Client.Deposit(Amount);
		 



	}
		else {
			cout << "Deposit operation cancelled";
		}


	}

};
