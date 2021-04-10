//Given an integer array nums sorted in non - decreasing order, return an array of the squares of each number sorted in non - decreasing order.
//Example 1:
//Input: nums = [-4, -1, 0, 3, 10]
//Output : [0, 1, 9, 16, 100]
//Explanation : After squaring, the array becomes[16, 1, 0, 9, 100].
//After sorting, it becomes[0, 1, 9, 16, 100].
//Example 2 :
//
//    Input : nums = [-7, -3, 2, 3, 11]
//    Output : [4, 9, 9, 49, 121]
//
//
//    Constraints :
//
//    1 <= nums.length <= 104
//    - 104 <= nums[i] <= 104
//    nums is sorted in non - decreasing order.
//
//
//    Follow up : Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach ?
//#####################################################################################
#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int>& A)
{
    int j = A.size() - 1;
    for (int i = 0; i < j; )
    {
        int a = abs(A[i]);
        int b = abs(A[j]);
        if ( a > b)
        {
            vector<int>::iterator it;
            it = A.begin();
            it = it + i;
            int temp = A[i];
            A.erase(it);
            A.insert((A.begin()+j), temp);
        }
        else
        {
            j--;
        }
    }

    for (int i = 0; i < A.size(); i++)
    {
        A[i] = A[i] * A[i];
    }
    return A;

}

int main()
{
    vector<int> nums{ -7, -3, 2, 3, 11 };
    vector<int> ans;

    ans = sortedSquares(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i]<<endl;
    }

    return 0;
}