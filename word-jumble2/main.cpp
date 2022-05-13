#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdio>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    setlocale(LC_ALL, "rus");

    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    string WORDS[NUM_WORDS][NUM_FIELDS];
    string guess;
    int k = 0;
    bool flag1 = 0, flag2 = 1;

    for (int j, i = 0; i < NUM_WORDS; i++){
        for (j = 0; j < NUM_FIELDS; j++){
            if (WORDS[i][j] == ""){
                string s;
                fin >> s;
                WORDS[i][j] = s;
            }
        }
        if (WORDS[i][j - 1] != "") k++;
    }

    cout << "\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n";

    while ((guess != "quit") && (k != 0)){

        while (flag1 && flag2){
            for (int j, i = 0; i < NUM_WORDS; i++){
                bool flag = 0;
                for (j = 0; j < NUM_FIELDS; j++){
                    if (WORDS[i][j] == ""){
                        string s;
                        fin >> s;
                        WORDS[i][j] = s;
                        flag = 1;
                    }
                }
                if ((WORDS[i][j - 1] != "") && flag) k++;
                if ((WORDS[i][j - 1] == "") && flag){
                    flag1 = 0;
                    flag2 = 0;
                    break;
                }
            }
        }

        bool flag = 0;
        int choice;

        while (!flag){
            srand(time(0));
            choice = rand() % NUM_WORDS;
            if (WORDS[choice][WORD] != "") flag = 1;
        }

        string theWord = WORDS[choice][WORD];
        string theHint = WORDS[choice][HINT];

        WORDS[choice][WORD] = "";
        WORDS[choice][HINT] = "";
        k--;
        flag1 = 1;

        string jumble = theWord;
        int length = jumble.size();

        while (jumble == theWord) {
            for (int i = 0; i < length; i++){
                int index1 = (rand() % length);
                int index2 = rand() % length;
                char temp = jumble[index1];
                jumble[index1] = jumble[index2];
                jumble[index2] = temp;
            }
        }

        cout << "\n\nThe jumble is: " << jumble;
        cout << "\n\nYour guess: ";
        cin >> guess;

        while ((guess != theWord) && (guess != "quit")){
            if (guess == "hint") cout << theHint;
            else cout << "Sorry. that's not it.";
            cout << "\n\nYour guess: ";
            cin >> guess;
        }

        if (guess == theWord) cout << "\nThat's it! You guessed it!\n";
        else break;
    }
    cout << "\nThanks for playing.\n";

    return 0;
}
