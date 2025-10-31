class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mp;
        int freq = 2;
        for(auto val:nums){
            mp[val]++;
        }
        for(auto it : mp){
            if(it.second==freq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};