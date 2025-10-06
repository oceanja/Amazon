class Solution {
public:
typedef pair<int,char> P;
    string reorganizeString(string s) {

        int n=s.length();
      
        vector<int> count(26,0);

        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }

        priority_queue<P> pq; 

        for(char ch='a' ; ch<='z'; ch++){
            if (count[ch-'a'] > 0) {
                pq.push({count[ch-'a'],ch});
            }
        }

        string result="";

        while(pq.size() >= 2){
            auto P1=pq.top();
            pq.pop();
            auto P2=pq.top();
            pq.pop();

            result.push_back(P1.second); 
            P1.first--;      
            
            result.push_back(P2.second); 
            P2.first--;            
            
            if(P1.first>0){
                pq.push(P1);
            }
            if(P2.first>0){
                pq.push(P2);
            }
        }

        if(!pq.empty()){
            if (pq.top().first > 1) {
                return ""; 
            }
            result.push_back(pq.top().second);
        }
        
        return result;
    }
};