class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.length();
        int m=part.length();

        int i=0;
        while(i<=n-m){
            int j=0;
            while(j<m && s[i+j]==part[j]){
                j++;
            }
            if(j==m){
                s.erase(i,m);
                i=max(0,i-m);
            }
            else{
                i++;
            }
        }

        return s;

        
    }
};