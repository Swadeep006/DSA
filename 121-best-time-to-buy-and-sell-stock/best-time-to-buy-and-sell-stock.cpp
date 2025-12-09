class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 0;
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[buy] > prices[i]) {
                buy = i;
            }
            if (prices[sell] < prices[i] || sell < buy) {
                sell = i;
            }
            ans = max(ans, prices[sell] - prices[buy]);
        }
        return ans;
    }
};