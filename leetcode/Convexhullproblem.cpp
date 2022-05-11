#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isValid( pair<int,int> a,pair<int,int> b, set<pair<int, int> > &trees) {
    int flag = 0;
    if(a.first == b.first){
        for(set<pair<int, int> >::iterator i=trees.begin(); i!=trees.end(); i++){
            if(flag == 0 && (*i).first < a.first){
                flag = -1;
            } else if(flag == 0 && (*i).first > a.first){
                flag = 1;
            }
            if(flag == -1 && (*i).first > b.first){
                return false;
            }
            if(flag == 1 && (*i).first < b.first){
                return false;
            }
        }
        return true;
    }
    double k = (double)(b.second - a.second) / (double)(b.first - a.first);
    double c = (double)a.second - k * (double)a.first;
    //cout<<"k "<<k<<"c "<<c<<endl;
    for(set<pair<int, int> >::iterator i=trees.begin(); i!=trees.end(); i++){
        double y = k * (double)(*i).first + c;
        //  cout<< "y "<<y<<endl;
        if(flag == 0 && (double)(*i).second < y){
            flag = -1;
        } else if(flag == 0 && (double)(*i).second > y){
            flag = 1;
        }
        if(flag == -1 && (double)(*i).second > y){
            return false;
        }
        if(flag == 1 && (double)(*i).second < y){
            return false;
        }
    }
    return true;
}

vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    int n = trees.size(), flag = 0;
    if(n<=3){
        return trees;
    }
    set<pair<int, int> > s;
    set<pair<int, int> > result;
    for(int i=0; i<n; i++){
        s.insert(make_pair(trees[i][0], trees[i][1]));
    }
    set<pair<int, int> >::iterator i;
    set<pair<int, int> >::iterator j;
    i = s.begin();
    result.insert(*i);
    while(flag == 0) {
        for(j=i; ; j++){
            if(j==s.end()){
                j = s.begin();
            }
            cout<<"2"<<endl;
            if(isValid(*i, *j, s)){
                if(result.find(*j) != result.end()){
                    flag == 1;
                    break;  
                } else {
                    result.insert(*j);
                    cout<<1<<" ";
                }
                result.insert(*j);
                i = j;
            }
        }
    }
    vector<vector<int>> ans;
    set<pair<int, int> >::iterator k;
    for(k=result.begin(); k!=result.end(); k++){
        vector<int> temp;
        temp.push_back(k->first);
        temp.push_back(k->second);
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    vector<vector<int>> trees = {{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
    vector<vector<int>> ans = outerTrees(trees);
    for(int i=0; i<ans.size(); i++){
        cout<<"("<<ans[i][0]<<","<<ans[i][1]<<")"<<endl;
    }
    return 0;
}