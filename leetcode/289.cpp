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
        int f2[m][n] = {0}, f5[m][n] = {0}, g2[m][n] = {0}, g5[m][n] = {0};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int two = 0;
                int five = 0;
                while(grid[i][j] % 2 == 0) {
                    two++;
                    grid[i][j] = grid[i][j] / 2;
                }
                while(grid[i][j] % 5 == 0) {
                    five++;
                    grid[i][j] = grid[i][j] / 5;
                }
                f2[i][j] = f2[i-1][j] + two;
                f5[i][j] = f5[i-1][j] + five;
                g2[i][j] = g2[i][j-1] + two;
                g5[i][j] = g5[i][j-1] + five;
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //左上
                ans = max(ans, min(f2[i][j] + g2[i][j-1], f5[i][j] + g5[i][j-1]));
                //左下
                ans = max(ans, min(f2[i][j] + g2[m-1][n-1] - g2[i][j], f5[i][j] + g5[m-i][n-i] - g5[i][j]));
                //右上
                ans = max(ans, min(f2[m-1][n-1] - f2[i][j] + g2[i][j], f5[m-1][n-1] - f5[i][j] + g5[i][j]));
                //右下
                ans = max(ans, min(f2[m-1][n-1] - f2[i][j] + g2[m-1][n-1] - g2[i][j-1], f5[m-1][n-1] - f5[i][j] + g5[m-i][n-i] - g5[i][j-1]));
            }
        }
    }

int main()
{
    string s = "01234567890";
    vector<vector<int>> a = {{23,17,15,3,20},{8,1,20,27,11},{9,4,6,2,21},{40,9,1,10,6},{22,7,4,5,3}};
    //cout << change(1234) << endl;
    //cout << change(10) << endl;
    //cout << digitSum(s, 2);
    cout << maxTrailingZeros(a);
    int c;
    cin>>c;
    return 0;
}