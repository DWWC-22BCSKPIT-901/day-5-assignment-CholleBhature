#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
    {
        return findMedianSortedArrays(nums2, nums1); // Ensure nums1 is the smaller array
    }

    int m = nums1.size();
    int n = nums2.size();
    int low = 0, high = m;

    while (low <= high)
    {
        int partitionX = (low + high) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];

        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX)
        {
            if ((m + n) % 2 == 0)
            {
                return (max(maxX, maxY) + min(minX, minY)) / 2.0;
            }
            else
            {
                return max(maxX, maxY);
            }
        }
        else if (maxX > minY)
        {
            high = partitionX - 1;
        }
        else
        {
            low = partitionX + 1;
        }
    }

    throw invalid_argument("Input arrays are not sorted or invalid.");
}

int main()
{
    int m, n;
    cout << "Enter the size of the first array: ";
    cin >> m;
    vector<int> nums1(m);
    cout << "Enter the elements of the first sorted array:\n";
    for (int i = 0; i < m; ++i)
    {
        cin >> nums1[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> n;
    vector<int> nums2(n);
    cout << "Enter the elements of the second sorted array:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums2[i];
    }

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "The median of the two sorted arrays is: " << median << endl;

    return 0;
}
