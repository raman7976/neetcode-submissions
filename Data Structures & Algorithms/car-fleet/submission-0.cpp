class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double> time(speed.size());
        stack<double> st;

        vector<pair<int,int>> p(speed.size());
        for(int i=0;i<speed.size();i++)
        {
            p[i]={position[i],speed[i]};
        }

        sort(p.begin(),p.end());

        for(int i=0;i<position.size();i++)
        {
            time[i] = (double)(target - p[i].first)/p[i].second;
        }

        for(int i=speed.size()-1;i>=0;i--)
        {
            if(!st.empty() && st.top()>=time[i])
            {
                continue;
            }
            else{
                st.push(time[i]);
            }
        }

        return st.size();
    }
};
