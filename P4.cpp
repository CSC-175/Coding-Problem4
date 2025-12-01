#include <iostream>
#include <random>
using namespace std;

bool  duplicate(int t, int arr[], int length);

void getPicks(int picks[]) // do not change the code in this function
{
    bool error;
    int temp=0;

    for (int i=0;i<10;i++)
    {
        error = false;
        cout << "Enter your pick #" << i+1 <<": ";
        cin >> temp;
        if (cin.fail())
        {
            error = true;
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Invalid data input! Try again. ";
        }
        else if (temp > 80)
        {
            error = true;
            cout << temp << " is out of range! Try again. ";
        }
        else if (duplicate(temp,picks,10))
        {
            error = true;
            cout << temp << " was already picked! Try again. ";
        }
        if (error)
            i--;
        else
            picks[i]= temp;
    }
}

void generateKenoNumbers(int winners[]) // do not change the code in this function
{
    // Generate Keno numbers
    std::random_device rd;
    std::mt19937 gen(rd());
    gen.seed(0);
    std::uniform_int_distribution<int> distrib(1, 80);
    int temp;

    for (int j=0; j<20; j++)
    {
        temp = distrib(gen);
        while (duplicate(temp,winners,20))
        {
            temp = distrib(gen);
        }
        winners[j]=temp;
    }
}

bool  duplicate(int t, int arr[], int length){ // tests to see if parameter t is present in array
    // implementation of duplicate function goes here
}

void sortArray(int arr[], int length) {  // sort array in ascending order
    // implementation of sortArray function goes here

}

void clearArray(int arr[], int length) { // reset each array element to 0
    // implementation of clearArray function goes here

}

int findMatches(int picks[],int winners[],int matches[]){ // assign values that match between pick and winners to matches
    // implementation of findMatches function goes here

}

void printArr(int arr[],int length){ // print the array passed
    // implementation of printArr function goes here


}
