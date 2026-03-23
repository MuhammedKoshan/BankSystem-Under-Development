
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;




class clsAddNewClientScreen : protected clsScreen {

private :

   static void _ReadClientInfo(clsBankClient& Client) {

        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();



    }

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

   static void ShowAddNewClientScreen() {
       if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
           return;
       }

        string Title = "\t  Add New Client Screen";
        string SubTitle = "";

        _DrawScreenHeader(Title, SubTitle);

        cout << "Please Enter the account Number: ";

        string AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber)) {

            cout << "This Client AccountNumber is already exist Try another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        /*    clsBankClient(enMode Mode, string FirstName, string LastName,
              string Email, string Phone, string AccountNumber, string PinCode,
              float AccountBalance) :
              clsPerson(FirstName, LastName, Email, Phone)*/

        clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClientInfo(Client);





        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client.Save();

        switch (SaveResult) {

        case clsBankClient::enSaveResults::svSucceeded:

            cout << "\nAccount Added Successfully :-)\n";
            _PrintClient(Client);

            break;



        case clsBankClient::enSaveResults::svFaildEmptyObject:
            cout << "\nError account was not saved because it's Empty";
            _PrintClient(Client);

            break;


        }
    }






};
