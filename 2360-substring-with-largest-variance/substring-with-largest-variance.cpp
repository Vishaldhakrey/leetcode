class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();

        vector<int>freq(26, 0);

        for (auto &ch : s) {
            freq[ch - 'a']++;
        }

        int result = 0;

        for (char first = 'a'; first <= 'z'; ++first) {
            for (char second = 'a'; second <= 'z'; ++second) {
                if (freq[first - 'a'] == 0 || freq[second - 'a'] == 0) {
                    continue;
                }

                int firstCnt = 0;
                int secondCnt = 0;
                bool pastLowFreq = false;


                for (auto &ch : s) {
                    if (ch == first) firstCnt++;
                    if (ch == second) secondCnt++;

                    if (secondCnt > 0) {
                        result = max(result, firstCnt - secondCnt);
                    } else {
                        if (pastLowFreq) {
                            result = max(result, firstCnt - 1);
                        }
                    }

                    if (secondCnt > firstCnt) {
                        firstCnt = 0;
                        secondCnt = 0;
                        pastLowFreq = true;
                    }
                }
            }
        } 
            return result;
    }
};