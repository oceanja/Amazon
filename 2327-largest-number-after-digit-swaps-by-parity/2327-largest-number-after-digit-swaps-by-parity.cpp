class Solution {
public:
    int largestInteger(int num) {
       // 65875
       // 87655
       vector<int> even;
       vector<int> odd;
       string s=to_string(num);

       for(char ch:s){
        int digit=ch-'0';
        if(digit%2==0){
            even.push_back(digit);
        }
        else{
            odd.push_back(digit);
        }

       }
       sort(even.rbegin(),even.rend()); // 8 6
       sort(odd.rbegin(),odd.rend());   // 7 5 5
       int evenidx=0;
       int oddidx=0;


      for(int i=0;i<s.length();i++){
        int d=s[i]-'0';
        if(d%2==0){
            s[i]='0'+even[evenidx++];
            
        }
        else{
            s[i]='0'+odd[oddidx++];
            
        }
      }

      return stoi(s);




        
    }
};