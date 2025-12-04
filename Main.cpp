#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

void ReadClientInfo(clsBankClient& Client)
{
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

void AddNewClient()
{
    string AccountNumber = "";
    cout << "\n Please Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    while (clsBankClient::IsClientExist(AccountNumber)) {

        cout << "\n Account Number Is Already Used, Choose another one:  ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(Client);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = Client.Save();

    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Addeded Successfully :-)\n";
        Client.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }
    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
    {
        cout << "\nError account was not saved because account number is used!\n";
        break;

    }
    }
}




void DeleteClient() {
    string AccountNumber = "";

    cout << "\n Please Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(AccountNumber)) {

        cout << "\nAccount Number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();



    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
 
    Client.Print();

    cout << "\n Are you sure you want to delete this client y/n?";
    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y') {


        if (Client.Delete()) {

            cout << "\n Client Deleted Successfully :) \n";
            Client.Print();

        }
        else {
            cout << "\n Error Client Was not Deleted\n";

        }
    }

}







int main()

{
    DeleteClient();
    system("pause>0");
    return 0;
}
