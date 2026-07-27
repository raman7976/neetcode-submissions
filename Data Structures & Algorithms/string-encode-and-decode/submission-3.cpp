class Solution {
public:
    

    string ans="";
    string encode(vector<string>& strs) {
       
       for(int i=0;i<strs.size();i++)
       {
         ans+= to_string(strs[i].size())+ '#' + strs[i];
       }
      return ans;

    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i=0;
        while(i<s.size())
        {
            int num = 0;
            while(s[i]!='#')
            {
                num = num*10 + (s[i]-'0'); 
                i++;
            }
            i++;
            
            string k="";
            for(int j=0; j<num; j++){
                k+=s[i];
                i++;
            }
            ans.push_back(k);
        }

        return ans;

    }
};

