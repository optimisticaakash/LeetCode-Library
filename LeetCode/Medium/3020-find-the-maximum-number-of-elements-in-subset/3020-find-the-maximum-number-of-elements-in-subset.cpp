class Solution {
public:
    typedef long long ll;
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<ll , int> mp; //ll isliye liye hai bcz x ki power badhte - badhte
        // boht bada no ban skta hai 

        for(int &num: nums){
            mp[num]++;
        }

        int result = 0;

        //corner case for 1

        if(mp[1]%2){
            result = mp[1];
        }else{
            result = mp[1]-1;
        }

        //map pr iterate krenge and map key , value pair me hota hai to 

        for(auto &[num,freq] : mp){//here hume freq se koi khaas mutlb nhi hai to empty bhi chod skte the

            if(num == 1) continue; //already handled


            ll curr = num;
            int len = 0;

            while(mp.count(curr) && mp[curr] > 1){
                len += 2;
                curr = curr * curr;
            }

            if(mp.count(curr) && mp[curr] == 1){// here dont use mp[curr] == 1 bcz agar nhi hoga map me to  woh freq ko 0 set kr dega apne aap 
                len += 1;
            }else{
                len -= 1;
            }

            result = max(result , len);
        }

        return result;
    }
};

//T.C : O(n* log(log(m)))
//where: m is the greatest element in the map
//S.C : O(n)
