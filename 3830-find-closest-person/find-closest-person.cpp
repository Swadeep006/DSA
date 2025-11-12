class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distxz = abs(x-z);
        int distyz = abs(y-z);
        if(distxz == distyz) return 0;
        if(distyz > distxz) return 1;
        else return 2;
    }
};