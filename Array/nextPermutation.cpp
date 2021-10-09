class Solution
{
    public:
    vector<int> nextPermutation(int n, vector<int> arr)
    {
        int i = n - 2;
        while (i >= 0 && arr[i] >= arr[i + 1])
            i--;

        if (i >= 0)
        {
            int j = n - 1;
            while (j >= 0 && arr[i] >= arr[j])
                j--;
            swap(arr[i], arr[j]);
        }
        reverse(arr.begin() + i + 1, arr.end());
        return arr;
    }
};