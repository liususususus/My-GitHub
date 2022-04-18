#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int minimumRounds(vector<int> &tasks)
{
    map<int, int> Map;
    int n = tasks.size();
    for (int i = 0; i < n; i++)
    {
        if (Map.find(tasks[i]) == Map.end())
        {
            Map[tasks[i]] = 1;
        }
        else
        {
            Map[tasks[i]]++;
        }
    }
    map<int, int>::iterator it; //使用迭代器
    int count = 0;
    for (it = Map.begin(); it != Map.end(); it++)
    {
        if (it->second == 1)
        {
            return -1;
        }
        if (it->second % 6 == 0)
        {
            count += it->second / 6 * 2;
        }
        else if (it->second % 6 <= 3)
        {
            count += it->second / 6 * 2 + 1;
        }
        else if (it->second % 6 <= 5)
        {
            count += it->second / 6 * 2 + 2;
        }
    }
    return count;
}

string change(int n)
{
    string s;
    if(n == 0){
        char tem = 48;
        s += tem;
    }
    while (n > 0)
    {
        int tem = n % 10;
        n = n / 10;
        char c = tem + 48;
        s += c;
    }
    for (int i = 0; i < s.length() / 2 ; i++)
    {
        char tem = s[i];
        //cout<<tem<<" ";
        s[i] = s[s.length() - 1 - i];
        s[s.length() - 1] = tem;
    }
    return s;
}

string digitSum(string s, int k)
{
    int a[s.length()];
    while (s.length() > k)
    {
        for (int i = 0; i < s.length(); i++)
        {
            a[i] = s[i] - 48;
        }
        string s1;
        int sum = 0, c = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum += a[i];
            if ((i + 1) % k == 0)
            {
                s1 += change(sum);
           //     cout<< sum <<" ";
                sum = 0;
            }
            if (i == s.length() - 1 && (i + 1) % k != 0)
            {
                s1 += change(sum);
             //   cout<< sum <<" ";
                sum = 0;
            }
        }
        s = s1;
    }
    return s;
}

int maxTrailingZeros(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size(); 
    float a[m][n] = {0};
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] % 10 == 0){
                a[i][j] = 1;
            }
            if(grid[i][j] % 5 == 0 && grid[i][j] % 10 != 0){
                a[i][j] = 0.3;
            }
            if(grid[i][j] % 2 == 0 && grid[i][j] % 10 != 0){
                a[i][j] = 0.21;
            }
        }
    }
    float count_m[m] = {0};
    float count_n[n] = {0};
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            count_m[i] += a[i][j];
            count_n[j] += a[i][j];
        }
    }
}

int main()
{
    string s = "01234567890";
    //cout << change(1234) << endl;
    //cout << change(10) << endl;
    cout << digitSum(s, 2);
    return 0;
}