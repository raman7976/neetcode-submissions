class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses);
        vector<vector<int>> chi(numCourses);

        for(int i=0;i<prerequisites.size();i++)
        {
            indeg[prerequisites[i][0]]++;
            chi[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty())
        {
            int sz = q.size();
            int x = q.front();
            q.pop();
            topo.push_back(x);

            for(auto &it : chi[x])
            {
                indeg[it]--;
                if(indeg[it]==0)
                {
                    q.push(it);
                }
            }

        }

        if(topo.size()==numCourses)
        {
            return true;
        }

        return false;
    }
};
