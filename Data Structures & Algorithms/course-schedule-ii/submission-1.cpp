class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> indeg(numCourses,0);
        queue<int> q;
        vector<vector<int>> adj(numCourses,vector<int>());

        for(int i =0;i<prerequisites.size();i++)
        {
          indeg[prerequisites[i][0]]++;
          adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0;i<indeg.size();i++)
        {
            if(indeg[i]== 0)
            q.push(i);
        }


        while(!q.empty())
        {
            int sz = q.size();
            

            for(int i=0;i<sz;i++)
            {
                int x = q.front();
                q.pop();
                ans.push_back(x);
                for(auto &it : adj[x]){
                    indeg[it]--;
                    if(indeg[it]==0)
                    {
                        q.push(it);
                    }
                }
            }
        }

        if(ans.size()!=numCourses)
        {
            return {};
        }

        return ans;



    }
};
