class Solution {
public:
    long long isPossible(vector<int>&bloomDay, int m, int k, int n, int day) {
        long long cnt = 0;
        long long no_of_banq = 0;

        for (int i=0; i<n; i++) {
            if (bloomDay[i] <= day ) {
                cnt++;
            }
            else {
                no_of_banq += (cnt/k);
                cnt = 0;
            }
        }
        no_of_banq += (cnt/k);
        
        return no_of_banq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if (n <(long) m*k) return -1;

        long long maxBloomDay = *max_element(bloomDay.begin(), bloomDay.end());

        long long left = 1;
        long long right = maxBloomDay;
        long long requiredDay = -1;
        while (left <= right) {
            long long  mid = left + (right-left)/2;
            long long banquet = isPossible(bloomDay, m, k, n, mid);

            if (banquet >= m) {
                requiredDay = mid;
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return requiredDay;
    }
};