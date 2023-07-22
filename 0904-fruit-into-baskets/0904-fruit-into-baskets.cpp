class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mpp;
        int head=0,tail=0,ans=0;
        for(head =0;head<fruits.size();head++){
            mpp[fruits[head]]++;
            while(mpp.size() > 2){
                mpp[fruits[tail]]--;
                if(mpp[fruits[tail]] == 0){
                    mpp.erase(fruits[tail]);
                }
                tail++;
            }
            ans = max(ans,head-tail+1);
        }
        return ans;
    }
};