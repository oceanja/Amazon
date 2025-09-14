class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long totalSum = 0;
        unordered_map<int, int> mpp;

        for (int num : nums) {
            totalSum += num;
            mpp[num] += 1;
        }

        int maxOutlier = INT_MIN;
        for (int num : nums) {
            long long requiredSum = totalSum - num;
            if (requiredSum % 2 != 0) continue;

            long long potentialSum = requiredSum / 2;
            mpp[num] -= 1;
            int sumElement = potentialSum;
            int count = mpp.count(sumElement) ? mpp[sumElement] : 0;
            if (count > 0) maxOutlier = max(maxOutlier, num);
            mpp[num] += 1;
        }

        return maxOutlier;
    }
}; 