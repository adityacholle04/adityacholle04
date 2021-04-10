//Given integer array nums, return the third maximum number in this array.If the third maximum does not exist, return the maximum number.
//Example 1:
//
//Input: nums = [3, 2, 1]
//Output : 1
//Explanation : The third maximum is 1.
//Example 2 :
//
//    Input : nums = [1, 2]
//    Output : 2
//    Explanation : The third maximum does not exist, so the maximum(2) is returned instead.
//    Example 3 :
//
//    Input : nums = [2, 2, 3, 1]
//    Output : 1
//    Explanation : Note that the third maximum here means the third maximum distinct number.
//    Both numbers with value 2 are both considered as second maximum.
//
//
//    Constraints :
//
//    1 <= nums.length <= 104
//    - 231 <= nums[i] <= 231 - 1
//
//
//    Follow up : Can you find an O(n) solution ?
//#####################################################################################

#include <iostream>
#include <vector>
#include<climits>

using namespace std;

int thirdMax(vector<int>& nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    if (nums.size() == 2)
    {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }
    long int m1 = LONG_MIN, m2 = LONG_MIN, m3 = LONG_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == m1 || nums[i] == m2 || nums[i] == m3)
        {
            continue;
        }
        if (nums[i] > m3)
        {
            m1 = m2;
            m2 = m3;
            m3 = nums[i];
        }
        else if (nums[i] > m2)
        {
            m1 = m2;
            m2 = nums[i];
        }
        else if (nums[i] > m1)
        {
            m1 = nums[i];
        }
    }
    if (m1 != LONG_MIN)
    {
        return m1;
    }    
    else 
    {
        return m3;
    }

}

int main()
{
    vector<int> nums{ 1,2,-2147483648 };
    int ans;
    ans = thirdMax(nums);
    cout << ans;
    return 0;
}