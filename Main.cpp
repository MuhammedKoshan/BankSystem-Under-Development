#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

void PrintClientRecordLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(40) << left << Client.FullName();
    cout << "| " << setw(20) << left << Client.AccountBalance;

}

void ShowTotalBalances()
{

    vector <clsBankClient>vClients = clsBankClient::GetClientsList();
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(20) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    if (vClients.size() == 0) {

        cout << "\t\t\t No Clients Available In The System! ";

    }
    else {

        for (clsBankClient Client : vClients) {

            PrintClientRecordLine(Client);
            cout << endl;


        }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\n\t\t\t\tTotal Balances = " << clsBankClient::GetTotalBalances() << "\n";
        cout << "\t\t\t\t( " << clsBankClient::NumberToText(clsBankClient::GetTotalBalances()) << ")";


    }

}









int main()

{
    ShowTotalBalances();
    system("pause>0");
    return 0;
}
