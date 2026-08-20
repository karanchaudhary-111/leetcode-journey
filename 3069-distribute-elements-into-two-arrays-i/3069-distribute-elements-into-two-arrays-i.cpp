#include <vector>

using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;

        // Step 1: Initialize first two operations
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        // Step 2: Distribute remaining elements based on last appended values
        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // Step 3: Concatenate arr2 into arr1
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};