class Solution
{
    public:
    void rotateMatrix(vector<vector<int>> &arr, int n)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            reverse(arr[i].begin(), arr[i].end());
        }

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
};