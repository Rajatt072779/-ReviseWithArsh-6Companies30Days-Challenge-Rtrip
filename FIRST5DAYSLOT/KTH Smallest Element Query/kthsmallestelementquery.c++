/*#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; if you want to check in command line*/

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> answer;  // To store the final answers
        int n = nums.size(); // Get the size of the nums array

        for (const auto &query : queries)
        {                        // Iterate through each query
            int k = query[0];    // k is the k-th smallest number to find
            int trim = query[1]; // trim is the number of rightmost digits to keep

            vector<pair<string, int>> trimmedIndices; // To store trimmed numbers with their original indices

            // For each number in nums, create a pair of trimmed number and its original index
            for (int i = 0; i < n; ++i)
            {
                string trimmed = nums[i].substr(nums[i].size() - trim); // Trim the number to its rightmost 'trim' digits
                trimmedIndices.emplace_back(trimmed, i);                // Store the trimmed number along with its original index
            }

            // Sort the trimmedIndices vector based on the trimmed numbers
            sort(trimmedIndices.begin(), trimmedIndices.end());

            // Find the k-th smallest trimmed number's index and store it in the answer vector
            answer.push_back(trimmedIndices[k - 1].second);
        }

        return answer; // Return the vector containing the indices of the k-th smallest trimmed numbers
    }
};
/*
int main()
{
    Solution sol;
    vector<string> nums1 = {"102", "473", "251", "814"};
    vector<vector<int>> queries1 = {{1, 1}, {2, 3}, {4, 2}, {1, 2}};
    vector<int> result1 = sol.smallestTrimmedNumbers(nums1, queries1);
    cout << "Output for Example 1: [";
    for (int i = 0; i < result1.size(); ++i)
    {
        if (i != 0)
            cout << ",";
        cout << result1[i];
    }
    cout << "]" << endl;

    vector<string> nums2 = {"24", "37", "96", "04"};
    vector<vector<int>> queries2 = {{2, 1}, {2, 2}};
    vector<int> result2 = sol.smallestTrimmedNumbers(nums2, queries2);
    cout << "Output for Example 2: [";
    for (int i = 0; i < result2.size(); ++i)
    {
        if (i != 0)
            cout << ",";
        cout << result2[i];
    }
    cout << "]" << endl;

    return 0;
} if you want to check in command line
*/