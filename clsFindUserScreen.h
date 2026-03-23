#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsUser.h"
using namespace std;

class clsFindUserScreen : protected clsScreen {

private:

	static void _PrintUser(clsUser User)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";

		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUserName    : " << User.GetUserName();

		cout << "\n Permissions: " << User.GetPermissions();
		cout << "\n___________________\n";

	}

public:

	static void ShowFindUser() {
		string Title = "\t  Find User Screen";	
		string SubTitle = "";

		_DrawScreenHeader(Title, SubTitle);
		string UserName = "";
		cout << "Enter UserName: ";
		cin >> UserName;
		while (!clsUser::IsUserExist(UserName)) {
			cout << "Username dores exist try another one: ";
			cin >> UserName;
		}
		vector<clsUser>vUsers = clsUser::GetUsersList();

		for (clsUser C : vUsers) {
			if (UserName == C.GetUserName()) {

				cout << "Yes We Find It\n ";
				_PrintUser(C);
				return;



			}

		}





	}




};