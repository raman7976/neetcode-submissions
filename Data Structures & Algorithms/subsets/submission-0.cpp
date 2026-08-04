class Solution {
public:
    void f(int ind,vector<int> &nums,vector<int> &path,vector<vector<int>> &ans)
    {
        if(ind==nums.size())
        {
          ans.push_back(path);
          return;
        }

        path.push_back(nums[ind]);
        f(ind+1,nums,path,ans);
        path.pop_back();
        f(ind+1,nums,path,ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int ind=0;
        f(ind,nums,path,ans);
        return ans;

    }
};
