class Solution {
public:
    int maxProfit(vector<int>&arr) {
       int profit = 0;
       int cost = 0;
       int mini = arr[0];
       for(int i = 1 ; i<arr.size() ; ++i){
          cost = arr[i] - mini;
          profit = max(cost, profit); 
          mini = min(mini , arr[i]);
       }
       return profit;
    }
};