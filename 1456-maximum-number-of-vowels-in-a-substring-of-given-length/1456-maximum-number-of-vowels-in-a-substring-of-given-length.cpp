class Solution {
public:
    
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int maxVowels(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans;
        int num = 0;
        int maxi = 0;
        while(j < n){
            //calculation
            if(isVowel(s[j])) num++;
            if(j-i+1  < k) j++;
            else if(j-i+1 == k){
                //ans -> store calculation work
                maxi = max(maxi,num);
                if(isVowel(s[i])) num--; // if i is vowel just remove 
                i++;
                j++;
            }
        }
        return maxi; 
    }
};