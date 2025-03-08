class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int satisfied      = 0;
        int unsatisfied    = 0;
        int maxUnsatisfied = 0;

        int l=0, r=0;
        while (r < n) {
            if (grumpy[r] == 1) {
                unsatisfied += customers[r];
            }
            else  {
                satisfied += customers[r];
            }

            maxUnsatisfied = max(maxUnsatisfied, unsatisfied);
            
            if ((r-l+1) == minutes) {
                if (grumpy[l] == 1) {
                    unsatisfied -= customers[l];
                }
                l++;
            }
            r++;
        }
        return satisfied + maxUnsatisfied;
    }
};