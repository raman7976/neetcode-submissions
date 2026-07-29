class MedianFinder {
public:

    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        //ingestion
        if(left.empty() || left.top()>=num)
        {
            left.push(num);
        }
        else{
            right.push(num);
        }

        //balancing
        if(left.size()>right.size()+1)
        {
            right.push(left.top());
            left.pop();
        }

        else if(right.size()>left.size())
        {
            left.push(right.top());
            right.pop();
        }
       
    }
    
    double findMedian() {
        
        if(right.size()==left.size())
        {
            double x = right.top();
            double y = left.top();
            return (x+y)/2.0;
        }

        return left.top();
    }
};
