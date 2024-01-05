/*#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std; npt needed for testing*/

class Solution
{
public:
    std::vector<std::string> findHighAccessEmployees(std::vector<std::vector<std::string>> &access_times)
    {
        // Store access times for each employee
        std::unordered_map<std::string, std::vector<int>> employeeAccess;

        // Populate the map with employee access times
        for (const auto &access : access_times)
        {
            // Extract employee name and their access time
            std::string employee = access[0];
            int time = std::stoi(access[1]);

            // Store access time for the corresponding employee
            employeeAccess[employee].push_back(time);
        }

        // List to store names of high-access employees
        std::vector<std::string> highAccessEmployees;

        // Iterate through employee access records
        for (auto &emp : employeeAccess)
        {
            // Check if the employee has high access based on access times
            if (hasHighAccess(emp.second))
            {
                highAccessEmployees.push_back(emp.first); // Add employee to high-access list
            }
        }

        // Sort the list of high-access employees
        std::sort(highAccessEmployees.begin(), highAccessEmployees.end());

        // Remove duplicates from the list of high-access employees
        highAccessEmployees.erase(
            std::unique(highAccessEmployees.begin(), highAccessEmployees.end()),
            highAccessEmployees.end());

        // Return the list containing names of high-access employees
        return highAccessEmployees;
    }

private:
    bool hasHighAccess(const std::vector<int> &times)
    {
        // Create a copy of access times and sort it
        std::vector<int> sortedTimes = times;
        std::sort(sortedTimes.begin(), sortedTimes.end());

        // Iterate through sorted access times to find consecutive accesses within 100 minutes
        for (size_t i = 0; i + 2 < sortedTimes.size(); ++i)
        {
            if (sortedTimes[i + 2] - sortedTimes[i] < 100)
            {
                return true; // Return true if consecutive access found within 100 minutes
            }
        }

        return false; // Return false if no such access found
    }
};

// Main function not needed for testing logic
/*
int main()
{

    Solution sol;

    vector<vector<string>> accessTimes = {

        {"d", "0002"},
        {"c", "0808"},
        {"c", "0829"},
        {"e", "0215"},
        {"d", "1508"},
        {"d", "1444"},
        {"d", "1410"},
        {"c", "0809"}};

    vector<string> result = sol.findHighAccessEmployees(accessTimes);

    for (auto emp : result)
    {
        cout << emp << " ";
    }

    return 0;
}*/
