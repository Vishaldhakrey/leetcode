class Solution {
    #define ll long long

    bool isVowel(char ch) {
        return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');
    }
public:
    long long beautifulSubstrings(string s, int k) {
        int n = s.size();

        unordered_map<ll, unordered_map<ll, ll>>mp;
        mp[0][0] = 1;
        ll result = 0;
        ll vowel = 0;
        ll cons = 0;

        for (auto &ch : s) {
            if (isVowel(ch)) {
                vowel += 1;
            } else {
                cons += 1;
            }

            ll psum = (vowel - cons);

            for (auto &[prevVowelCnt, cnt] : mp[psum]) {
                if (((vowel%k - prevVowelCnt)*(vowel%k - prevVowelCnt)) % k == 0) {
                    result += cnt;
                }
            }

            mp[psum][vowel%k]++;
        }
        return result;
    }
};