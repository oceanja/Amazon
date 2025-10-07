class Solution {
public:
    int maximumSwap(int num) {
        // 2 7 3 6
        // 7 2 3 6
        // 9 9 7 3 
        // 9 9 7 3 
        // 2 5 3 6
        // 

        string number = to_string(num);
        int n = number.length();
        for (int i = 0; i < n; i++) {
            int maxiIndex = -1; 
            for (int j = i + 1; j < n; j++) {
                
                if (number[j] > number[i]) {
                    if (maxiIndex == -1 || number[j] >= number[maxiIndex]) {
                        maxiIndex = j;
                    }
                }
            }
            if (maxiIndex != -1) {
                swap(number[i], number[maxiIndex]);
                break;
            }
        }

        int newNum = stoi(number);
        return newNum;
    }
};