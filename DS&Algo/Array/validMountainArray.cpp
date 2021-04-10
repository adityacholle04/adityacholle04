//Given an array of integers arr, return true ifand only if it is a valid mountain array.
//
//Recall that arr is a mountain array ifand only if:
//
//arr.length >= 3
//There exists some i with 0 < i < arr.length - 1 such that :
//arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//	arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//
//	Example 1:
//
//Input: arr = [2, 1]
//Output : false
//Example 2 :
//
//	Input : arr = [3, 5, 5]
//	Output : false
//	Example 3 :
//
//	Input : arr = [0, 3, 2, 1]
//	Output : true
//
//
//	Constraints :
//
//	1 <= arr.length <= 104
//	0 <= arr[i] <= 104
//#####################################################################################
#include <iostream>
#include <vector>

using namespace std;

bool validMountainArray(vector<int>& A) {
    if (A.size() < 3)
    {
        return false;
    }
    bool reachedMax = false;
    bool reachedMin = false;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] > A[i - 1] && reachedMax == false)
        {
            reachedMax = false;
            reachedMin = true;
        }
        else if (A[i] == A[i - 1])
        {
            return false;
        }
        else
        {
            reachedMax = true;
            if (A[i] > A[i - 1])
            {
                return false;
            }
        }
    }
    if (reachedMax == true && reachedMin == true)
    {
        return true;
    }
    return false;
};

int main()
{
    vector<int> nums{ 3, 5, 5 };

    bool ans = validMountainArray(nums);

    cout << ans;

    return 0;
}