class Solution {
public:
    void f(int ind, vector<int>& nums, int target,
           vector<int>& path, vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(path);
            return;
        }

        for(int i = ind; i < nums.size(); i++)
        {
            if(i > ind && nums[i] == nums[i-1])
                continue;

            if(nums[i] > target)
                break;

            path.push_back(nums[i]);
            f(i + 1, nums, target - nums[i], path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> path;

        f(0, candidates, target, path, ans);

        return ans;
    }
};