								//Mine Solution

//#pragma once
//#include <iostream>
//#include "clsScreen.h"
//#include "clsBankClient.h"
//using namespace std;
//
//class clsTranferScreen : protected clsScreen {
//private:
//	static void _Print(clsBankClient Client) {
//		cout << "\nClient Card:";
//		cout << "\n___________________";
//		cout << "\nFull Name   : " << Client.FullName();
//		cout << "\nAcc. Number : " << Client.AccountNumber();
//		cout << "\nBalance     : " << Client.AccountBalance;
//		cout << "\n___________________\n";
//
//
//
//	}
//
//
//
//
//public:
//	static void ShowTransferScreen() {
//		_DrawScreenHeader("\t Transfer Screen");
//		vector<clsBankClient>vClients = clsBankClient::GetClientsList();
//
//		string  sClientFrom;
//		cout << "Please Enter Account Number to Transfer From: ";
//		cin >> sClientFrom;
//
//		while (!clsBankClient::IsClientExist(sClientFrom)) {
//			cout << "No Client in this Account Number, Try again? ";
//			cin >> sClientFrom;
//		}
//		clsBankClient ClientFrom = clsBankClient::Find(sClientFrom);
//
//		_Print(ClientFrom);
//
//		string sClientTo;
//		cout << "Please Enter Account Number to Transfer to: ";
//		cin >> sClientTo;
//		
//
//		while ((!clsBankClient::IsClientExist(sClientTo)) || sClientFrom == sClientTo) {
//			if (sClientFrom == sClientTo) {
//				cout << "You can not transfer between same account, Try again? ";
//				cin >> sClientTo;
//			}
//			cout << "No Client in this Account Number, Try again? ";
//			cin >> sClientTo;
//
//
//		}
//		
//		clsBankClient ClientTo = clsBankClient::Find(sClientTo);
//		_Print(ClientTo);
//		
//		int Amount;
//		cout << "Enter Transfer Amount? ";
//		cin >> Amount;
//		while (!((ClientFrom.AccountBalance > Amount)&& (Amount!=0))) {
//			cout << "Amount exceed Please try another amount: ";
//			cin >> Amount;
//
//		}
//	
//
//		char Answer;
//		cout << "Are you sure you want to perform this operation? y/n? ";
//		cin >> Answer;
//		if (!(Answer == 'y' || Answer == 'Y'))
//		{
//			return;
//		}
//		
//		ClientFrom.WithDraw(Amount);
//		ClientTo.Deposit(Amount);
//
//		cout << "\nTransfer done successfully\n ";
//		_Print(ClientFrom);
//
//		_Print(ClientTo);
//	
//
//	}
//
//
//
//
//};
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen {

private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber() {
        string AccountNumber;
        cout << "\n Please Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\n Account number is not found, choose another one: ";

            AccountNumber = clsInputValidate::ReadString();

        }

        return AccountNumber;

    }

    static float ReadAmount(clsBankClient SourceClient) {

        float Amount;
        cout << "\nEnter Transfer Amount? ";
        Amount =clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance) {
            cout << "\n Amount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadFloatNumber();

        }
        return Amount;



    }



public:
    static void ShowTransferScreen() {

        _DrawScreenHeader("\tTransfer Screen");
        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(SourceClient);
        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(DestinationClient);

        float Amount = ReadAmount(SourceClient);
        cout << "\n Are you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.GetUserName())) {
                cout << "\n Transfer done successfully";
                

            }
            else {
                cout << "\n Transfer Faild \n";

            }



        }
        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
    }


};