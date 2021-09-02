int longestOnes(vector<int> &nums, int k)
{
    int i = 0, j = 0, ans = 0;

    while (j < nums.size())
    {
        if (nums[j] == 0)
        {
            k--;
        }
        if (k < 0)
        {
            while (k < 0)
            {
                if (nums[i] == 0)
                    k++;
                i++;
            }
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}