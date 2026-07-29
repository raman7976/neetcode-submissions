class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int con=nums[0];
        int gl = nums[0];

        for(int i=1;i<nums.size();i++)
        {
           con = max(con+nums[i],nums[i]);
           gl = max(gl,con);
        }

        return gl;

    }
};
