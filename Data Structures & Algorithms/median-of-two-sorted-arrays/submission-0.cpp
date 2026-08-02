class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      
      if(nums1.size()>nums2.size())
      {
        return findMedianSortedArrays(nums2,nums1);
      }

      int m = nums1.size();
      int n = nums2.size();
      int low = 0 ;
      int high = m;
      int totalLeft = (m+n+1)/2;

      while(low<=high)
      {
        int  px = low+(high-low)/2;
        int  py = totalLeft - px;

        //handle Boundry conditions
        int maxLeft1  = (px==0) ? INT_MIN : nums1[px-1];
        int minRight1 = (px==m) ? INT_MAX : nums1[px];

        int maxLeft2  = (py==0) ? INT_MIN : nums2[py-1];
        int minRight2 = (py==n) ? INT_MAX : nums2[py];

        //check if we found valid partition
        if(maxLeft1<=minRight2 && maxLeft2<=minRight1)
        {
            if((m+n)%2==1)
            {
                return max(maxLeft1,maxLeft2);
            }
            else{
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            }
        }
        else if(maxLeft1>minRight2)
        {
            high=px-1;
        }
        else{
            low=px+1;
        }

      }

      return 0.0;
      
        
    }
};
