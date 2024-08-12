// John Greig
// Homework 7

#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

string CLS = "\033[2J\033[1;1H";
string Red = "\033[31;1m";
string Green = "\033[32;1m";
string Yellow = "\033[33;1m";
string Blue = "\033[34;1m";
string Purple = "\033[35;1m";
string Cyan = "\033[36;1m";
string White = "\033[37;1m";
string Default = "\033[0m"; // default gray color & reset background to black

string WhiteOnRed = "\033[41;1m";
string WhiteOnGreen = "\033[42;1m";
string WhiteOnYellow = "\033[43;1m";
string WhiteOnBlue = "\033[44;1m";
string WhiteOnPurple = "\033[45;1m";
string WhiteOnCyan = "\033[46;1m";

int main()
{
    srand(time(NULL));
    
    cout << Cyan << R"(
     _       _           _        
    | | ___ | |__  _ __ ( )___    
 _  | |/ _ \| '_ \| '_ \|// __|   
| |_| | (_) | | | | | | | \__ \   
 \___/ \___/|_| |_|_| |_| |___/   
__        __            _    ____                           
\ \      / /__  _ __ __| |  / ___| _   _  ___  ___ ___  ___ _ __ 
 \ \ /\ / / _ \| '__/ _` | | |  _ | | | |/ _ \/ __/ __|/ _ \ '__|
  \ V  V / (_) | | | (_| | | |_| || |_| |  __/\__ \__ \  __/ |   
   \_/\_/ \___/|_|  \__,_|  \____| \__,_|\___||___/___/\___|_|   
)" << Default <<  endl;

    cout << Cyan << "-----------------------------------------------------------------------------------------------" << Default << endl << endl;
    cout << Green << "Welcome!\n";
    cout << "In this game, your goal is to guess the secret phrase." << endl;
    cout << "You can guess one letter at a time. If the letter is in the" << endl;
    cout << "phrase, it will be revealed. If not, you will lose a life." << endl;
    cout << "You have 10 lives to guess the entire phrase." << endl;
    cout << "All letters must be entered in lower case." << endl;
    cout << "The theme is College and University!" << endl;
    cout << "Good luck!" << endl;
    cout << endl;
    cout << "Press Enter to begin" << Default << endl;
    cin.get();
    cout << CLS;

    // make array of phrases to choose from

    ifstream fin("words.txt");
	string Phrases[100];
    int phraseCount = 0;
    while (phraseCount < 100 && getline(fin, Phrases[phraseCount])) {
        phraseCount++;
    }
    // select a random phrase
    string secretphrase = Phrases[rand() % 100];
    string guessphrase = secretphrase;
    for (int i=0; i<guessphrase.size(); i++)
    {
        if (secretphrase[i] == ' ')
            guessphrase[i] = ' ';
        else
            guessphrase[i] = '.';
    }
    int BadGuesses = 0;
    string Letter;
    string LettersRemaining = "abcdefghijklmnopqrstuvwxyz";
    // start main game loop.
    while(guessphrase != secretphrase && BadGuesses < 10)
    {
        cout << CLS;
        //graphics
        cout << Cyan << R"( __    __ _           _   _      _   _            __    __              _ ___  ___ 
/ / /\ \ \ |__   __ _| |_( )__  | |_| |__   ___  / / /\ \ \___  _ __ __| / _ \/ _ \
\ \/  \/ / '_ \ / _` | __|/ __| | __| '_ \ / _ \ \ \/  \/ / _ \| '__/ _` \// /\// /
 \  /\  /| | | | (_| | |_ \__ \ | |_| | | |  __/  \  /\  / (_) | | | (_| | \/   \/ 
  \/  \/ |_| |_|\__,_|\__||___/  \__|_| |_|\___|   \/  \/ \___/|_|  \__,_| ()   () 
                                                                                  )" << Default <<  endl;
        
        // to show which letters are remaining to use for the user to see.
        
        cout << endl;
        cout << Green << LettersRemaining << Default << endl << endl;
        cout << guessphrase << endl;
        cout << "Enter your letter: ";
        cin >> Letter;
        int Found = LettersRemaining.find(Letter,0);
        if(Found > -1)
            LettersRemaining.replace(Found, 1, " ");
            
        // to find and replace correct guesses in the phrase else increment BadGuesses.
        
        Found = secretphrase.find(Letter,0);
        if (Found > secretphrase.size())
            {
            BadGuesses++;
            }
        else
            while(Found < secretphrase.size())
            {
                guessphrase.replace(Found, 1, Letter);
                Found = secretphrase.find(Letter, Found + 1);
            }
        
    } 
    // end main game loop
    cout << Green << "The Secret Phrase was: " << secretphrase << Default << endl << endl;
    if (guessphrase == secretphrase)
        {cout << Cyan << R"(____    ____  ______    __    __     ____    __    ____  __  .__   __.     __   __   __   __  
\   \  /   / /  __  \  |  |  |  |    \   \  /  \  /   / |  | |  \ |  |    |  | |  | |  | |  | 
 \   \/   / |  |  |  | |  |  |  |     \   \/    \/   /  |  | |   \|  |    |  | |  | |  | |  | 
  \_    _/  |  |  |  | |  |  |  |      \            /   |  | |  . `  |    |  | |  | |  | |  | 
    |  |    |  `--'  | |  `--'  |       \    /\    /    |  | |  |\   |    |__| |__| |__| |__| 
    |__|     \______/   \______/         \__/  \__/     |__| |__| \__|    (__) (__) (__) (__) )" << Default << endl;
        }

    else
        cout << Red << R"(____    ____  ______    __    __      __        ______        _______. _______              
\   \  /   / /  __  \  |  |  |  |    |  |      /  __  \      /       ||   ____|             
 \   \/   / |  |  |  | |  |  |  |    |  |     |  |  |  |    |   (----`|  |__                
  \_    _/  |  |  |  | |  |  |  |    |  |     |  |  |  |     \   \    |   __|               
    |  |    |  `--'  | |  `--'  |    |  `----.|  `--'  | .----)   |   |  |____     __ __ __ 
    |__|     \______/   \______/     |_______| \______/  |_______/    |_______|   (__|__|__))" << Default << endl;
    return 0;
}