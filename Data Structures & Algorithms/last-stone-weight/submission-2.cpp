class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        if(stones.size()==1)return stones[0];
        

        for(auto &it : stones)
        {
            pq.push(it);
        }

        while(pq.size()>2)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x==y)continue;
            else{
                pq.push(abs(x-y));
            }
        }

        if(pq.size()==1)
        {
            return pq.top();
        }

        int x =pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();

        if(x==y)
        {
            return 0;
        }
         
        return abs(x-y);
               
    }
};
