class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt  = 0;
        for(auto it: s){
          if(it == '(' && cnt++ > 0) ans+=it;
          if(it == ')' && cnt -- >1) ans += it;  
        }
        return ans;
    }
};