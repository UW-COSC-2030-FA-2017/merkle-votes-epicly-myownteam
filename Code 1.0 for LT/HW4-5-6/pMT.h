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
    int selectedHash;
    bTREE myMerkle;

    string hash_1(string);
    string hash_2(string);
    string hash_3(string);

public:
    pMT(int);
    ~pMT();


    int insert(string, int);

    int find(string);
    int findHash(string);

    string locate(string);

    friend bool operator==(const pMT& lhs, const pMT& rhs);

    friend bool operator!=(const pMT& lhs, const pMT& rhs);

    friend pMT operator^(const pMT& lhs, const pMT& rhs);
    friend std::ostream& operator<<(std::ostream& out, const pMT& p);

};

#endif //HW4_5_6_PMT_H
