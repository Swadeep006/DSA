class Solution {
public:
    bool helper(string& s, int index, int sum, int orgsum) {
        if (sum == orgsum / 2) {
            return true;
        }
        if (index >= s.length()) { 
            return false;
        }
        return helper(s, index + 1, sum + (int(s[index] - 'a' + 1)), orgsum);
    }
    bool scoreBalance(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += int(s[i] - 'a' + 1);
        }
        if(sum%2!=0) return false;
        return helper(s, 0, 0, sum);
    }
};