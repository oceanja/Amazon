class Solution {
public:
    int countCollisions(string directions) {
        // RLRSLL +2
        // SSRSLL +1
        // SSSSLL +1
        // SSSSSL +1
        // SSSSSS

        int n=directions.length();
        int collisions=0;

        stack<char> st;

        for(int i=0;i<n;i++){
        char curr = directions[i];

         while(!st.empty()){

            if((st.top()=='R' &&  curr=='L')){
                collisions+=2;
                st.pop();
                curr='S';
            }
            else if(st.top()=='R' && curr=='S'){
                collisions+=1;
                st.pop();
                curr='S';
            }
            else if(st.top()=='S' && curr=='L'){
                collisions+=1;
                curr='S';
                st.pop();
            }
            else{
                break;
            } 
        }

        st.push(curr);

        }

        return collisions;

   

        
    }
};