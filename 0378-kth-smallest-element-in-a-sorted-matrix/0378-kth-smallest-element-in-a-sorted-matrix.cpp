class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
       priority_queue<tuple<int, int, int>,
                            vector<tuple<int, int, int>>,
                            greater<tuple<int, int, int>>> minHeap;
        //      c0  c1  c2
        //  r0  1   5  9
        // r1   10 11 13
        //  r2  12 13 15

        for(int r=0;r<n;r++){
            minHeap.push({matrix[r][0],r,0});
        }

        for(int i=0;i<k-1;i++){
            auto [val,r,c]=minHeap.top();
            minHeap.pop();

            if(c+1<n){
                minHeap.push({matrix[r][c+1],r,c+1});
            }
        }

       
    int el = get<0>(minHeap.top());

    return el;


        
    }
};