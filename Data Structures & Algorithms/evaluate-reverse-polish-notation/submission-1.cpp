class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for(int i=0;i<n;i++)
        {
            if(tokens[i]!="/" && tokens[i]!="*" && tokens[i]!="+" && tokens[i]!="-"  )
            {
                s.push(stoi(tokens[i]));
            }
            else{
                int b=s.top();
                s.pop();
                int a = s.top();
                s.pop();
                
                if(tokens[i]=="/")
                {
                    s.push(a/b);
                }
                else if(tokens[i]=="*")
                {
                    s.push(a*b);
                }
                else if(tokens[i]=="+")
                {
                    s.push(a+b);
                }
                else{
                    s.push(a-b);
                }
            }
        }

        return s.top();
    }
};
