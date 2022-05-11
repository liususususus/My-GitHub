#include <iostream>
#include <vector>
#include <string>
#include<unordered_set>
using namespace std;

string toGoatLatin(string sentence) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int n = sentence.size();
        int i = 0, cnt = 1;
        string ans;

        while (i < n) {
            int j = i;
            while (j < n && sentence[j] != ' ') {
                ++j;
            }

            ++cnt;
            if (cnt != 2) {
                ans += ' ';
            }
            if (vowels.count(sentence[i])) {
                ans += sentence.substr(i, j - i) + 'm' + string(cnt, 'a');
            }
            else {
                ans += sentence.substr(i + 1, j - i - 1) + sentence[i] + 'm' + string(cnt, 'a');
            }

            i = j + 1;
        }

        return ans;
    }

string MytoGoatLatin(string sentence) {
        string result, tem;
        int count = 1;
        for(int i=0; i<sentence.length(); i++){
            if(sentence[i] == ' ' || i == sentence.length()-1){
                if(i == sentence.length()-1){
                    tem += sentence[i];
                }
                if(tem[0] == 'a' || tem[0] == 'e' || tem[0] == 'i' || tem[0] == 'o' || tem[0] == 'u' || tem[0] == 'A' || tem[0] == 'E' || tem[0] == 'I' || tem[0] == 'O' || tem[0] == 'U'){
                    tem += "ma";
                    for(int j=0; j<count; j++){
                        tem += 'a';
                    }
                    result += tem;
                    if(i != sentence.length()-1){
                        result += ' ';
                    }
                    
                    tem = "";
                    count++;
                } else {
                    string tt;
                    for(int j=1; j<tem.length(); j++){
                        tt += tem[j];
                    }
                    tt += tem[0];          
                    tt += "ma";
                    for(int j=0; j<count; j++){
                        tt += 'a';
                    }
                    result += tt;
                    if(i != sentence.length()-1){
                        result += ' ';
                    }
                    tem = "";
                    count++;
                }
            }
            else {
                tem += sentence[i];
            }
        }
        return result;
    }
int main(){
    return 0;
}