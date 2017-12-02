//
// Created by Quinn on 11/19/2017.
//
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "pMT.h"
using namespace std;

int main(int argc, char **argv)
{
    int selection;
    bTREE treeOB;
    pMT pmtOB(selection);
    string line;

    string vote;
    int timeStamp;

    /*So we have the vote now in our vote line
     * we need to select a hash now and then put it in the tree
     *
     */
    cout << "We are grabbing your vote: " << endl;
    ifstream myfile("mv test.txt");
    if(!myfile.is_open())
    {
        cout << "error opening the file, close the program and try again" << endl;
    }
    else
    {
        while(getline(myfile,line))
        {
            istringstream istringstream1(line);
            istringstream1 >> vote;
            istringstream1 >> timeStamp;
        }
    }
    cout << "Before we can enter your vote please input a 1, 2, 3 to select your hash";
    cin >> selection;
    cout << "Thank you! We will now store your votes" << endl;
    for(int i = 0; i < line.length(); i++) {

        if(pmtOB.find(vote,timeStamp) == pmtOB.insert(vote,timeStamp,selection))
        {
            cout << "Validated and the vote is already in our database" << endl;
        } else{
            cout << "Not validated and the vote is not in our database, adding now" << endl;
            pmtOB.insert(vote, timeStamp, selection);
        }
    }
    //check for two votes and if theyre equal output validated and if not not validated



    return 0;
}
