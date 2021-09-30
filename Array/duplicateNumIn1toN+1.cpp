int findDuplicate(vector<int> &nums)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int slow = nums[0];
    int fast = nums[0];
    while (true)
    {

        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)
            break;
    }
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}