#pragma once
#include <iostream>
#include "clsScreen.h"

#include "clsUtil.h"
using namespace std;

class clsLoginRegisterScreen : protected clsScreen {

private:

    string _Date;
    string _UserName;
    string _Password;
    int _Permissions;




    static  vector <clsLoginRegisterScreen> _LoadLoginsDataFromFile()
    {

        vector <clsLoginRegisterScreen> vLogins;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsLoginRegisterScreen Login = _ConvertLineToLoginRegisterObject(Line);

                vLogins.push_back(Login);
            }

            MyFile.close();

        }

        return vLogins;

    }


    static void _PrintLoginRecordLine(clsLoginRegisterScreen Login)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << Login._Date;
        cout << "| " << setw(42) << left << Login._UserName;
        cout << "| " << setw(15) << left <<Login._Password;
        cout << "| " << setw(25) << left << Login._Permissions;
      

    }


    static clsLoginRegisterScreen _ConvertLineToLoginRegisterObject(string Line, string Seperator = "#//#") {



        vector<string>vLoginData;
        vLoginData = clsString::Split(Line, Seperator);
        return clsLoginRegisterScreen(vLoginData[0], vLoginData[1], clsUtil::Decryption(vLoginData[2],2), stoi(vLoginData[3]));

    }
     static vector <clsLoginRegisterScreen> GetLogsList() {
         vector<clsLoginRegisterScreen>Logs = _LoadLoginsDataFromFile();
         return Logs;


    }

public:

	clsLoginRegisterScreen(string Date,string UserName,string Password,int Permissions) {
		_Date = Date;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
}



    static void ShowLoginList() {

        if (!CheckAccessRights(clsUser::enPermissions::pRegisterLog)) {

            return;
        }

        vector<clsLoginRegisterScreen>Logins = GetLogsList();
        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(Logins.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date";
        cout << "| " << left << setw(42) << "UserName";
        cout << "| " << left << setw(15) << "Paswword";
        cout << "| " << left << setw(25) << "Permissions";
        
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (Logins.size() == 0)
            cout << "\t\t\t\tNo Record Available In the System!";
        else

            for (clsLoginRegisterScreen Login : Logins)
            {

                _PrintLoginRecordLine(Login);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }






};