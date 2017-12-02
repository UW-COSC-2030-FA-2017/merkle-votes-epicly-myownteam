//
// Created by Quinn on 11/19/2017.
//

#ifndef HW4_5_6_PMT_H
#define HW4_5_6_PMT_H
#pragma once

#include "bTREE.h"
#include <iostream>
#include <string>
using namespace std;
class pMT
{
private:

    string selectedHash;
    bTREE myMerkle;
    string h;

    string hash_1(string);
    string hash_2(string);
    string hash_3(string);
    //ostream & outHelp(ostream &output, const pMT root) const;


public:
    pMT(int);
    ~pMT();
    int numOfOp;




    int insert(string, int, int);

    int find(string, int);

    string locate(string);

    bool operator==(const pMT &other) const;

    bool operator!=(const pMT &other) const ;

    pMT operator^(const pMT &other) const;
    //std::ostream& operator<<(std::ostream& out, const pMT p);

};
//std::ostream& operator<<(std::ostream& out, const pMT p);

#endif //HW4_5_6_PMT_H
