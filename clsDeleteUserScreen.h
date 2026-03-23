#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteUserScreen : protected clsScreen {
private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
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

    static void ShowDeleteUser() {
        string Title = "\t  Delete User Screen";
        string SubTitle = "";

        _DrawScreenHeader(Title, SubTitle);
        cout << "Please Enter the UserName: ";

        string UserName = clsInputValidate::ReadString();
        while (!(clsUser::IsUserExist(UserName))) {

            cout << "This User is not exist Try another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        _PrintUser(User);
        char Answer;
        cout << "Are you sure you want to delete this User? \n";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            if (User.Delete()) {

                cout << "User Deleted Successfully";
                _PrintUser(User);



            }
            else {
                cout << "Error User Wasnt deleted";
            }
        }

            


    }




};
