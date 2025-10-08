class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        string hint = "";

        int bulls = 0;
        int cows = 0;

        unordered_map<char, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[secret[i]]++;
        }

     
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                mpp[guess[i]]--; 
            }
        }

    
        for (int i = 0; i < n; i++) {
            if (secret[i] != guess[i] && mpp[guess[i]] > 0) {
                cows++;
                mpp[guess[i]]--; 
            }
        }

        hint += to_string(bulls) + "A" + to_string(cows) + "B";
        return hint;
    }
};
