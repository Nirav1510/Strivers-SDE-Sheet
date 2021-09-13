/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    static bool compare(struct Item i1, struct Item i2)
    {
        double vw1 = (double)i1.value / i1.weight;
        double vw2 = (double)i2.value / i2.weight;

        return vw1 > vw2;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, compare);

        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= W)
            {
                ans += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                double valperWt = (double)arr[i].value / arr[i].weight;
                ans += valperWt * W;
                break;
            }
        }
        return ans;
    }
};