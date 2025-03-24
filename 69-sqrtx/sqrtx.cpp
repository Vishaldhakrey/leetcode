class Solution {
public:
    int mySqrt(int x) {
        int result = 0;

        for (int i=1; i<=x; i++) {
            if ((long)i*i <= x) {
                result = i;
            }
            else {
                break;
            }
        }
        return result;
    }
};