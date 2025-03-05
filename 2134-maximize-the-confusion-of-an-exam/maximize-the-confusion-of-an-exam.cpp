class Solution {
public:
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();

        int trueCount = 0;
        int l=0, r=0;
        int maxConsecutiveAnswer = 0;

        while (r < n) {
            if (answerKey[r] == 'T') {
                trueCount += 1;
            }
            while (trueCount > k) {
                if (answerKey[l] == 'T') {
                    trueCount -= 1;
                }
                l++;
            }
            maxConsecutiveAnswer = max(maxConsecutiveAnswer, r-l+1);
            r++;
        }
        l=0;
        r=0;
        int falseCount = 0;

        while (r < n) {
            if (answerKey[r] == 'F') {
                falseCount += 1;
            }
            while (falseCount > k) {
                if (answerKey[l] == 'F') {
                    falseCount -= 1;
                }
                l++;
            }
            maxConsecutiveAnswer = max(maxConsecutiveAnswer, r-l+1);
            r++;
        }
        return maxConsecutiveAnswer;
    }
};