//
//  ExpTree.h
//  
//
//  Created by Resch,Cheryl on 7/11/19.
//

#ifndef ExpTree_h
#define ExpTree_h

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//you may change this
struct node
{
    string data;
    node* left;
    node* right;
    bool isOp;
    int value;

    ~node();
};

class ExpTree 
{
    //do not change public methods
public:
    ExpTree();
    ~ExpTree();
    
    void CreateTree(vector<string> postFix);
    void SetVariableValues(vector<int> values);
    int EvaluateTree();
    void inOrderTraversalandPrint(ostream &out);

private:
    node* root;
    node* newNode(int newN);
    node* newNode(string newN);
    bool isOp(string Operator);
    void inOrderTrav(node* root,ostream &out);
    void inOrderSet(node* root, vector<int> values, int counter);
 
    //add helper methods here
};

#endif /* ExpTree_h */
