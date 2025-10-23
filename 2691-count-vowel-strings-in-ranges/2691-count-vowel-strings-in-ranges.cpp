class Solution {
public:
bool checkVowel(char ch){
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o'|| ch=='u');
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int Q=queries.size();
        int N=words.size();

        vector<int> helper(N);
        vector<int> result;
        int s=0;

        for(int i=0;i<N;i++){
            string word=words[i];
            if (checkVowel(word.front()) && checkVowel(word.back())) s++;
helper[i] = s;
        }
        // 0 1 2 3 4
        // 1 1 2 3 4

        for(auto &query:queries){
            int l=query[0];
            int r=query[1];

            int noOfstrings=helper[r]-(l-1>=0?helper[l-1]:0);
            result.push_back(noOfstrings);

        }

        return result;


        
    }
};