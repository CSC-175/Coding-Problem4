#include <iostream>
#include "./P4.cpp"

using namespace std;

int main()
{
    int matchCount;
    char again;
    do
    {
    cout << "\nLet's Play Keno!\n\n";
    cout << "To play Keno, select 10 unique (no repeats) numbers in the range of 1-80.\n\n";
    int picks[10]={0,0,0,0,0,0,0,0,0,0};  // initialize array holding player choices
    int winners[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // initialize array holding Keno numbers generated
    int matches[10]={0,0,0,0,0,0,0,0,0,0}; // initialize array holding matching numbers
    getPicks(picks);  // call function to collect players choices
    generateKenoNumbers(winners); // call function to generate Keno numbers

    // display results
    cout <<"\n----------------------------------Results----------------------------------\n";
    cout << "Keno Numbers: ";
    sortArray(winners,20); // call function to sort in ascending order the winners array
    printArr(winners,20); // call function to print winners array
    cout << "Player Picks: ";
    sortArray(picks,10); // call function to sort in ascending order the picks array
    printArr(picks,10); // call function to print picks array
    matchCount = findMatches(picks,winners,matches); // call function to find the matches between picks and winners arrays
    cout << "You matched: ";
    printArr(matches, 10); // call function to print matches array

    // print prizes message
    if (matchCount > 0) {
        cout<<"Matching " << matchCount << " of 20 numbers wins ";
        switch (matchCount){
            case 10:
                cout<<"the GRAND PRIZE of $250,000";
                break;
            case 9:
                cout << "$2,500";
                break;
            case 8:
                cout<<"$250";
                break;
            case 7:
                cout<<"$50";
                break;
            case 6:
                cout<<"$10";
                break;
            case 5:
                cout<<"$5";
                break;
            default:
                cout<<"$0. Sorry, better luck next time.";
        }
    }
    else {
        cout << "\nSorry, you didn't have any matches.";
    }
    // prize message end
    cout << "\n\nPlay another round? (y/n): ";
    cin >> again;
    clearArray(winners,20); // call function to reset winners array to hold zeros
    clearArray(picks,10); // call function to reset picks array to hold zeros
    clearArray(matches,10); // call function to reset matches array to hold zeros
} while (tolower(again) == 'y');
std::cout << "\nTHANKS FOR PLAYING!!\n";


    return 0;
}



