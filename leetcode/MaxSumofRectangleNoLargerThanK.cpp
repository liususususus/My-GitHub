#include <iostream>
#include <vector>
using namespace std;

int maxSumSubmatrix(vector<vector<int> >& matrix, int k) {  
    int m = matrix.size();
    if(m == 0) return 0;
    int n = matrix[0].size();
    if(n == 0) return 0;
    int res = INT_MIN;
    for(int i = 0; i < n; i++) {
        vector<int> sum(m, 0);
        for(int j = i; j < n; j++) {
            for(int p = 0; p < m; p++) {
                sum[p] += matrix[p][j];
            }
            int cur = 0;
            for(int p = 0; p < m; p++) {
                cur += sum[p];
                if(cur > res && cur <= k) {
                    res = cur;
                }
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int> > matrix = {{5,-4,-3,4},{-3,-4,4,5},{5,1,5,-4}};
    int k = 8;
    cout<<maxSumSubmatrix(matrix, k)<<endl;
    int a;
    cin>>a;
    return 0;
}