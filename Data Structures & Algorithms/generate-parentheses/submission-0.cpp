class Solution {
public:
    void gen(int i,int o,vector<string> &ans,string s)
    {
        if(i==0 && o==0)
        {
            ans.push_back(s);
            return;
        }
        if(i>0 and o==0)
        {
            s+='(';
            i--;
            o++;
            gen(i,o,ans,s);
        }
        else if(i==0 && o>0)
        {
            o--;
            gen(i,o,ans,s+')');
        }
        else if (i>0 and o>0)
        {
            o--;
            gen(i,o,ans,s+')');
            o++;
            i--;
            o++;
            gen(i,o,ans,s+'(');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        gen(n,0,ans,s);
        return ans;
    }
};
