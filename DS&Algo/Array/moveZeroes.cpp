//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
//Note that you must do this in - place without making a copy of the array.
//
//
//
//Example 1:
//
//Input: nums = [0, 1, 0, 3, 12]
//Output : [1, 3, 12, 0, 0]
//Example 2 :
//
//    Input : nums = [0]
//    Output : [0]
//
//
//    Constraints :
//
//    1 <= nums.length <= 104
//    - 231 <= nums[i] <= 231 - 1
//
//
//    Follow up : Could you minimize the total number of operations done ?
//#####################################################################################
#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums)
{
    if (nums.size() == 0 || nums.size() == 1)
    {
        return;
    }
    int i = 0;
    while ( i < nums.size())
    {
        if (nums[i] != 0)
        {
            i++;
        }
        else {
            break;
        } 
    }
    for (int j = i + 1; j < nums.size(); j++)
    {
        if (nums[i] == 0 && nums[j] != 0)
        {
            nums[i] = nums[j];
            nums[j] = 0;
            i++;
            while (i < nums.size())
            {
                if (nums[i] != 0)
                {
                    i++;
                }
                else 
                {
                    break;
                }
            }
            j = i;
        }
    }
}

int main()
{
    vector<int> nums{ 0,1,0,3,12 };
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}