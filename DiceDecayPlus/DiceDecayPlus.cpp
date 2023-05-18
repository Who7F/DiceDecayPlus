// DiceDecay.cpp : This file contains the 'main' function. Program execution begins and ends there.
// No notes as of yet
// 1000 by 1000 by 1000
//Time difference = 625406228[Ás]
//Time difference = 625406228400[ns]

#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>
#include <string>

class diceDecay {
private:
    int sidesDice;
    int numberDiceStart;
    int repeats;
    std::string fileNmae;

    int diceRemove(int numberDice)
    {
        int removeDice = 0;
        for (int i = 0; i < numberDice; i++)
        {

            if (rand() % sidesDice == 0)
            {
                removeDice++;
            }
        }
        return removeDice;
    }

    void iteration()
    {
        int numberDice = numberDiceStart;
        while (numberDice > 0) {
            numberDice -= diceRemove(numberDice);
            std::cout << numberDice;
            if (numberDice > 0)
            {
                std::cout << ",";
            }


        }
    }

public:
    diceDecay(__int16 s, __int16 n, __int16 r, std::string f) : sidesDice(s), numberDiceStart(n), repeats(r), fileNmae(f)
    {

    }
    void test()
    {
        std::cout << fileNmae;
    }
    

    void repeater()
    {
        
        std::cout << "[";
        for (int i = 0; i < repeats; i++)
        {
            std::cout << "[";
            iteration();

            if (i == repeats - 1)
            {
                std::cout << "]";
            }
            else
            {
                std::cout << "],";
            }
        }
        std::cout << "]\n";
        
    }
};

bool checkInterger(std::string input)
{
    if (input.length() == 0) {
        std::cout << "No value enttered\n";
        return false;
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
        {
            std::cout << "Needs to be int\n";
            return false;
        }
    }
    return true;
}


__int16 inputInt(std::string textBloc)
{
    std::string input;
    while (true)
    {
        std::cout << textBloc;

        std::cin >> input;
        if (checkInterger(input) == true)
        {
            std::cout << "Accepted value\n";
            break;
        }
        std::cout << ".................\n";
    }
    return std::stoi(input);
}

int inputInti(std::string textBloc)
{


    int myReturn = 0;
    std::cout << textBloc;
    std::cin >> myReturn;
    if (std::cin.fail())
    {
        std::cin.clear(); // reset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << myReturn;
    return 1;
}

int main()
{
    __int16 numberDice = inputInt("Number of dice to be rolled :");
    __int16 sidesDice = inputInt("Numer of sides on the dice :");
    __int16 repeats = inputInt("Repeats :");

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    srand(time(NULL));

    diceDecay ii(sidesDice, numberDice, repeats, "myfile");
    
    std::ofstream myFile("filename.txt");
    if (myFile.is_open()) 
    {
        std::cout << "Woop Woop";
        myFile << "It's going to be fun";
        ii.repeater();
    }
    else 
    {
        std::cout << "ERROR!\nFile is not open\n";
    }
    
    ii.repeater();

    myFile.close();

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    std::string textBloc;
    std::cin >> textBloc;
    

}

