#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
    const int MAX_WRONG = 8;
    vector<string> words;
    vector<string> hangman = {
        "___________",
        "|/",
        "|",
        "|",
        "|",
        "|",
        "|",
        "|",
        "|____________ "
    };
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
    srand(time(0));
    random_shuffle(words.begin(), words.end());

    const string THE_WORD = words[0];
    int wrong = 0;
    int n;
    string soFar(THE_WORD.size(), '-');
    string used = "";
    cout << "Welcome to Hangman. Good luck!\n";

    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)){
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << "\n";
        cout << "\nSo far, the word is:\n" << soFar;
        n = 10;
        for (string s : hangman){
            for (int i = 0; i < n; i++) cout << " ";
            cout << s << "\n";
            n = soFar.size() + 10;
        }

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess);

        while (used.find(guess) != string::npos){
            cout << "\nYou've already guessed " << guess << "\n";
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        used += guess;

        if (THE_WORD.find(guess) != string::npos){
            cout << "That's right! " << guess << " is in the word.\n";
            for (int i = 0; i < THE_WORD.size(); i++){
                if (THE_WORD[i] == guess) soFar[i] = guess;
            }
        } else {
            wrong++;
            cout << "Sorry. " << guess << " isn't in the word.\n";
            switch (wrong){
                case 1:
                    hangman[1] = "|/        |";
                    break;
                case 2:
                    hangman[1] = "|/       _|_";
                    hangman[2] = "|       |___|";
                    break;
                case 3:
                    hangman[3] = "|         |";
                    break;
                case 4:
                    hangman[4] = "|        /";
                    break;
                case 5:
                    hangman[4] = "|        / \\";
                    break;
                case 6:
                    hangman[4] = "|        /|\\";
                    hangman[5] = "|         |";
                    hangman[6] = "|         |";
                    break;
                case 7:
                    hangman[7] = "|          \\";
                    break;
                case 8:
                    hangman[7] = "|        / \\";
                    break;
            }
        }
    }

    if (wrong == MAX_WRONG){
        for (string s : hangman){
            for (int i = 0; i < n; i++) cout << " ";
            cout << s << "\n";
        }
        cout << "\nYou've been hanged!";
    }
    else cout << "\nYou guessed it!";

    cout << "\nThe word was " << THE_WORD << "\n";

    return 0;
}
