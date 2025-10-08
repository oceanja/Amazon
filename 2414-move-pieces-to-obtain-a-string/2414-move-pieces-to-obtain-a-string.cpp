class Solution {
public:
    bool canChange(string start, string target) {
        // _L__R__R_
        // L___R__R_
        // L___R___R
        // L______RR
        int n=start.length();
        int i=0;
        int j=0;

        while(i<n && j<n ){
            while(i<n && start[i]=='_') i++;
            while(j<n && target[j]=='_') j++;

            if(i==n || j==n){
                break; // early exhaust
            }

            if(start[i]!=target[j]){
                return false;
            }

            if(start[i]=='L' && i<j) return false;
            if(start[i]=='R' && i>j) return false;

            i++;
            j++;


        }

        while (i < n) {
            if (start[i] != '_') return false;
            i++;
        }

  
        while (j < n) {
            if (target[j] != '_') return false;
            j++;
        }

        return true;

    }
};