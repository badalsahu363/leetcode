class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int cnt =0;
      int ele = 0;
      for(auto it : nums){
          if(cnt  == 0){
              ele = it;
          }
          if(ele == it){
              cnt += 1;
              
          }else{
              cnt -= 1;
          }
      }  
        return ele;
    }
};