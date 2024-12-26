#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxChunksToSorted(vector<int> &arr)
{
    int n = arr.size();

    // Create an array to store the minimum value from the right
    vector<int> minRight(n);
    minRight[n - 1] = arr[n - 1];

    // Fill the minRight array
    for (int i = n - 2; i >= 0; --i)
    {
        minRight[i] = min(arr[i], minRight[i + 1]);
    }

    // Initialize variables
    int maxLeft = arr[0];
    int chunks = 0;

    // Traverse through the array and count valid splits
    for (int i = 0; i < n - 1; ++i)
    {
        maxLeft = max(maxLeft, arr[i]);
        if (maxLeft <= minRight[i + 1])
        {
            chunks++;
        }
    }

    // Add the last chunk
    return chunks + 1;
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    cout << maxChunksToSorted(arr) << endl; // Output: 1
    return 0;
}
