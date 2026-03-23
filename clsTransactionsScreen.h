#pragma once
#include  <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include"clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransferScreen.h"
using namespace std;


class clsTransactionScreen : protected clsScreen {


    enum _enTransactionOptions {
        eDeposit = 1, eWithdraw = 2, eTotalBalance = 3, eTransferMenue = 4, eShowMainMenue = 6, eTransferLog
        = 5
    };

    static  short _ReadTransactionMenueOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

        short Number = clsInputValidate::ReadShortNumberBetween(1, 6, "Invalid Range ");
        return Number;

    }
    static  void _GoBackToTransactionMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...\n";
        system("pause>0");
        ShowTransacionMenue();
    }


    static void ShowDepositScreen() {
        clsDepositScreen::ShowDepositScreen();

    }
    static void ShowWithdrawScreen() {

        clsWithdrawScreen::ShowWithdrawScreen();

    }
    static void ShowTotalBalanceScreen() {
        clsTotalBalanceScreen::ShowTotalBalanceScreen();
    }
    static void ShowTransferScreen() {

        clsTransferScreen::ShowTransferScreen();
    }
    static void ShowTransferLogScreen() {

        clsTransferLogScreen::ShowTransferLogList();
    }
    static void _PerformTransacionMenue(_enTransactionOptions TransactionOption) {

        switch (TransactionOption) {
        case _enTransactionOptions::eDeposit:
            system("cls");
            ShowDepositScreen();
            _GoBackToTransactionMenue();
            break;

        case _enTransactionOptions::eWithdraw:
            system("cls");
            ShowWithdrawScreen();
            _GoBackToTransactionMenue();
            break;

        case _enTransactionOptions::eTotalBalance:
            system("cls");
            ShowTotalBalanceScreen();
            _GoBackToTransactionMenue();
            break;
        case _enTransactionOptions::eTransferMenue:
            system("cls");
            ShowTransferScreen();
            _GoBackToTransactionMenue();
            break;

        case _enTransactionOptions::eTransferLog:
            system("cls");
            ShowTransferLogScreen();

            _GoBackToTransactionMenue();
            break;
        case _enTransactionOptions::eShowMainMenue:


        {


        }

        }
    }
public:
 

	static void ShowTransacionMenue() {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {
            return;
        }

        system("cls");
        _DrawScreenHeader("\tTransaction Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransaction Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";

      
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] TotalBalances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";

        cout << setw(37) << left << "" << "\t[6] MainMenue.\n";
        cout << setw(37) << left << "" << "===========================================\n";



        _PerformTransacionMenue(_enTransactionOptions(_ReadTransactionMenueOption()));





	}



	
	






};




