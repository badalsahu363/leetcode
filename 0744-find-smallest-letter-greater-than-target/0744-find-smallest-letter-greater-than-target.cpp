class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0;
        int r = n-1;
        while(l <= r){
            int mid = (l + r)/2;
            if(letters[mid] > target){
                r = mid - 1;
            }else if(letters[mid] <= target){
                l = mid+1;
            }
        }
        return l == n?letters[0]:letters[l];
    }
};