#include <iostream>
using namespace std;

void PrintWordsFromAAAtoZZZ()
{
    string word = "";
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);
                cout << word << endl;
                word = "";
            }
        }
    }
}

int main()
{
    PrintWordsFromAAAtoZZZ();
    return 0;
}