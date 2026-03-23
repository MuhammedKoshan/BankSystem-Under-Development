
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;




class clsAddNewUserScreen : protected clsScreen {

private:

    static void _ReadUserInfo(clsUser& User) {


        cout << "\nEnter FistName: ";
        User.FirstName = clsInputValidate::ReadString();
        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();
            
        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.SetPassword(clsInputValidate::ReadString());

        cout << "\nEnter Permissions: ";
        User.SetPermissions(_ReadPermissionsToSet(User));



    }

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
    static int _ReadPermissionsToSet(clsUser &User) {
      

            int Permissions = 0;
            char Answer = 'n';


            cout << "\nDo you want to give full access? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                return -1;
            }

            cout << "\nDo you want to give access to : \n ";

            cout << "\nShow Client List? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {


                Permissions += clsUser::enPermissions::pListClients;
            }


            cout << "\nAdd New Client? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pAddNewClient;
            }

            cout << "\nDelete Client? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pDeleteClient;
            }

            cout << "\nUpdate Client? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pUpdateClients;
            }

            cout << "\nFind Client? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pFindClient;
            }

            cout << "\nTransactions? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pTranactions;
            }

            cout << "\nManage Users? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pManageUsers;
            }
            cout << "\n Login Register? y/n? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Permissions += clsUser::enPermissions::pRegisterLog;
            }

            return Permissions;

        }
   


public:

    static void ShowAddNewUserScreen() {
        string Title = "\t  Add New User Screen";
        string SubTitle = "";

        _DrawScreenHeader(Title, SubTitle);

        cout << "Please Enter the UserName: ";

        string UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName)) {

            cout << "This User is already exist Try another one: ";
            UserName = clsInputValidate::ReadString();
        }
        /*    clsBankClient(enMode Mode, string FirstName, string LastName,
              string Email, string Phone, string AccountNumber, string PinCode,
              float AccountBalance) :
              clsPerson(FirstName, LastName, Email, Phone)*/

        clsUser User = clsUser::GetAddNewUserObject(UserName);
        _ReadUserInfo(User);





        clsUser::enSaveResults SaveResult;

        SaveResult = User.Save();

        switch (SaveResult) {

        case clsUser::enSaveResults::svSucceeded:

            cout << "\n User Added Successfully :-)\n";
            _PrintUser(User);

            break;



        case clsUser::enSaveResults::svFaildEmptyObject:
            cout << "\nError User was not saved because it's Empty";
            _PrintUser(User);

            break;


        }
    }






};
