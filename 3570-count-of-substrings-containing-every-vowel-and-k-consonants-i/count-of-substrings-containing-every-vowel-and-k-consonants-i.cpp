#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'));
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();

        vector<int>nextCons(n);
        int idx = n;
        for (int i=n-1; i>=0; i--) {
            nextCons[i] = idx;
            if (!isVowel(word[i])) {
                idx = i;
            }
        }

        unordered_map<char, int>freq;

        long long cnt  = 0;
        int cons = 0;
        int l = 0, r = 0;

        while (r < n) {
            char ch = word[r];

            if (isVowel(ch)) {
                freq[ch]++;
            }
            else {
                cons++;
            }

            while (cons > k) {
                char ch_left = word[l];
                if (isVowel(ch_left)) {
                    freq[ch_left]--;
                    if (freq[ch_left] == 0) {
                        freq.erase(ch_left);
                    }
                }
                else {
                    cons--;
                }
                l++;
            }

            while (l < n && freq.size()==5 && cons == k) {
                int indx = nextCons[r];
                cnt += indx-r;

                char ch_left = word[l];
                if (isVowel(ch_left)) {
                    freq[ch_left]--;
                    if (freq[ch_left] == 0) {
                        freq.erase(ch_left);
                    }
                }
                else {
                    cons--;
                }
                l++;
            }
            r++;
        }
        return cnt;
    }
};