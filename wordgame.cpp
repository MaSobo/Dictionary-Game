#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>


std::vector<std::string> readDic()
{
    std::string inputFile = "words.txt";
    std::vector<std::string> words = {};

    std::ifstream file(inputFile);

    for(std::string word; file >> word; )
        words.emplace_back(word);
    
    return words;

}


std::string randomLetterString(int howManyLeters)
{   
    std::string letters = "abcdefghijklmnopqrstuvwxyzaaaaaeeeeiiiiooo";

    std::mt19937 generator(std::time(nullptr));

    std::shuffle(letters.begin(), letters.end(), generator);
    
    std::string tempLetters="";
    for (int i=0; i<howManyLeters; ++i)
        {
            tempLetters.push_back(letters[i]);
        }
    
    return tempLetters;
}

bool checkIfWordInDic(std::string word)
{
  std::vector<std::string> words;
  
  words=readDic();
   
  if (std::find (words.begin(), words.end(), word) != words.end())
    return true;
  else
    return false;
}

bool checkIfWordFromLetters(std::string word, std::string letters)
{
    int a;
    for(int i=0; i<word.size(); ++i)
    {
        a=letters.find(word[i]);
        if (a == std::string::npos)
            return false;
        else
        {
            continue;
        }
        
    }
    return true;
}

int main()
{
    std::vector<std::string> Guesedwords;

    int numberOfLetters;

    std::cout<<"How many letters would you like to draw?";
    std::cin>>numberOfLetters;
  
    std::string letters = randomLetterString(numberOfLetters);
    std::string guess;

    int HowManyTries = 10;

    while(HowManyTries > 0)
    {   std::cout<<letters;
        std::cout<<std::endl;
        std::cout<<"Input a word created from the letters: ";
        std::cin>>guess;
        std::cout<<std::endl;
    
        if(checkIfWordFromLetters(guess, letters))
        {
            if (checkIfWordInDic(guess))
            {
                if (std::find (Guesedwords.begin(), Guesedwords.end(), guess) != Guesedwords.end())
                {
                    std::cout<<"You already have this word!";
                }
                else
                {
                    Guesedwords.emplace_back(guess);
                    std::cout<<"You found "<<Guesedwords.size()<<" words! \n"; 
                    for(std::string n : Guesedwords)
                    std::cout<<n<<" "; 
                    std::cout<<std::endl;
                }
                         
            }
            else
            {
                std::cout<<"wrong \n";
            }
        }
        else
        {
            std::cout<<"This word is made of letters different than the chosen ones. \n";
        }
        
     --HowManyTries;
     std::cout<<"You have "<<HowManyTries<<" tries left \n";

    }
    
  




    return 0;

}