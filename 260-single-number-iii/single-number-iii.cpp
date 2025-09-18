class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long allxor = 0;
        for(long val : nums){
            allxor ^=val;
        }
        long k = allxor & ~(allxor -1);
        long g1 =0,g2=0;
        for(long val : nums){
            if((k&val)!=0){
                g1^=val; 
            }
            else{
                g2^=val;
            }
        }
        return {(int)g1,(int)g2};
    }
};