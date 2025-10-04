class Solution {
public:
    int countPairs(vector<int>& deliciousness) {

        const int MOD = 1000000007;
        unordered_map<int,int> cnt;
        long long ans = 0;

        for (int x : deliciousness) {
            for (int i = 0; i <= 21; ++i) {
                int power = 1 << i;
                int need = power - x;
                auto it = cnt.find(need);
                if (it != cnt.end()) ans = (ans + it->second) % MOD;
            }
            cnt[x]++; 
        }
        return (int)ans;
        
    }
};