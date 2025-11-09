class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();

        int i=0;
        int idx = 0;
        while(i<n){
            char currChar=chars[i];
            int cnt=1;

            while(i+1<n && chars[i+1]==currChar){
                i++;
                cnt++;
            }

            chars[idx++]=currChar;
            
            if(cnt>1){
                string count=to_string(cnt);

                for(char &c:count){
                    chars[idx++]=c;
                }
            }
            i++;
        }

        return idx;
        
    }
};