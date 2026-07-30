class Solution {
public:
    void check(string &s,int st, int e,int &count)
    {
        while(st>=0 && e<s.size() && s[st]==s[e])
        {
            count++;
            st--;
            e++;
        }
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            check(s,i,i,count);
            check(s,i,i+1,count);
        }

        return count;
        
    }
};
