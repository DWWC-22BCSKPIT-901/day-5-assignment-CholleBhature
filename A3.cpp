#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    int kthSmallestSum(vector<vector<int>> &mat, int k)
    {
        int m = mat.size(), n = mat[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        set<vector<int>> seen;

        vector<int> init(m, 0);
        int initialSum = 0;
        for (int i = 0; i < m; ++i)
        {
            initialSum += mat[i][0];
        }

        vector<int> initialState = {initialSum};
        initialState.insert(initialState.end(), init.begin(), init.end());
        pq.push(initialState);
        seen.insert(init);

        while (k--)
        {
            auto curr = pq.top();
            pq.pop();

            int sum = curr[0];
            vector<int> indices(curr.begin() + 1, curr.end());

            if (k == 0)
                return sum;

            for (int i = 0; i < m; ++i)
            {
                if (indices[i] + 1 < n)
                {
                    auto next = indices;
                    next[i]++;
                    if (seen.insert(next).second)
                    {
                        int newSum = sum - mat[i][indices[i]] + mat[i][next[i]];
                        vector<int> nextState = {newSum};
                        nextState.insert(nextState.end(), next.begin(), next.end());
                        pq.push(nextState);
                    }
                }
            }
        }

        return -1; // Should not reach here
    }
};

int main()
{
    Solution solution;

    // Take input from the user
    int m, n, k;
    cout << "Enter the number of rows in the matrix: ";
    cin >> m;
    cout << "Enter the number of columns in the matrix: ";
    cin >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter the elements of the matrix row by row: \n";
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = solution.kthSmallestSum(mat, k);
    cout << "The " << k << "th smallest sum of the matrix is: " << result << endl;

    return 0;
}
