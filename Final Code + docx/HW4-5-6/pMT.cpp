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
        selectedHash = hash_1(h);
    }
    else if(hashSelect == 2)
    {
        selectedHash = hash_2(h);
    }
    else if(hashSelect == 3)
    {
        selectedHash = hash_3(h);
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
    bTREE ob;
    ob.remove_tree();
}


int pMT::insert(string vote, int time, int hashSelect)
/**
 * @brief insert a vote and time into a leaf node of tree
 * @param vote - a string
 * @param time - an int representing the time
 * @return the number of operations needed to do the insert, -1 if out of memory
 */
{
    bTREE ob;
    ob.insert(vote, time);
    //going to return (time -1)
    numOfOp = time -1;
    return numOfOp;
}

int pMT::find(string vote, int time)
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of opperations required to find the matching vote
 */
{
   bTREE ob;
    ob.find(vote);
    ob.insert(vote,time);
}

string pMT::locate(string loc)
{
    bTREE ob;
    return ob.locate(loc);
}
string pMT::hash_1(string hash)
{
    int hashVal = 0, len = hash.length();
    for(int i = 0; i < len; i++)
    {
        hashVal += hash[i];
    }
    return to_string(hashVal);
}
string pMT::hash_2(string hash) {
    int sum = 0;
    int len = hash.length();
    for (int k = 0; k < len; k++)
    {
        sum = (sum + hash[k]) ;
    }
    return to_string(sum % 307);
}
string pMT::hash_3(string hash)
{
    int s = 131;
    long word = 0;
    for(int i = 0; i < hash.length(); i++)
    {
        word += hash[i];
        word = word *s;
    }
    return to_string(word % 307);
}

bool pMT::operator ==(const pMT &other) const
{
    return (other == 0 && other.numOfOp == 0)
           || (numOfOp != 0 && other.numOfOp != 0 && numOfOp == other.numOfOp);
}


bool pMT::operator !=(const pMT &other) const
{
    return (numOfOp != 0 && other.numOfOp != 0)
           || (numOfOp != 0 && other.numOfOp != 0 && numOfOp != other.numOfOp);
}

/*ostream &outHelp(ostream &output, const pMT root) const
{
    if(root == 0)
    {
        outHelp(output, root.numOfOp);
        output << root.numOfOp;
        outHelp(output, root.numOfOp);
    }
    return output;
}
 */
/*std::ostream& operator <<(std::ostream& out, const pMT p)
{
    p.outHelp(out, p.numOfOp);
    return out;
}
 */
pMT pMT::operator^(const pMT &other) const
{
    return (numOfOp ^ 0 && other.numOfOp == 0)
        || (numOfOp ^ 0 && other.numOfOp != 0 && numOfOp == other.numOfOp);
}