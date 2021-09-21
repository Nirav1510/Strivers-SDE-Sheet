int singleNonDuplicate(vector<int> &nums)
{
    int low = 0, high = nums.size() - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == nums[mid ^ 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return nums[low];
}

/*

  1 1 | 2 3 3 4 4 8 8
  0 1 | 2 3 4 5 6 7 8
  
// right half
1st occurance - odd
2nd occurnce - even

left 
1st occurance - even
2nd occurance - odd


*/