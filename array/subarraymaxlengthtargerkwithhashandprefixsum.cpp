#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> prefixMap; // prefix_sum → first index
        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            if (prefixSum == k) {
                maxLen = i + 1;
            }

            if (prefixMap.find(prefixSum - k) != prefixMap.end()) {
                maxLen = max(maxLen, i - prefixMap[prefixSum - k]);
            }

            // store only first occurrence of a prefixSum
            if (prefixMap.find(prefixSum) == prefixMap.end()) {
                prefixMap[prefixSum] = i;
            }
        }

        return maxLen;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, -1, 5, -2, 3}; // Example input
    int k = 3; // Target sum
    int maxLength = solution.maxSubArrayLen(nums, k);
    
    cout << "The maximum length of a subarray with sum " << k << " is: " << maxLength << endl; // Output the result
    
    return 0;
}