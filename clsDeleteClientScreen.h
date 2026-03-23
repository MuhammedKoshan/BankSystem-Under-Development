#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen {
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

   static void ShowDeleteClient() {
       if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient) ){
           return;
       }

       string Title = "\t  Delete Client Screen";
       string SubTitle = "";

       _DrawScreenHeader(Title, SubTitle);
        cout << "Please Enter the account Number: ";

        string AccountNumber = clsInputValidate::ReadString();
        while (!(clsBankClient::IsClientExist(AccountNumber))) {

            cout << "This Client AccountNumber is not exist Try another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);
        char Answer;
        cout << "Are you sure you want to delete this client? \n";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            if (Client.Delete()) {

                cout << "Client Deleted Successfully";
                _PrintClient(Client);



            }
            else {
                cout << "Error Client Wasnt deleted";
            }
        }




    }




};
