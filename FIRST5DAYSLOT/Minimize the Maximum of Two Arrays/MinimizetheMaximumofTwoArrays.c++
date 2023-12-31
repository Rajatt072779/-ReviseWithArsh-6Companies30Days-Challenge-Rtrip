#include <climits>
#include <cstdint>
#include <iostream> //(if want to check through output)
class Solution
{
    long long getGCD(long long a, long long b)
    {
        if (b == 0)
            return a;
        return getGCD(b, a % b);
    }

public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {
        long long ans = LLONG_MAX;
        long long low = 1, high = LLONG_MAX;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2; // Using a different calculation for 'mid'

            long long total1 = mid - mid / divisor1;
            long long total2 = mid - mid / divisor2;

            long long gcd = getGCD(divisor1, divisor2);
            long long lcm = (divisor1 / gcd) * divisor2;

            long long temp = mid - mid / lcm;

            if (total1 >= uniqueCnt1 && total2 >= uniqueCnt2 && temp >= uniqueCnt1 + uniqueCnt2)
            {
                high = mid - 1;
                ans = mid; // Updated to assign 'mid' directly without modifying it further
            }
            else
            {
                low = mid + 1;
            }
        }

        return static_cast<int>(ans);
    }
};
int main()
{
    Solution solution;

    // Test Case 1
    int divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3;
    int result1 = solution.minimizeSet(divisor1, divisor2, uniqueCnt1, uniqueCnt2);
    std::cout << "Test Case 1 Result: " << result1 << std::endl;

    // Test Case 2
    int divisor3 = 3, divisor4 = 5, uniqueCnt3 = 2, uniqueCnt4 = 1;
    int result2 = solution.minimizeSet(divisor3, divisor4, uniqueCnt3, uniqueCnt4);
    std::cout << "Test Case 2 Result: " << result2 << std::endl;

    // Add more test cases as needed...

    return 0;
} /*to check through output?*/