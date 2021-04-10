//Given two sorted integer arrays nums1and nums2, merge nums2 into nums1 as one sorted array.
//
//The number of elements initialized in nums1and nums2 are mand n respectively.You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.
//
//
//
//Example 1:
//
//Input: nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//Output : [1, 2, 2, 3, 5, 6]
//Example 2 :
//
//    Input : nums1 = [1], m = 1, nums2 = [], n = 0
//    Output : [1]
//
//
//    Constraints :
//
//    nums1.length == m + n
//    nums2.length == n
//    0 <= m, n <= 200
//    1 <= m + n <= 200
//    - 109 <= nums1[i], nums2[i] <= 109
//#####################################################################################
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] > nums2[j])
        {
            nums1.insert(nums1.begin() + i, nums2[j]);
            j++;
            m++;
            nums1.pop_back();
        }
        i++;
    }
    while (j < n)
    {
        nums1.insert(nums1.begin()+i, nums2[j]);
        nums1.pop_back();
        j++;
        i++;
    }
}

int main()
{
    vector<int> nums1{ 1, 2, 3, 0, 0, 0 };
    vector<int> nums2{ 2, 5, 6 };
    int m = 3, n = 3;
    merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }

    cout << endl;
    vector<int> nums3{ 2, 0 };
    vector<int> nums4{ 1};
    int m3 = 1, n4 = 1;
    merge(nums3,m3,nums4,n4);
    for (int i = 0; i < nums3.size(); i++)
    {
        cout << nums3[i] << " ";
    }
    cout << endl;

    vector<int> nums5{ 4, 0, 0, 0, 0, 0 };
    vector<int> nums6{ 1, 2, 3, 5, 6 };
    int m5 = 1, n6 = 5;
    merge(nums5, m5, nums6, n6);
    for (int i = 0; i < nums5.size(); i++)
    {
        cout << nums5[i] << " ";
    }
    cout << endl;

    vector<int> nums7{ 1, 2, 3, 4, 5, 0 };
    vector<int> nums8{ 6 };
    int m7 = 5, n8 = 1;
    merge(nums7, m7, nums8, n8);
    for (int i = 0; i < nums7.size(); i++)
    {
        cout << nums7[i] << " ";
    }
    cout << endl;

    return 0;
}