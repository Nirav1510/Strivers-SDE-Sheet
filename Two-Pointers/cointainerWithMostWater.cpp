int maxArea(vector<int> &height)
{
    int area = 0;
    int i = 0, j = height.size() - 1;
    while (i < j)
    {
        area = max(area, (j - i) * min(height[i], height[j]));

        if (height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return area;
}