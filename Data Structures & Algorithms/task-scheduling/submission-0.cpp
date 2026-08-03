class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        queue<pair<int,pair<int,char>>> q;
        unordered_map<char,int> mpp;
        
        for(int i=0;i<tasks.size();i++){
            mpp[tasks[i]]++;
        }

        for(auto &it : mpp)
        {
            pq.push({it.second,it.first});
        }

        int time=1;
        while((!pq.empty()) || (!q.empty()))
        {
            if(!q.empty())
            {
                if(q.front().first==time)
                {
                    pair<int,pair<int,char>> y = q.front();
                    q.pop();
                    pq.push(y.second);
                }
            }

            if(!pq.empty()){

            pair<int,char> x = pq.top();
            pq.pop();
            x.first = x.first-1;
            
            if(x.first>0)
            {
               q.push({time+n+1,{x}});
            }
            }
            time++;  
        }

        return time-1;
    }
};
