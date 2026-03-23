#pragma once
#include  <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include"clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsUserScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsUpdateUserScreen.h"
using namespace std;



class clsManageUsersScreen : protected clsScreen {


    enum _enManageUserOption { eListUsers = 1, eAddNewUsers = 2, eDeleteUser = 3,eUpdateUser=4, eFindUser = 5,eMainMenue=6};

    static  short _ReadManageUserMenueOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

        short Number = clsInputValidate::ReadShortNumberBetween(1, 6, "Invalid Range ");
        return Number;

    }
    static  void _GoBackToManageUserScreen()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menue...\n";
        system("pause>0");
        ShowManageUsersScreen();
    }

    

   static void _ListUsersScreen() {

       clsUserListScreen::ShowUsersList();

    }

   static  void _AddNewUserScreen() {

       clsAddNewUserScreen::ShowAddNewUserScreen();
    }
   static  void _DeleteUserScreen() {

       clsDeleteUserScreen::ShowDeleteUser();
   }



   static    void _FindUserScreen() {

       clsFindUserScreen::ShowFindUser();
   }



   static   void _UpdateUserScreen() {
       clsUpdateUserScreen::ShowUpdateUser();

    }
   
    
    static void _PerformManageUsersMenue(_enManageUserOption ManageUserOption) {

        switch (ManageUserOption) {
        case _enManageUserOption::eListUsers:
            system("cls");
            _ListUsersScreen();
            _GoBackToManageUserScreen();
            break;

        case _enManageUserOption::eAddNewUsers:
            system("cls");
            _AddNewUserScreen();
            _GoBackToManageUserScreen();
            break;


        case _enManageUserOption::eDeleteUser:
            system("cls");
            _DeleteUserScreen();
            _GoBackToManageUserScreen();
            break;

        case _enManageUserOption::eUpdateUser:
            system("cls");

            _UpdateUserScreen();
            _GoBackToManageUserScreen();
            break;

        case _enManageUserOption::eFindUser:
            system("cls");

            _FindUserScreen();
            _GoBackToManageUserScreen();
            break;

        case _enManageUserOption::eMainMenue:

        {
        

        }

        }
    }
public:


    static void ShowManageUsersScreen() {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers)) {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t Manage Users  Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tManage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";


        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";

        cout << setw(37) << left << "" << "\t[4] Update User.\n";

        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";

        cout << setw(37) << left << "" << "===========================================\n";



        _PerformManageUsersMenue(_enManageUserOption(_ReadManageUserMenueOption()));





    }



};




