#define ll long long
class Solution {
public:
    bool is_possible(ll maxtime,vector<int>& time, int totalTrips){
        ll trips_completed = 0;
        for(auto it :time){
            trips_completed+= maxtime/it;
        }
        return (trips_completed >= totalTrips);
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l = 0,r = (1e14);
        while(l < r){
            ll mid = l + (r - l)/2;
            if(is_possible(mid,time,totalTrips)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};