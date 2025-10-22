class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int k = needle.size();
        if(k == 0) return 0;  

        for(int i = 0; i <= n - k; i++) {
            bool flag = true;
            for(int j = 0; j < k; j++) {
                if(haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }
        return -1;
    }
};
