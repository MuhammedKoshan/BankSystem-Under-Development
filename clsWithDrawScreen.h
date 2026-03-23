#pragma once
#include  <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

#include "clsInputValidate.h"
using namespace std;
class clsWithdrawScreen : protected clsScreen {

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

public:

	static void ShowWithdrawScreen() {

		_DrawScreenHeader("\tWithdraw  Screen");
		cout << "Enter Account Number to Withdraw";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "No client in this Account Number try another one: ";
			cin >> AccountNumber;
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		cout << "How Much you want to Withdaw: ";
		int Amount = clsInputValidate::ReadDblNumber();
		
		cout << "Are you sure you want to perform this transaction? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.WithDraw(Amount)) {

				cout << "Amount Withdraw Succesfully\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance;



			}
			else {

				cout << "Cancelled";

			}

		

			
			


		}
		else {
			cout << "Withdraw operation cancelled";
		}


	}

};
