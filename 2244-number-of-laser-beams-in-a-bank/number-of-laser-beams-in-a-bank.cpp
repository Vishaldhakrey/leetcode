class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();

        int preDeviceCnt = 0;
        int result = 0;

        for (int i=0; i<n; i++) {

            int currDeviceCnt = 0;
            for (auto &ch : bank[i]) {
                if (ch == '1') {
                    currDeviceCnt++;
                }
            }

            result += currDeviceCnt*preDeviceCnt;

            if (currDeviceCnt != 0) {
                preDeviceCnt = currDeviceCnt;
            }
        }

        return result;
    }
};