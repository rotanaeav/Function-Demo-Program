#include <iostream>
using namespace std;
void printLogo()
{
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "::  ____       _                          ____                                      ::" << endl;
    cout << ":: |  _ \\ ___ | |_ __ _ _ __   __ _      |  _ \\ _ __ ___   __ _ _ __ __ _ _ __ ___  ::" << endl;
    cout << ":: | |_) / _ \\| __/ _` | '_ \\ / _` |_____| |_) | '__/ _ \\ / _` | '__/ _` | '_ ` _ \\ ::" << endl;
    cout << ":: |  _ < (_) | || (_| | | | | (_| |_____|  __/| | | (_) | (_| | | | (_| | | | | | |::" << endl;
    cout << ":: |_| \\_\\___/ \\__\\__,_|_| |_|\\__,_|     |_|   |_|  \\___/ \\__, |_|  \\__,_|_| |_| |_|::" << endl;
    cout << "::                                                        |___/                     ::" << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
}

void printMenu()
{
    cout << endl;
    cout << "\t Menu" << endl;
    cout << "1. Money Exchange" << endl;
    cout << "2. Worker Salary Calucator" << endl;
    cout << "3. Sum/Mul of 1...n" << endl;
    cout << "4. Exit" << endl;
}

void entertoex()
{
    cout << "---- Press Enter to exit -----" << endl;
    cin.ignore();
    cin.get();
}

float exchangeUSDKHR(bool isUSDtoKHR)
{
    float amount;
    string currency = (isUSDtoKHR) ? "($)" : "(riels)";
    cout << "Enter Amount " << currency << "to Exchange : ";
    cin >> amount; // ternary operator
    cout << "Amount is " << amount << currency << endl;
    if (isUSDtoKHR == true)
    {
        return amount * 4000;
    }
    else
    {
        return amount / 4000;
    }
}

void moneyExProgram()
{
    while (true)
    {
        {
            cout << "Money Exchange" << endl;
            int opt;
            cout << "1. USD to Riel" << endl;
            cout << "2. Riel to USD" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your option: ";
            cin >> opt;
            if (opt == 1)
            {
                cout << "USD -> Riel" << endl;
                float result = exchangeUSDKHR(true);
                cout << "Result is : " << result << " riel " << endl;
            }
            else if (opt == 2)
            {
                cout << "Riel -> USD" << endl;
                float result = exchangeUSDKHR(false);
                cout << "Result is : " << result << " $ " << endl;
            }
            else if (opt == 3)
            {
                cout << "Exit" << endl;
                entertoex();
                break;
            }
            entertoex();
        }
    }
}
double salaryCalculate(float hours, float wage, char gender)
{
    float salary = hours * wage;
    if (salary >= 1000)
    {
        if (gender == 'M' || gender == 'm')
        {
            salary *= 0.5;
        }
        else
            salary *= 0.7;
    }
    else
        salary *= 0.9;
    return salary;
}
void workerSalaryProgram()
{
    string name, position;
    char gender;
    float hours, wage;
    while (true)
    {

        cout << "------Worker Salary Calucator------" << endl;
        cout << "[-] Input The Worker Information [-]" << endl;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Gender (M/F) : ";
        cin >> gender;
        cout << "Enter Position : ";
        cin >> position;
        cout << "Enter Wage ($) : ";
        cin >> wage;
        cout << "Enter Hours (h) : ";
        cin >> hours;
        cout << "Name is : " << name << endl;
        cout << "Gender is : " << gender << endl;
        cout << "Position is : " << position << endl;
        cout << "Wage is : " << wage << '$' << endl;
        cout << "Hours is : " << hours << "hrs" << endl;
        cout << "Salary is : " << salaryCalculate(hours, wage, gender) << "$" << endl;
        cout << endl;
        cout << "Press Enter to continue or Q to quit: ";
        // exit-button
        cin.ignore();
        char quit = cin.get();
        if (quit == 'q' || quit == 'Q')
        {
            cout << "Exit" << endl;
            break;
        }
    }
}
void sumMul()
{
    int n;
    int sum = 0;
    long long mul = 1;

    cout << "[+]---- Sum and Mul of n ----[+]" << endl;
    cout << "Enter n: ";
    cin >> n;
    if (n >= 0)
    {
        for (int i = 1; i <= n; i++)
        {
            sum += i;
            mul *= i;
        }
        cout << "Sum of 1...n is : " << sum << endl;
        cout << "Mul of 1...n is : " << mul << endl;
    }
    else
    {
        cout << "Please enter non-negative numbers." << endl;
    }
    entertoex();
}
int main()
{
    int option;
    do
    {
        system("cls");
        printLogo();
        printMenu();
        cout << "Enter your option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            moneyExProgram();
            break;
        case 2:
            workerSalaryProgram();
            break;
        case 3:
            sumMul();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }

    while (option != 4);
    return 0;
}