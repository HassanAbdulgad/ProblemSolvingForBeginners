#include<iostream>
using namespace std;

// Global variables to store personal information
string Name, City, Country;
int Age, x, y;
float Monthly_Salary;
string Gender; // Changed to string to allow more options
bool isMarried;
short int choose = 0;

// Function to read two numbers from the user
void ReadNumbers() {
    cout << "Please Enter the first number :" << '\n';
    cin >> x;

    cout << "Please Enter the Second number :" << '\n';
    cin >> y;

    
    // Input validation to handle division by zero
    if (y == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        exit(1); // Terminate the program
    }
}

// Function to read personal information from the user
void ReadPersonInfo() {
    cout << "Please Enter Your name :" << '\n';
    cin >> Name;

    cout << "Please Enter Your City :" << '\n';
    cin >> City;

    cout << "Please Enter Your Country :" << '\n';
    cin >> Country;

    cout << "Please Enter Your Age :" << '\n';
    cin >> Age;

    cout << "Please Enter Your Monthly Salary:" << '\n';
    cin >> Monthly_Salary;

    cout << "Please Enter Your Gender (male/female/other):" << '\n';
    cin >> Gender;

    cout << "Are You Married? (1 for yes, 0 for no)" << '\n';
    cin >> isMarried;
}

// Function to print personal information
void PrintPersonInfo(string Name, string City, string Country, int Age, float Monthly_Salary, string Gender, bool isMarried) {
    cout << "\t****************************\n";
    cout << "\tName : " << Name << '\n';
    cout << "\tAge : " << Age << '\n';
    cout << "\tCity : " << City << '\n';
    cout << "\tCountry : " << Country << '\n';
    cout << "\tMonthly Salary : " << Monthly_Salary << '\n';
    cout << "\tYearly Salary : " << 12 * Monthly_Salary << '\n'; // Assuming 12 months in a year
    cout << "\tGender : " << Gender << '\n';
    cout << "\tMarried : " << (isMarried ? "Yes" : "No") << '\n'; // Print a descriptive message for marital status
    cout << "\t****************************" << endl;
}

// Function to print arithmetic calculations of two numbers
void PrintCalOF2Nums(int x, int y) {
    cout << "\t" << x << " + " << y << " = " << x + y << '\n';
    cout << "\t" << x << " - " << y << " = " << x - y << '\n';
    cout << "\t" << x << " * " << y << " = " << x * y << '\n';
    cout << "\t" << x << " / " << y << " = " << static_cast<float>(x) / y << '\n'; // Ensure floating-point division
    cout << "\t" << x << " % " << y << " = " << x % y << '\n';
}

// Function to print age after 5 years
void PrintAgeNotification() {
    cout <<"\t";
    short AGE ; cin >> AGE;
    short int YourAgeAfter5Years = AGE + 5;
    cout << "\tAfter 5 Years Your Age Will Be " << YourAgeAfter5Years << " Years Old";
}

int main() {
    
    cout << "\tChoose what you want to do from this menu\n";
    cout << "\t1) Do You want to do operations on two numbers?\n";
    cout << "\t2) Do You want to make information form?\n";
    cout << "\t3) Do You want to See Your Age After 5 Years?\n\t";
    cin >> choose;

    switch (choose) {
    case 1:
        cout << "\tOption 1 selected" << '\n';
        ReadNumbers();
        PrintCalOF2Nums(x, y);
        break;
    case 2:
        cout << "\tOption 2 selected" << '\n';
        ReadPersonInfo();
        PrintPersonInfo(Name, City, Country, Age, Monthly_Salary, Gender, isMarried);
        break;
    case 3:
        cout << "\tOption 3 selected" << endl;
        cout << "\tPlease Enter Your Current Age ?" << '\n';
        PrintAgeNotification();
        break;
    default:
        cout << "\tInvalid Number!";
        break;
    }

    return 0;
}
