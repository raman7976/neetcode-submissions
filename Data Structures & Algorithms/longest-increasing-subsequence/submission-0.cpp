class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size(),1);

        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(1+dp[j],dp[i]);
                }
            }
        }

        int lis=0;
        for(int i=0;i<nums.size();i++)
        {
            lis=max(lis,dp[i]);
        }

        return lis;
    }
};
