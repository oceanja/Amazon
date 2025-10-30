class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i =0; i<n; i++) {
            unordered_set<char> s1(words[i].begin(), words[i].end());

            for (int j = i + 1; j < n; j++) {
                unordered_set<char> s2(words[j].begin(), words[j].end());

                if (s1 == s2) {
                    count++;
                }
            }
        }

        return count;
    }
};
