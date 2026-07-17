/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:

   static bool comp(const Interval &a,const Interval &b)
   {
     return a.start < b.start;
   }

    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        int count=1;
        int maxi=1;
        sort(intervals.begin(),intervals.end(),comp);
        
        


        // Min Heap
        priority_queue<int, vector<int>, greater<int>> minH;
        minH.push(intervals[0].end);

        for(int i=1; i < intervals.size(); i++)
        {
            while(!minH.empty() && intervals[i].start>=minH.top())
            {
                
                minH.pop();
            }
            minH.push(intervals[i].end);

            if(minH.size()>maxi)maxi=minH.size();


        }

        return maxi;


        
        
    }
};
