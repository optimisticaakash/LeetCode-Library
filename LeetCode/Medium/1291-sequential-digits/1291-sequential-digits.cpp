class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        queue<int> q;
        for(int i = 1; i <= 8; i++){
            q.push(i);
        }

        vector<int> result;

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            if(temp >= low && temp <= high){
                result.push_back(temp);
            }

            int ld = temp % 10;
            if(ld  + 1 <= 9){
                q.push(temp * 10 + (ld +1 ));
            }
        }

        return result;
    }
};