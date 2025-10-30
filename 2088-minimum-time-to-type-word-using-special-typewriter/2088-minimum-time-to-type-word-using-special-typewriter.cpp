class Solution {
public:
    int minTimeToType(string word) {
        int n=word.length();
        int cnt=0;
        char pointer='a';

        for(int i=0;i<n;i++){
            int steps=abs(word[i]-pointer);
            cnt+=min(steps,26-steps)+1;
            pointer=word[i];
        }

        return cnt;


        
    }
};