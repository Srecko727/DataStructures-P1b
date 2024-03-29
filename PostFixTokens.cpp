#include "PostFixTokens.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <stack>
using namespace std;

vector<string> inFixTokens;
vector<string> postFixTokens;

PostFixTokens::PostFixTokens() {};
PostFixTokens::PostFixTokens(vector<string> inFix)
{
	for (int i = 0; i < inFix.size(); i++)
	{
		inFixTokens.push_back(inFix.at(i));
	}
};
PostFixTokens::~PostFixTokens() {};

vector<string> PostFixTokens::getPostFixTokens()
{
	if (inFixTokens.size() == 0)
	{
		throw invalid_argument("you messed up F, no inFix");
	}
	else return postFixTokens;
};
vector<string> getInFixTokens()
{
	return inFixTokens;
};

int  PostFixTokens::order(string NWO)
{
	if (NWO == "^") { return 3; }
	else if (NWO == "/") { return 2; }
	else if (NWO == "*") { return 2; }
	else if (NWO == "-") { return 1; }
	else if (NWO == "+") { return 1; }
	else if (NWO == "(") { return 0; }
	else return -1;
};
void PostFixTokens::setInFixTokens(vector<string> inFix)
{
	inFixTokens == inFix;
};
void PostFixTokens::printPostFix()
{
	if (inFixTokens.size() == 0)
	{
		throw invalid_argument("you messed up F, no inFix");
	}
	else
	{
		for (int i = 0; i <= postFixTokens.size(); i++)
		{
			cout << postFixTokens[i] << "  ";
		}
	}
};
void PostFixTokens::printInFix()
{
	for (int i = 0; i < inFixTokens.size(); i++)
	{
		cout << inFixTokens[i] << " ";
	}
};
void PostFixTokens::createPostFix()
{
	if (inFixTokens.size() == 0)
	{
		throw invalid_argument("you messed up F, no inFix");
	}
	else
	{
		stack<string> inTo;
		int x = inFixTokens.size();
		for (int i = 0; i < x; i++)//if its an operand add it to the output string
		{
			if ((inFixTokens[i] != (")") &&
				inFixTokens[i] != ("+") &&
				inFixTokens[i] != ("-") &&
				inFixTokens[i] != ("*") &&
				inFixTokens[i] != ("/") &&
				inFixTokens[i] != ("^") &&
				inFixTokens[i] != ("(")))
			{
          //      cout << inFixTokens[i];
                postFixTokens.insert(postFixTokens.end(), inFixTokens[i]);

			}
			else if (inFixTokens[i] == ("("))
			{
				inTo.push("(");
			}
			else if (inFixTokens[i] == (")"))//if its a (, pop it and output it from the stack till )
			{
				while (inTo.top() != ("("))
				{
					string temp = inTo.top();
					inTo.pop();
					postFixTokens.insert(postFixTokens.end(), temp);
				}
				inTo.pop();
			}
			else if ((inFixTokens[i] == ("+")) ||//if its an operator pop all elements
				(inFixTokens[i] == ("-")) ||
				(inFixTokens[i] == ("*") )||
				(inFixTokens[i] == ("/")) ||
				(inFixTokens[i] == ("^")))
			{
				if (inTo.empty())
				{
					inTo.push(inFixTokens[i]);
				}
				else
				{
					int uno = order(inTo.top()), dos = order(inFixTokens[i]);
					if (dos > uno)
					{
						inTo.push(inFixTokens[i]);
					}
					else if (uno == 3 && dos == 3)
					{
						inTo.push(inFixTokens[i]);
					}
					else
					{
						while (dos <= uno && !inTo.empty())
						{
							string temp = inTo.top();
							inTo.pop();
							postFixTokens.insert(postFixTokens.end(), temp);
						}
						inTo.push(inFixTokens[i]);
					}
				}
			}
		}
		while (!inTo.empty())
		{
			postFixTokens.push_back(inTo.top());
			inTo.pop();
		}
	}
};
