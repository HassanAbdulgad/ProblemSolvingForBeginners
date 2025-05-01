

// Project 1 Solution Using C++

#include <iostream>
#include <cstdlib>
using namespace std;

enum enGameChoice
{
    Stone = 1,
    Paper = 2,
    Scissors = 3
};
enum enWinner
{
    Player1 = 1,
    Computer = 2,
    Draw = 3
};
struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResults
{
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short Computer2WinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = {"Player1", "Computer", "No Winner"};
    return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
    {
        return enWinner::Draw;
    }
    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
        {
            return enWinner::Computer;
        }
        break;
    }
    // if you reach here then player1 is the winner.
    return enWinner::Player1;
}

string ChoiceName(enGameChoice Choice)
{
    string arrGameChoices[3] = {"Stone", "Paper", "Scissors"};
    return arrGameChoices[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        system("color 2F"); // turn screen to Green
        break;
    case enWinner::Computer:
        system("color 4F"); // turn screen to Red
        cout << "\a";
        break;
    default:
        system("color 6F"); // turn screen to Yellow
        break;
    }
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n____________Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner : [" << RoundInfo.WinnerName << "] \n";
    cout << "__________________________________\n"
         << endl;
    SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.Computer2WinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(Player1WinTimes,
                                           ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);
    return GameResults;
}
enGameChoice ReadPlayer1Choice()
{
    short Choice = 1;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enGameChoice)Choice;
}
enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
        // Increase win/Draw counters
        if (RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;
        PrintRoundResults(RoundInfo);
    }
    return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}
string Tabs(short NumberOfTabs)
{
    string t = "";
    for (int i = 1; i < NumberOfTabs; i++)
    {
        t = t + "\t";
        cout << t;
    }
    return t;
}

void ShowGameOverScreen()
{
    cout << Tabs(2) << "__________________________________________________________\n\n";
    cout << Tabs(2) << " +++ G a m e O v e r +++\n";
    cout << Tabs(2) << "__________________________________________________________\n\n";
}
void ShowFinalGameResults(stGameResults GameResults)
{
    cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n";
    cout << Tabs(2) << "Game Rounds : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player1 won times : " << GameResults.Player1WinTimes << endl;
    cout << Tabs(2) << "Computer won times : " << GameResults.Computer2WinTimes << endl;
    cout << Tabs(2) << "Draw times : " << GameResults.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner : " << GameResults.WinnerName << endl;
    cout << Tabs(2) << "___________________________________________________________\n";
    SetWinnerScreenColor(GameResults.GameWinner);
}
short ReadHowManyRounds()
{
    short GameRounds = 1;
    do
    {
        cout << "How Many Rounds 1 to 10 ? \n";
        cin >> GameRounds;
    } while (GameRounds < 1 || GameRounds > 10);
    return GameRounds;
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}
void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);
        cout << endl
             << Tabs(3) << "Do you want to play again? Y/N? ";

        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    StartGame();
    return 0;
}
enum enGameChoice
{
    Stone = 1,
    Paper = 2,
    Scissors = 3
};
enum enWinner
{
    Player1 = 1,
    Computer = 2,
    Draw = 3
};
struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};
struct stGameResults
{
    short GameRounds;
    short Player1WinTimes;
    short ComputerWinTimes;
    short DrawTimes;
    enWinner Winner;
    string WinnerName = " ";
};

short RandomNumber(short From, short To)
{
    short randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enGameChoice ReadPlayer1Choice()
{
    short Player1 = 0;
    do
    {
        cout << "Enter your choice : [1]:Stone , [2]:Paper, [3]:Scissors ? \n";
        cin >> Player1;
    } while (Player1 < 1 || Player1 > 3);
    return (enGameChoice)Player1;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

short ReadHowManyRounds()
{
    short RoundNumber = 0;
    do
    {
        cout << "How many rounds 1 to 10 ? ";
        cin >> RoundNumber;
    } while (RoundNumber < 1 || RoundNumber > 10);
    return RoundNumber;
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        system("color 2F"); // turn screen to green
        break;
    case enWinner::Computer:
        system("color 4F"); // turn screen to  Red
        cout << "\a";       // make ring
        break;
    default:
        system("color 6F"); // turn screen to Yellow
        break;
    }
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
    {
        return enWinner::Draw;
    }

    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
        {
            return enWinner::Computer;
        }
        break;
    }

    return enWinner::Player1;
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = {"Player", "Computer", "No Winner"};
    return arrWinnerName[Winner - 1];
}

string ChoiceName(enGameChoice choice)
{
    string arrGameChoices[3] = {"stone", "paper", "scissor"};
    return arrGameChoices[choice - 1];
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
    {
        return enWinner::Player1;
    }
    else if (Player1WinTimes < ComputerWinTimes)
    {
        return enWinner::Computer;
    }
    else
        return enWinner::Draw;
}

stGameResults FillGameResultS(short GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.Winner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.Winner);
    return GameResults;
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n________Round [" << RoundInfo.RoundNumber << "]____________\n\n";
    cout << "Player 1 choice : " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner : [" << RoundInfo.WinnerName << "]\n";
    cout << "__________________________________________________\n"
         << endl;
    SetWinnerScreenColor(RoundInfo.Winner);
}

stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
    for (short Round = 1; Round <= HowManyRounds; Round++)
    {

        cout << "Round[ " << Round << "] begins: \n";
        RoundInfo.RoundNumber = Round;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
        if (RoundInfo.Winner == enWinner::Player1)
        {
            Player1WinTimes++;
        }
        else if (RoundInfo.Winner == enWinner::Computer)
        {
            ComputerWinTimes++;
        }
        else
            DrawTimes++;

        PrintRoundResults(RoundInfo);
    }

    return FillGameResultS(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
    string t = "";
    for (short i = 1; i < NumberOfTabs; i++)
    {
        t = t + "\t";
        cout << t;
    }
    return t;
}

void SetScreen()
{
    system("cls");
    system("color 0F");
}

void ShowGameOverInTheScreen()
{
    cout << Tabs(2) << "                          +++ Game  Over +++                    " << '\n';
    cout << Tabs(2) << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n";
    cout << Tabs(2) << "___________________________________________________________________\n";
}
void ShowFinalGameResults(stGameResults GameResults)
{
    cout << Tabs(2) << "________________ Result________________________\n"
         << endl;
    cout << Tabs(2) << "Game Rounds            :" << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player1 Won Times      :" << GameResults.Player1WinTimes << endl;
    cout << Tabs(2) << "Computer Won Times     :" << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw Times             :" << GameResults.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner           :" << GameResults.WinnerName << endl;
    cout << "_____________________________________________________________\n";
    SetWinnerScreenColor(GameResults.Winner);
}

void StartGame()
{
    char playAgain = 'Y';
    do
    {
        SetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverInTheScreen();
        ShowFinalGameResults(GameResults);

        cout << Tabs(2) << "Do you want to play again? Y/N" << endl;
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}