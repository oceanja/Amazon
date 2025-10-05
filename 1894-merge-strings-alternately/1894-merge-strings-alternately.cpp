class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        string ans="";
        bool flag=true;

        int i=0;
        int j=0;

        while(i<n && j<m){
            if(flag){
                ans+=word1[i];
                flag=!flag;
                i++;
            }

            else{
                ans+=word2[j];
                flag=!flag;
                j++;
            }

        }

        while(i<n){
            ans+=word1[i];
            i++;
        }
        while(j<m){
            ans+=word2[j];
            j++;
        }

        return ans;
        
    }
};