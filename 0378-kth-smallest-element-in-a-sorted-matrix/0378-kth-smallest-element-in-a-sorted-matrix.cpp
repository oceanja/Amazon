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


// ************************ OPTIMIZED********************************
class Solution {
public:

int count(int mid,vector<vector<int>>& matrix){

    int n=matrix.size();
    int cnt=0;

    int row=n-1;
    int col=0;

    while(row>=0 && col<n){
        if(matrix[row][col]<=mid){
            cnt+=(row+1);
            col++;
        }
        else{
            row--;
        }
    }

    return cnt;

}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        //      c0  c1  c2
        //  r0  1   5  9
        // r1   10 11 13
        //  r2  12 13 15

        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        int ans=matrix[0][0];

        while(low<=high){
            int mid=low+(high-low)/2;

            if(count(mid,matrix)>=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }

        return ans;

        
    }
};
