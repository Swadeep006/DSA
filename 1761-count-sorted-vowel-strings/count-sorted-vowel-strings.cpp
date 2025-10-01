class Solution {
public:
    int sumtotal(vector<int> res) {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += res[i];
        }
        return sum;
    }
    int countVowelStrings(int n) {
        vector<int> res(5, 1);
        int totalSum = 0;
        for (int i = 0; i < n-1; i++) {
            totalSum = sumtotal(res);
            for (int j = 0; j < 5; j++) {
                int k = res[j];
                res[j] = totalSum;
                totalSum -= k;
            }
        }
        return sumtotal(res);
    }
};