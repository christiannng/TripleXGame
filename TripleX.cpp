#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Print welcome messages to the termial
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << "Enter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    //Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print out sum and product
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "\n+ The code add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum)
    {
        std::cout << "\n***  Well done agent! You have extracted a file! Keep going! ***";
        return true;
    } 
    else
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //Create new random sequence based on time of day

    int LevelDifficulty = 1;
    int MaxDifficulty = 10;

    while(LevelDifficulty <= MaxDifficulty) //Loop the game until all levels complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();//Clear any errors
        std::cin.ignore();//Discard the buffer

        if(bLevelComplete) 
        {
            ++LevelDifficulty;
        }
    }
    
    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}