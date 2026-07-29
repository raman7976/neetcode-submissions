class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        if(nums.size()==3)return max({nums[0],nums[2],nums[1]});
        int n=nums.size();
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);

        for(int i=2;i<n-1;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }


        vector<int> dp2(nums.size());
        dp2[1]=nums[1];
        dp2[2]=max(nums[1],nums[2]);

        for(int i=3;i<n;i++)
        {
            dp2[i]=max(dp2[i-1],dp2[i-2]+nums[i]);
        }

        return max(dp2[n-1],dp[n-2]);
        
    }
};
