#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsTransferLogScreen : protected clsScreen {
private:
    string   _Date;
    string _SourceAcc;
    string  _DestinationAcc;
    float  _Amount;
    float _SourceBalance;
    float _DestinationBalance;
    string _UserName;
    static clsTransferLogScreen _ConvertLineToLoginRegisterObject(string Line, string Seperator = "#//#") {



        vector<string>vLoginData;
        vLoginData = clsString::Split(Line, Seperator);
        return clsTransferLogScreen(vLoginData[0], vLoginData[1], vLoginData[2], stof(vLoginData[3]),stof( vLoginData[4]),stof(vLoginData[5]),vLoginData[6]);

    }



    static  vector <clsTransferLogScreen> _LoadLoginsDataFromFile()
    {

        vector <clsTransferLogScreen> vLogins;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsTransferLogScreen Login = _ConvertLineToLoginRegisterObject(Line);

                vLogins.push_back(Login);
            }

            MyFile.close();

        }

        return vLogins;

    }



	static vector <clsTransferLogScreen> GetTransferLogsList() {
		vector<clsTransferLogScreen>Logs = _LoadLoginsDataFromFile();
		return Logs;


	}

    static void _PrintLoginRecordLine(clsTransferLogScreen Login)
    {

        cout << setw(12) << left << "" << "| " << setw(15) << left << Login._Date;
        cout << "| " << setw(10) << left << Login._SourceAcc;
        cout << "| " << setw(10) << left << Login._DestinationAcc;
        cout << "| " << setw(10) << left << Login._Amount;
        cout << "| " << setw(10) << left << Login._SourceBalance;
        cout << "| " << setw(10) << left << Login._DestinationBalance;
        cout << "| " << setw(10) << left << Login._UserName;


    }


public:


    clsTransferLogScreen(string Date, string SourceAcc,
        string DestinaitonAcc, float Amount,
        float SourceBalance, float DestinaitonBalance,
        string UserName) {

        _Date = Date;
        _SourceAcc = SourceAcc;
        _DestinationAcc = DestinaitonAcc;
        _Amount = Amount;
        _SourceBalance = SourceBalance;
        _DestinationBalance = DestinaitonBalance;
        _UserName = UserName;


    }
    static void ShowTransferLogList() {

        vector<clsTransferLogScreen>vTransferLogins = GetTransferLogsList();
        string Title = "\t Transfer Log Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogins.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;



        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogins.size() == 0)
            cout << "\t\t\t\tNo Record Available In the System!";
        else

            for (clsTransferLogScreen Login : vTransferLogins)
            {

                _PrintLoginRecordLine(Login);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


    }
	




};