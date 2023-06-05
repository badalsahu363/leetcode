class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(auto it : arr) {
            sum += it;
        }
        
        if(sum % 3 != 0) return false;
        int x = sum/3; 
        int cnt = 0;
        int currsum =0;
        for(auto it : arr){
            currsum += it;
            if(currsum == x){
                   cnt++;
                   currsum =0;
            }
        }
        
        if(cnt >=3){
            return true;
        }
        return false;
    }
};