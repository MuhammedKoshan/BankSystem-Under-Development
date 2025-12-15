#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsInputValidate.h"
#include "clsBankClient.h";
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManagerUserScreen.h"
using namespace std;


class clsMainScreen : protected clsScreen {
private:

    enum enMainMenueOptions {
        eListClinets = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
        eFindClient = 5, eShowTransationsMenue = 6, eManagaUsers = 7, eExit = 8
    };


    static int _ReadMainMenueOption() {
        cout << "\t\t\t\t\tChoose what do you want to do? [1 to 8]?";

        int Choice = clsInputValidate::ReadShortNumberBetween(1, 8);
        return Choice;

    }

    static  void _GoBackToMainMenue() {

        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();


    }

    static void _ShowAllClientsScreen() {
        // cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::ShowClientsList();

    }

    static void _ShowAddClientsScreen() {
        //   cout << "\nAdd Client List Screen Will be here...\n";

        clsAddNewClientScreen::ShowAddNewClientScreen();



    }

    static void _ShowDeleteClientsScreen() {

        // cout << "\nDelete Client List Screen Will be here...\n";

        clsDeleteClientScreen::ShowDeleteClientScreen();



    }
    static void _ShowUpdateClientsScreen() {

        // cout << "\nUpdate Client List Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientsScreen() {

        //  cout << "\nFind Client List Screen Will be here...\n";
        clsFindClientScreen::ShowUpdateClientScreen();
    }


    static void _ShowClientsTransactionsMenue() {

        //  cout << "\nTransactions Menue Will be here...\n";

        clsTransactionsScreen::ShowTransactionsScreen();

    }
    static void _ShowManagerUserMenue() {

        // cout << "\nUsers Menue Will be here...\n";

        clsManagerUserScreen::ShowManagerUserScreen();

    }

    static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";


    }

    static void _PerformMainMenueOption(enMainMenueOptions MainMenueOption) {


        switch (MainMenueOption) {

        case enMainMenueOptions::eListClinets:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;


        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");

            _ShowDeleteClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");

            _ShowUpdateClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransationsMenue:
            system("cls");
            _ShowClientsTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManagaUsers:
            system("cls");
            _ShowManagerUserMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _ShowEndScreen();

        }


    }


public:


    static void ShowMainMenue() {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");


        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PerformMainMenueOption(enMainMenueOptions(_ReadMainMenueOption()));



    }

};
