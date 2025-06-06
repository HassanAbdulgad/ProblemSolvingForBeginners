#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillArrayWithRandomNumbers(int arr[], int &arrLength)
{
    cout << "Please Enter Number of elements ? \n";
    cin >> arrLength;

    for (int k = 0; k < arrLength; k++)
    {
        arr[k] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[], int arrLength)
{
    for (int m = 0; m < arrLength; m++)
    {
        cout << arr[m] << " ";
    }
}

int SumOfArray(int arr[], int arrLength)
{
    int sum = 0;
    for (int i = 0; i < arrLength; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "Array Elements : ";
    PrintArray(arr, arrLength);
    cout << "\nThe Sum of Numbers In The Array: " << SumOfArray(arr, arrLength) << endl;
    return 0;
}