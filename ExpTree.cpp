#include "ExpTree.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <stack>
using namespace std;

ExpTree::ExpTree()
{
    root = new node();
}
ExpTree::~ExpTree()
{
    delete root;
}

void ExpTree::CreateTree(vector<string> postFix)
{
    stack <node*> stack;
    node *middle, *rightN, *leftN;
    for (int i=0; i<postFix.size();i++)
    {
        if (isOp(postFix[i]) == false)
        {
            middle = newNode(postFix[i]);
            middle->isOp = false;
            stack.push(middle);
        }
        else
        {
            middle = newNode(postFix[i]);
            middle->isOp = true;
            rightN = stack.top();
            stack.pop();
            leftN = stack.top();
            stack.pop();
            middle->right = rightN;
            middle->left = leftN;
            stack.push(middle);
        }
    }
    middle =stack.top();
    root = middle;
    stack.pop();
}
void ExpTree::SetVariableValues(vector<int> values)
{
    inOrderSet(root,values,0);
}
int ExpTree::EvaluateTree()
{
    if(root->left == NULL)
    {
        
    }
}
void ExpTree::inOrderTraversalandPrint(ostream &out)
{
    inOrderTrav(root, out);
}


node* ExpTree::newNode(int newN) 
{ 
    node *temp = new node; 
    temp->left = temp->right = NULL; 
    temp->value = newN; 
    temp->data = "";
    return temp; 
}; 
node* ExpTree::newNode(string newN) 
{ 
    node *temp = new node; 
    temp->left = temp->right = NULL; 
    temp->value = 0; 
    temp->data = newN;
    return temp; 
}; 
bool ExpTree::isOp(string Operator)
{
    	if (Operator == "^") { return true; }
	else if (Operator == "/") { return true; }
	else if (Operator == "*") { return true; }
	else if (Operator == "-") { return true; }
	else if (Operator == "+") { return true; }
	else return false;
}
void ExpTree::inOrderTrav(node* root, ostream &out)
{
    if (root)
    {
        inOrderTrav(root->left, out);
        cout << root->data << " ";
        out << root->data << " ";
        inOrderTrav(root->right, out);
    }
}
void ExpTree::inOrderSet(node* root, vector<int> values, int counter)
{
    if (root)
    {
        inOrderSet(root->left, values, counter);
        if (!root->isOp)
        {
            root->value = values.at(counter);
            counter++;
        }
        inOrderSet(root->right,values, counter);
    }   
}

node::~node()
{
    delete left;
    delete right;
}