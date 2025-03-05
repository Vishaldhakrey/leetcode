class Solution {
public:
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();

        
        int l=0;
        int r=0;
        int maxConsecutiveAnswer = 0;
        unordered_map<char, int>freq_map;

        while (r < n) {
            char ch = answerKey[r];
            freq_map[ch]++;
            while (min(freq_map['T'], freq_map['F']) > k) {
                freq_map[answerKey[l]]--;
                l++;
            }
            maxConsecutiveAnswer = max(maxConsecutiveAnswer, r-l+1);
            r++;
        }
        return maxConsecutiveAnswer;
    }
};