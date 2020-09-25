#include <iostream>
#include <ctime>

void PrintIntroduction (int Difficulty)
{
    std::cout << "   /|                                                        /|\n";
    std::cout << "  |  |                                                      |  |\n";
    std::cout << " /----|                        The                         /----|\n";
    std::cout << "[______]                   Faerie Realm                   [______]\n";
    std::cout << " |    |         _____                        _____         |    |\n";
    std::cout << " |[]  |        [     ]                      [     ]        |  []|\n";
    std::cout << " |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    |\n";
    std::cout << " |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    |\n";
    std::cout << " |             |     |/'    ____..____    '||     |             |\n";
    std::cout << "  |  []        |     |    /'    ||    '|    |     |        []  /\n";
    std::cout << "   |      []   |     |   |o     ||     o|   |     |  []       |\n";
    std::cout << "   |           |  _  |   |     _||_     |   |  _  |           |\n";
    std::cout << "   |   []      | (_) |   |    (_||_)    |   | (_) |       []  |\n";
    std::cout << "   |           |     |   |     (||)     |   |     |           |\n";
    std::cout << "   |           |     |   |      ||      |   |     |           |\n";
    std::cout << " /''           |     |   |o     ||     o|   |     |           ''|\n";
    std::cout << "[_____________[_______]--'------''------'--[_______]_____________]\n";
    std::cout << "You wake up in the faerie realm, you find a well-fortified fortress in front of you...\n";
    std::cout << "To gain entrance you have to prove your worth by solving the mathematical riddles of the faerie...\n";
    std::cout << "You approach a level " << Difficulty << " gate...\n\n"; 
    
}

bool PlayGame (int Difficulty)
{
    PrintIntroduction (Difficulty);
    //CREATES THE RIDDLE'S ENTRIES
    int EntryA = rand() % (Difficulty+3) + 1 ;  int EntryB = rand() % (Difficulty+3) + 1 ;  int EntryC = rand() % (Difficulty+3) + 1 ;

    //CALCULATES THE RIDDLE
    int EntrySum = EntryA + EntryB + EntryC;
    int EntryProduct = EntryA * EntryB * EntryC;

    //OUTPUTS THE RIDDLE
    std::cout << "\nWhat 3 numbers would satisfy the upcoming conditions : ..." << std::endl;
    std::cout << " -They add up to be : " << EntrySum << std::endl;
    std::cout << " -But multiply to be : " << EntryProduct << std::endl;

    //TAKES THE PLAYER'S ENTRIES
    int GuessA, GuessB, GuessC;
    std::cout<< "\n\nMy answer is : ";
    std::cin >> GuessA >> GuessB >> GuessC;

    //CALCULATES THE RESULTS
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //OUTPUTS THE PLAYER'S RESULTS
    std::cout << " -Your sum : " << GuessSum << std::endl;
    std::cout << " -Your product : " << GuessProduct << std::endl;

    //CHECKS THE RESULTS
    if (GuessSum == EntrySum  &&  GuessProduct == EntryProduct)
    {
        std::cout << "\n            <<<Thee myght gayn entrance, fellow elf.>>>\n\n";
        return true;
    }
    else
    {
        std::cout << "\n                    <<<Thou art not worthy!>>>\n\n";           
        return false;
    }
}

int main ()
{
    srand(time(NULL)); // CREATES RANDOM SEQUENCE BASED ON THE TIME OF THE DAY
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // LOOPS UNTIL THE FINAL LEVEL IS DONE
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // CLEARS THE ERRORS
        std::cin.ignore(); // DISCARDS THE BUFFER

        if (bLevelComplete) // INCREASES THE DIFFICULTY AFTER EACH LEVEL SUCCESS
        {
            ++LevelDifficulty;
        }
        else
        {
            if (LevelDifficulty>1)
            {
               --LevelDifficulty;
            }
        }
    }
    std::cout << "             <<<We doth bid thee wilcuma, kinsman.>>>\n\n";
    std::cin.get();
    return 0;   
}