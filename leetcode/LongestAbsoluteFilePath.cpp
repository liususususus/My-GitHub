#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct Tree
{
    string v;
    Tree *bro, *child;
};
int lengthLongestPath(string input)
{
    int max = 0;
    Tree *root = new Tree;
    string tem;
    int flag = 0;
    for(int i=0; i<input.length(); i++){
        if(input[i] == '\\' ){
            if(input[i+1] == 'n'){
                
            }
        } else {
            tem += input[i];
        }
    }
}

int main(){
    string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    cout << lengthLongestPath(input) << endl;
    return 0;
}