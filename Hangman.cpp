#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;



int main()
{

    // setting the words to be guessed from
    string words[] = { "house", "thief", "guitar" };


    //random number 0 to 2
    srand(time(NULL));
    int randomNumber;
    randomNumber = (rand() % 3);


    //setting word
    string wordGuess = words[randomNumber];
    //cout << wordGuess << "\n";


    // getting word length 
    int wordLength = wordGuess.size();
    //cout << wordLength;
    string word_ = "";
    for (int i = 0; i < wordLength; i++) {
        word_ = word_ + "_ ";
    }
    //cout << word_ << "\n";


    //Visuals
    string man[6] = { 
        "    ____\n    |   |\n        |\n        |\n        |\n        | \n",
        "    ____\n    |   |\n    O   |\n        |\n        |\n        |\n",
        "    ____\n    |   |\n    O   |\n    |   |\n        |\n        |\n",
        "    ____\n    |   |\n    O   |\n   /|   |\n        |\n        |\n",
        "    ____\n    |   |\n    O   |\n   /|\\  |\n        |\n        |\n",
        "    ____\n    |   |\n    O   |\n   /|\\  |\n    ^   |\n        |\n" };
    //cout << man[3];
    //cout << "\n" << man0 << man1 << man2 << man3 << man4 << man5;


    //Game Introduction
    cout << "\n\n\n"; //blank
    for (int i = 0; i < 50; i++) { cout << "_";} //dash line
    cout << "\n\n"; //blank
    cout << " Welcome to Hangman. Your word is below. \n"
        << "   " << word_ << "\n\n" << man[0]
        << "\n\n Type 1 letter to guess individual and more than 1 to guess multiple.\n";

    // First Guess
    char guess;
    int correctGuess = 0, 
        incorrectGuess = 0,
        allowedGuess = 5,
        remaininGuess = 5;
    bool correct = 0;

    while (correctGuess != wordLength) {
        cin >> guess;
        correct = 0;
        for (int j = 0; j < wordLength; j++) {
            //cout << guess << wordGuess[j];
            if (guess == wordGuess[j]) {
                //to do at each correct letter
                correctGuess++;
                correct = 1;
                //cout << "correct2";

                for (int k = 0; k < wordLength; k++) {
                    if (guess == wordGuess[k]) {
                        word_[k*2] = guess;
                    }
                }
                wordGuess[j] = '-';
                
            }
            
            else if (j == wordLength - 1) {
                if (correct == 1) {
                    // end of check 1 or more is current
                    cout << man[incorrectGuess] << "\n\n" << "Correct guess\n" << "\n";
                    cout << word_ << "\n";

                }
                else {
                    // end of check was incorrect guess
                    remaininGuess--;
                    incorrectGuess++;
                    cout << man[incorrectGuess] << "\n\n" << "Incorrect guess. Your have " << remaininGuess << " guesses left.\n";
                    cout << word_ << "\n";
                    if (incorrectGuess == allowedGuess) {
                        // if reached max guessed
                        cout << "You Lost";
                        return 0;
                    }

                }

            }

        }


    }
    cout << word_ << "\n" << "You Win :)";



    return 0;
}
