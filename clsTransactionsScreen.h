#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsMainScreen.h"

using namespace std;


class clsTransactionsScreen : protected clsScreen {

private:

    enum enTransactionsMenueOptions {

        eDeposit = 1, eWithdraw = 2, eShowTotalBalances = 3, eShowMainMenue = 4


    };
    static  void _GoBackToTransactionsMenue() {

        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

        system("pause>0");
        ShowTransactionsScreen();


    } 
    static int _ReadTransactionsMenueOption() {
        cout << "\t\t\t\t\tChoose what do you want to do? [1 to 4]?";

        int Choice = clsInputValidate::ReadShortNumberBetween(1, 4);
        return Choice;
    }
    static void _ShowDepositScreen() {
        cout << "\nDeposit Screen Will be Here\n";

    }
    static void _ShowWithdrawScreen() {
        cout << "\nWithdraw Screen Will be Here\n";

    }
    static void _ShowTotalBalancesScreen() {
        cout << "\nBalances Screen Will be Here\n";

    }




    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption) {
        switch (TransactionsMenueOption) {

        case enTransactionsMenueOptions::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eShowTotalBalances:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eShowMainMenue:

            break;
           
        }
    
    }
public:

	static void ShowTransactionsScreen() {

        system("cls");
        _DrawScreenHeader("\t\Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
 
        cout << setw(37) << left << "" << "===========================================\n";


        _PerformTransactionsMenueOption(enTransactionsMenueOptions(_ReadTransactionsMenueOption()));

	}




};