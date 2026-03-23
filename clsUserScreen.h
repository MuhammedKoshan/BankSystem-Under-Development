#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUser.h"
#include "clsString.h"
class clsUserListScreen :protected clsScreen
{

private:

    
    static void _PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << User.GetUserName();
        cout << "| " << setw(20) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << clsUtil::Encryption(User.GetPassword(),2);
        cout << "| " << setw(12) << left << User.GetPermissions();


    }

public:


    static void ShowUsersList()
    {


        vector <clsUser> vUsers = clsUser::GetUsersList();
        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Username";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permission";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser User  : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

