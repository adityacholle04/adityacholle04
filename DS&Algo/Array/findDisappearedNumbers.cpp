//Given an array nums of n integers where nums[i] is in the range[1, n], return an array of all the integers in the range[1, n] that do not appear in nums.
//
//
//
//Example 1:
//
//Input: nums = [4, 3, 2, 7, 8, 2, 3, 1]
//Output : [5, 6]
//Example 2 :
//
//    Input : nums = [1, 1]
//    Output : [2]
//
//
//    Constraints :
//
//    n == nums.length
//    1 <= n <= 105
//    1 <= nums[i] <= n
//
// Follow up : Could you do it without extra spaceand in O(n) runtime ? You may assume the returned list does not count as extra space.
//#####################################################################################

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {

    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int v = abs(nums[i]) - 1;
        if (nums[v] > 0)
            nums[v] = -nums[v];
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0)
            res.push_back(i + 1);
    }
    return res;

}

int main()
{
    vector<int> nums{ 1,2, };
    vector<int> ans;
    ans = findDisappearedNumbers(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    return 0;
}