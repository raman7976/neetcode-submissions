class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l =0;
        int h =nums.size()-1;
        int ans=-1;

        while(l<=h)
        {
            int mid = l+(h-l)/2;
            
            if(nums[mid]>mid)
            {
                h=mid-1;
                ans=nums[mid]-1;
            }
            else{
                l=mid+1;
            }
        }
        if(ans==-1)
        return nums.size();
        return ans;
    }
};
