class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l =0;
        int h =nums.size()-1;


        while(l<=h)
        {
            int mid = l+(h-l)/2;
            
            if(nums[mid]>mid)
            {
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
