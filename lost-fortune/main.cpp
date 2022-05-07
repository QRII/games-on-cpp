#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;


int main()
{
    const int GOLD_PIECES = 900;
    int adventurers, killed, survivors;
    string leader;

    cout << "Welcome to Lost Fortune\n\n";
    cout << "Please enter the following for your personalized adventure\n";
    cout << "Enter a number: ";
    cin >> adventurers;
    cout << "Enter a number, smaller than the first: ";
    cin >> killed;
    survivors = adventurers - killed;
    cout << "Enter your leader name: ";
    cin >> leader;

    //сюжет
    cout << "\nA brave group of " << adventurers << " set out on a quest ";
    cout << "-- in search of the lost treasure of the Ancient Tribes. ";
    cout << "The group was led by that legendary leader. " << leader << ".\n";
    cout << "\nAlong the way, a band of marauding rogue ambushed the party. ";
    cout << ". and the rogues were defeated, but at a cost. ";
    cout << "of the adventurers. " << killed << " were vanquished. ";
    cout << "leaving just " << survivors << " in the group.\n";
    cout << "\nThe party was about to give up all hope. ";
    cout << "But while laying the deceased to rest. ";
    cout << "they stumbled upon the buried fortune. ";
    cout << "So the adventurers split " << GOLD_PIECES << " gold pieces.";
    cout << leader << " help on to the extra " << (GOLD_PIECES % survivors);
    cout << " pieces to keep things fair of course.\n";

    return 0;
}
