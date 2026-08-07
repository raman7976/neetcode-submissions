class Solution {
public:
    void dfs(string s,unordered_map<string ,priority_queue<string,vector<string>,greater<string>>> &mpp,vector<string> &res)
    {
        while(mpp.count(s)&& !mpp[s].empty())
        {
            string x = mpp[s].top();
            mpp[s].pop();
            dfs(x,mpp,res);
           
        }

        res.push_back(s);
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string ,priority_queue<string,vector<string>,greater<string>>> mpp;
        vector<string> res;
        for(int i=0;i<tickets.size();i++)
        {
            mpp[tickets[i][0]].push(tickets[i][1]);
        }

        dfs("JFK",mpp,res);

        reverse(res.begin(),res.end());

       
            return res;
        


    }
};
