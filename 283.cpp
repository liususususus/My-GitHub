#include <iostream>
using namespace std;

long long minimalKSum(vector<int>& nums, int k) {
    
    //冒泡排序
    for(int i=0;i<nums.size()-1;i++){
        for(int j=0;j<nums.size()-i-1;j++){
            if(nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }


    int count = k;
    int sum = 0;
    int c = 0
    while(count > 0) {
        if(i < nums[c] && (c==0 || i > nums[c-1])) {
            sum += i;
            i++;
            count--;
        } else if(i == nums[c]) {
            i++;
            c++;
        } else {
            c++;
        }
    }
}



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x)  {
        val = x;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)  {
        val = x;
        this->left = left;
        this->right = right;
    }
 };

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    TreeNode* root = new TreeNode(descriptions[0][0]);
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    for(int i=1;i<descriptions.size();i++) {
        int parent = descriptions[i][1];
        int child = descriptions[i][2];
        nodes[parent]->left = new TreeNode(child);
        nodes.push_back(nodes[parent]->left);
    }
    return root;
        
}
int main(){
    return 0;
}