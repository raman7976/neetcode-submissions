class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=nums[0];
        int suf=nums[nums.size()-1];
        int n=nums.size()-1;
        int maxi =max(pre,suf);

        for(int i=1;i<nums.size();i++)
        {
            pre*=nums[i];
            suf*=nums[n-i];
            maxi=max({maxi,suf,pre});
            if(pre==0)pre=1;
            if(suf==0)suf=1;
        }

        return maxi;
    }
};
