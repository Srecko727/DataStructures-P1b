#ifndef PostFixTokens_h
#define PostFixTokens_h
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class PostFixTokens {
public:
PostFixTokens();
PostFixTokens(vector<string> inFix);
~PostFixTokens();

    vector<string> getPostFixTokens();
    vector<string> getInFixTokens();
	int order(string NWO);//new
    void setInFixTokens(vector<string> inFix);
    void printPostFix();
    void printInFix();
    void createPostFix();


private:
vector<string> inFixTokens;
vector<string> postFixTokens;
    
};


#endif /* PostFixTokens_h */
