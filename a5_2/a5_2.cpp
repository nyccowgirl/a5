/*
 Trang Hoang
 CS110B
 Dave Harden
 10/3/20
 a5_2.cpp
 
 Assignment 5.2
 
 Program records high-score data for a fictitious game. The program asks user to enter the
 number of scores and the respective indicated number of names and scores. It then prints
 the names and scores sorted by score in descending order.
 
 Created by nyccowgirl on 10/3/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include <iostream>
#include <string>
#include <utility>
using namespace std;


void readData(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
int idxOfHigh(const int scores[], int start, int size);
void displayData(const string names[], const int scores[], int size);


int main(int argc, const char * argv[]) {
    string *names;                          // To dynamically allocate array for names
    int *scores;                            // To dynamically allocate array for scores
    int numScores;                          // To hold number of scores
    
    cout << "How many scores will you enter?: ";
    cin >> numScores;
    names = new string[numScores];
    scores = new int[numScores];
    readData(names, scores, numScores);
    sortData(names, scores, numScores);
    displayData(names, scores, numScores);
    
    delete [] names;
    delete [] scores;
    names = nullptr;
    scores = nullptr;
    return 0;
}






/*
 Definition of function readData. The function passes in two arrays, names and scores, and
 the size of the arrays. It gets names and scores from the user to store into the respective
 arrays. It assumes that user inputs valid type (e.g., string for name and integer for
 score).
*/

void readData(string names[], int scores[], int size) {
    for (int x = 0; x < size; x++) {
        cin.ignore();
        cout << "Enter the name for score #" << (x + 1) << ": ";

        do {
            getline(cin, names[x]);
        } while (names[x] == "");
        
        cout << "Enter the score for score #" << (x + 1) << ": ";
        cin >> scores[x];
    }
}






/*
 Definition of function sortData. The function passes in two arrays, names and scores, and
 the size of the arrays. It sorts the arrays based on scores in descending order by calling
 the idxOfHigh function to determine the index of the higher score to swap in the scores
 and names array.
 */

void sortData(string names[], int scores[], int size) {
    int highIdx;                            // To hold index of highest remaining number
    
    for (int x = 0; x < (size - 1); x++) {
        highIdx = idxOfHigh(scores, x, size);
        swap(scores[highIdx], scores[x]);
        swap(names[highIdx], names[x]);
    }
}






/*
 Definition of function idxOfHigh. The function passes in the scores array, a starting
 index and size of the array. It compares the remaining scores in the scores array from the
 starting index and returns the index of the highest score.
 */

int idxOfHigh(const int scores[], int start, int size) {
    int target = start;                     // To define initial starting index
    
    for (int x = (start + 1); x < size; x++) {
        if (scores[x] > scores[target]) {
            target = x;
        }
    }
    return target;
}






/*
 Definition of function displayData. The function passes in two arrays, names and scores,
 and the size of the arrays. It displays names and scores of the players in descending
 order.
 */

void displayData(const string names[], const int scores[], int size) {
    cout << "\nTop Scorers:" << endl;
    
    for (int x = 0; x < size; x++) {
        cout << names[x] << ": " << scores[x] << endl;
    }
}


/*
 
 How many scores will you enter?: 4
 Enter the name for score #1: Suzy
 Enter the score for score #1: 600
 Enter the name for score #2: Kim
 Enter the score for score #2: 9900
 Enter the name for score #3: Armando
 Enter the score for score #3: 8000
 Enter the name for score #4: Tim
 Enter the score for score #4: 514

 Top Scorers:
 Kim: 9900
 Armando: 8000
 Suzy: 600
 Tim: 514
 Program ended with exit code: 0
 
 How many scores will you enter?: 5
 Enter the name for score #1: Suzy Q
 Enter the score for score #1: 666
 Enter the name for score #2: Kim Kardashian
 Enter the score for score #2: 9999
 Enter the name for score #3:
 Armando
 Enter the score for score #3: 8888
 Enter the name for score #4: Tiny Tim
 Enter the score for score #4: 54321
 Enter the name for score #5: The Notorious RBG
 Enter the score for score #5: 11

 Top Scorers:
 Tiny Tim: 54321
 Kim Kardashian: 9999
 Armando: 8888
 Suzy Q: 666
 The Notorious RBG: 11
 Program ended with exit code: 0
 
 */

