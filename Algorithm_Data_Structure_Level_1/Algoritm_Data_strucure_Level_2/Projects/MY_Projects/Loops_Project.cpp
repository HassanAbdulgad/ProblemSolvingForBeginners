#include <iostream>
using namespace std;

void Print_A_to_Z_Double();
void Print_Pyrmids(int n);
void Print_From1To10Pyrmids();
void Print_From1To10Pyrmids_Rotate();
void Print_Numbers();
void Print_A_to_Z_Pyrmids();
void ShowMenue();

int main()
{
    ShowMenue();
    return 0;


















    
}

void Print_Numbers()
{
    for (size_t i = 1; i <= 10; i++)
    {
        for (size_t j = i; j <= 10; j++)
        {
            cout << j << " ";
        }
        cout << '\n';
    }
    cout << "\n********************************\n";
}

void Print_A_to_Z_Pyrmids()
{
    for (int i = 65; i < 71; i++)
    {
        for (int j = 65; j <= i; j++)
        {
            cout << char(j) << " ";
        }
        cout << '\n';
    }
    cout << "\n********************************\n";
}

void Print_From1To10Pyrmids_Rotate()
{
    for (size_t i = 1; i <= 10; i++)
    {
        for (size_t j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << '\n';
    }
    cout << "\n********************************\n";
}

void Print_From1To10Pyrmids()
{
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 1; j <= 10 - i; j++)
        {
            cout << j << " ";
        }
        cout << '\n';
    }
    cout << "\n********************************\n";
}

void Print_Pyrmids(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
    cout << "\n********************************\n";
}

void Print_A_to_Z_Double()
{
    for (int i = 65; i <= 90; i++)
    {
        cout << "Letter : " << char(i) << "\n";
        for (int j = 65; j <= 90; j++)
        {
            cout << char(i) << " " << char(j) << '\n';
        }
        cout << "---------------------\n";
    }
    cout << "\n********************************\n";
}
void ShowMenue()
{
    cout << "*****************************\n";
    cout << "Please Select From the menue ? ";
    cout << "\n1) print Letters \n";
    cout << "2)Print Pyrmid of *\n";
    cout << "3) Print Numbers in pyrmids \n";
    cout << "4) Print Rotate Numbers pyrmids\n";
    cout << "5) print letters in pyrmids\n";
    cout << "6) print Nice Numbers pyrmids\n";
    cout << "*****************************\n";
    cout << "Enter Your choise ? \n";
    int choise;
    cin >> choise;
    switch (choise)
    {
    case 1:
        Print_A_to_Z_Double();
        break;
    case 2:
        Print_Pyrmids(10);
        break;
    case 3:
        Print_From1To10Pyrmids();
        break;
    case 4:
        Print_From1To10Pyrmids_Rotate();
        break;
    case 5:
        Print_A_to_Z_Pyrmids();
        break;
    case 6:
        Print_Numbers();
        break;
    default:
        cout << "Invalid  Inputs";
        break;
    }
}
