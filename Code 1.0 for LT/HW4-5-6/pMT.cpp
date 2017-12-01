//
// Created by Quinn on 11/19/2017.
//

#include "pMT.h"
pMT::pMT(int hashSelect)
/**
 * @brief
 * @param hashSelect a number corresponding to the hashfunction to use for this pMT
 * @return
 */
{
    if(hashSelect == 1)
    {
        hash_1();
    }
    else if(hashSelect == 2)
    {

    }
    else if(hashSelect == 3)
    {

    }
    else
        std::cout<< "That is not a valid hash selection" << endl;
}

pMT::~pMT()
/**
 * @brief destructor
 * @return nada
 */
{
    void bTREE::remove_tree() {};
}


int pMT::insert(string vote, int time)
/**
 * @brief insert a vote and time into a leaf node of tree
 * @param vote - a string
 * @param time - an int representing the time
 * @return the number of operations needed to do the insert, -1 if out of memory
 */
{
}

int pMT::find(string vote, int time, int hashSelect)
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of opperations required to find the matching vote
 */
{

}

string pMT::hash_1(string hash)
{
    int hashVal = 0, len = hash.length();
    for(int i = 0; i < len; i++)
    {
        hashVal += hash[i];
    }
    return hashVal + "";
}
string pMT::hash_2(string hash) {
    int sum = 0;
    for (int k = 0; k < hash.length(); k++);
    {
        sum = sum + int(hash[k]);
    }
    return (sum % 307) + "";
}
string pMT::hash_3(string hash)
{
    int s = 131;
    long word = 0;
    for(int i = 0; i < hash.length(); i++)
    {
        word = (word * s) + hash[i];
    }
    return (word % 307) + "";
}

