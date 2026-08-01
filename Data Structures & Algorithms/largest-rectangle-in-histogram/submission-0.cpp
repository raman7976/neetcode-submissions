class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>> left_span;
        stack<pair<int,int>> right_span;
        vector<int> left(n);
        vector<int> right(n);

        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                left_span.push({heights[i],1});
                left[i]=1;
            }

            else{
                int x = 1;
                while(!left_span.empty() && left_span.top().first>=heights[i])
                {
                    x+=left_span.top().second;
                    left_span.pop();
                }
                left_span.push({heights[i],x});
                left[i]=x;
            }
        }
        

        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                right_span.push({heights[i],1});
                right[i]=1;
            }

            else{
                int x = 1;
                while(!right_span.empty() && right_span.top().first>=heights[i])
                {
                    x+=right_span.top().second;
                    right_span.pop();
                }
                right_span.push({heights[i],x});
                right[i]=x;
            }
        }

        vector<int> width(n);
        int maxi =0;

        for(int i=0;i<n;i++)
        {
            width[i]=left[i]+right[i]-1;
            maxi = max(maxi,width[i]*heights[i]);
        }

        return maxi;

    }
};
