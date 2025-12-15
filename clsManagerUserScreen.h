#pragma once
#include <iostream>
#include "clsScreen.h"
using namespace std;


class clsManagerUserScreen : protected clsScreen {
	enum enManagerUsersMenueOptions {
		eListUsers=1, eAddNewUser=2, eDeleteUser=3,
		eUpdateUser=4, eFindUser=5, eMainMenue=6
	};
	static int _ReadnManageUserOption() { 
		cout << "\t\t\t\t\tChoose what do you want to do? [1 to 6]?";

		int Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choice;
	}
	static void _GoBackToManagerUserMenue() {


		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manager User Menue...\n";

		system("pause>0");
		ShowManagerUserScreen();
	}
	static void _ShowListUsersScreen() {
		cout << "List Users Screen Will be here";

	}
	static void _ShowAddNewUserScreen() {

		cout << "Add New User SCreen will be here ";

	}
	static void _ShowDeleteUserScreen() {
		cout << "Delete user screen will be here";

	}
	static void _ShowUpdateUserScreen() {

		cout << "Update User Screen will be here";

	}
	static void _ShowFindUserScreen() {


		cout << "Find user screen will be here";
	}
	
	static void _PerformManageUserOption(enManagerUsersMenueOptions ManagerUserMenueOptions) {

		switch (ManagerUserMenueOptions) {
		case enManagerUsersMenueOptions::eListUsers:

			system("cls");
			_ShowListUsersScreen();
			_GoBackToManagerUserMenue();

			break;

		case enManagerUsersMenueOptions::eAddNewUser:

			system("cls");

			_ShowAddNewUserScreen();
			_GoBackToManagerUserMenue();
			break;
			

		case enManagerUsersMenueOptions::eDeleteUser:

			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManagerUserMenue();
			break;


		case enManagerUsersMenueOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManagerUserMenue();
			break;

		case enManagerUsersMenueOptions::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManagerUserMenue();
			break;
		case enManagerUsersMenueOptions::eMainMenue:

			break;

		}




	}

public :

	static void ShowManagerUserScreen(){
		system("cls");
		_DrawScreenHeader("\tManage Users Screen");



		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
	
		cout << setw(37) << left << "" << "===========================================\n";


		_PerformManageUserOption(enManagerUsersMenueOptions(_ReadnManageUserOption()));



	}

};