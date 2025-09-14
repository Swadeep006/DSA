class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        long long sum = 0;
        for (int val : nums)
            sum += val;

        double avg = (double)sum / nums.size();
        unsigned long long mask[2] = {0, 0};

        for (int val : nums) {
            if (val > 0 && val <= 101) {
                int idx = val / 64; 
                int bit = val % 64; 
                mask[idx] |= (1ULL << bit);
            }
        }
        int start = (avg <= 0) ? 1 : (int)avg + 1;
        for (int candidate = start; candidate <= 101; candidate++) {
            int idx = candidate / 64;
            int bit = candidate % 64;
            if ((mask[idx] & (1ULL << bit)) == 0) {
                return candidate;
            }
        }
        return 101;
    }
};