class Solution {
public:
    int check(string word, int s,int e)
    {
        int len = 0;
        while( s>=0 && e<word.size() && (word[s]==word[e]))
        {
            len = (e-s+1);
            s--;
            e++;
        }
        return len;

    }
    string longestPalindrome(string s) {
        int start =0;
        int maxL = 0;
        for(int i=0;i<s.size();i++)
        {
            int len=0;
            int odd=check(s,i,i);
            int even =check(s,i,i+1);
            len=max(odd,even);

            if(len>maxL)
            {
                maxL=len;
                start = i-(len-1)/2;
            }
            
        }

        return s.substr(start,maxL);
        
    }
};
