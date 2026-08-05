class Solution {
public:
    void f(int ind,vector<int> &nums ,vector<vector<int>> &ans,vector<int> &path)
    {
       
            ans.push_back(path);
       
        

        for(int i=ind;i<nums.size();i++)
        {
            if(i>ind && nums[i]==nums[i-1])continue;

            path.push_back(nums[i]);
            f(i+1,nums,ans,path);
            path.pop_back();
            

        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> path;

        f(0,nums,ans,path);
        return ans;
    }
};
