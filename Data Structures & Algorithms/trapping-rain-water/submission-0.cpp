class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(),0);
        vector<int> right(height.size(),0);
        int maxi=height[0];
        int maxiR=height[height.size()-1];
        for(int i=1;i<height.size()-1;i++)
        {
            left[i]=maxi;
            maxi = max(maxi,height[i]);
        }

        for(auto &it : left)
        {
            cout<< it << " ";
        }
        cout << endl;


        for(int i=height.size()-1;i>=0;i--)
        {
            right[i]=maxiR;
            maxiR =max(maxiR,height[i]);
        }

        for(auto &it : right)
        {
            cout<< it << " ";
        }

        int water = 0;
        for(int i=0;i<height.size();i++)
        {
            int x =min(left[i],right[i])-height[i];
            if(x>0)
            water+=x;
        }

        return water;
        
    }
};
