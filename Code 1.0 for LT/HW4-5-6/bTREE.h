//
// Created by Quinn
//

#ifndef HW4_5_6_BTREE_H
#define HW4_5_6_BTREE_H
#pragma once
#include <string>
//https://stackoverflow.com/questions/2863582/binary-tree-operator-overloading-and-recursion
//use this site for help
using namespace std;

class bTREE
{
    struct treeNode{
        string data;
        int time;
        treeNode *left;
        treeNode *right;
        friend bool operator ==(const treeNode& lhs, const treeNode& rhs)
        {
            return lhs. == rhs.time
                   &&((lhs.left == 0 && rhs.left == 0)
                      || (lhs.left != 0 && rhs.left !=0 && *lhs.left == *rhs.right))
                   &&((lhs.right ==0 && rhs.right ==0)
                      || (lhs.right != 0 && rhs.right != 0 && *lhs.right == *rhs.right));


        }
        friend bool operator !=(const treeNode &lhs, const treeNode &rhs)
        {
            return lhs. != rhs.time
                   &&((lhs.left == 0 && rhs.left == 0)
                      || (lhs.left != 0 && rhs.left !=0 && *lhs.left == *rhs.right))
                   &&((lhs.right ==0 && rhs.right ==0)
                      || (lhs.right != 0 && rhs.right != 0 && *lhs.right == *rhs.right));

        }

    };

private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
    treeNode *left;
    treeNode *right;
    treeNode *root;
    int time;
    void insert(string data, treeNode *leaf);

    treeNode*find(string data, treeNode *leaf);
    void remove_tree(treeNode *leaf);
    int numberOfNodes(treeNode *leaf);



public:
    bTREE();
    ~bTREE();
    void remove_tree();

    int dataInserted();
    int numberOfNodes();

    bool insert(string, int);

    bool find(string);

    string locate(string);


    bool operator==(const bTREE &other) const;
    bool operator!=(const bTREE &other) const;

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);

};

#endif //HW4_5_6_BTREE_H
