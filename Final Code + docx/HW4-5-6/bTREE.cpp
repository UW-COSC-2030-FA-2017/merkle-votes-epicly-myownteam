//
// Created by Quinn
//
#include <iostream>
#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
    root = NULL;
}

bTREE::~bTREE()
{
    remove_tree();
}

// data inserted is going to be the number of nodes we insert
//which will be the total number of nodes -1 because of the root
int bTREE::dataInserted()
{
    return (numberOfNodes(root)) -1;
}

int bTREE::numberOfNodes(treeNode *leaf) {
   int x = 1; //initial node
    //no node so no subtree so no nodes
    if(leaf == NULL)
    {
        return 0;
    }
    else{
        x += numberOfNodes(leaf->left);
        x += numberOfNodes(leaf->right);
        return x;
    }

}

int bTREE::numberOfNodes()
{
    numberOfNodes(root);
}

void bTREE::remove_tree(treeNode *leaf) {
    if(leaf != NULL)
    {
        remove_tree(leaf->left);
        remove_tree(leaf->right);
        delete leaf;
    }
}
void bTREE::remove_tree() {remove_tree(root);}

void bTREE::insert(string data, treeNode *leaf)
{
    if(data<leaf ->data)
    {
        if(leaf->left!=NULL)
            insert(data, leaf->left);
        else
        {
            leaf->left = new treeNode;
            leaf->left->data = data;
            //set left side to null
            leaf->left->left = NULL;
            //right side to null
            leaf->left->right = NULL;
        }
    }
    else if(data>leaf->data)
    {
        if(leaf->right!=NULL)
            insert(data, leaf->right);
        else
        {
            leaf->right = new treeNode;
            leaf->right->data=data;
            //set left side to null
            leaf->right->left=NULL;
            //set right side to null
            leaf->right->right=NULL;
        }
    }
}

bool bTREE::insert(string data, int time)
{
    if(root!=NULL)
    {
        insert(data, root);
    } else
    {
        root = new treeNode;
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
}

bTREE::treeNode* bTREE::find(string data, treeNode *leaf)
{
    if(leaf!=NULL)
    {
        if(data==leaf->data)
            return leaf;
        if(data<leaf->data)
            return find(data,leaf->left);
        else
            return find(data, leaf->right);
    } else
        return NULL;
}

bool bTREE::find(string data)
{
    return find(data,root);
}

string bTREE::locate(string loc)
{
    return to_string(find(loc));
}
bool bTREE::operator ==(const bTREE &other) const
{
    return (root == 0 && other.root == 0)
        || (root != 0 && other.root != 0 && *root == *other.root);
}

bool bTREE::operator !=(const bTREE &other) const
{
    return (root != 0 && other.root != 0)
           || (root != 0 && other.root != 0 && *root != *other.root);
}
/*
ostream& bTREE::outHelp(ostream &output, const treeNode *root) const
{
    if(root == NULL)
    {
        outHelp(output, root->left);
        output << root->data;
        outHelp(output, root->right);
    }
    return output;
}

std::ostream& operator <<(std::ostream& out, const bTREE &p)
{
    p.outHelp(out, p.root);
    return out;
}
 */
