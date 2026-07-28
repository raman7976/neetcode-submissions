class Solution {
public:
    void f(int i,vector<int> &num,vector<int>&path,vector<vector<int>> &ans,int target)
    {
        if(target==0)
        {
            ans.push_back(path);
            return;
        }
        else if(target<0 || i>=num.size())
        {
            return;
        }
        path.push_back(num[i]);
        f(i,num,path,ans,target-num[i]);
        path.pop_back();
        f(i+1,num,path,ans,target);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        f(0,nums,path,ans,target);
        return ans;
    }
};
