#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1)*/
int maxProfit(vector<int>& prices) {
    int minimum = prices[0];
    int profit = 0;
    int max_profit = 0;
    for (int price : prices) {
        profit = price - minimum;
        max_profit = max(profit, max_profit);
        if (price < minimum) {
            minimum = price;
        }
    }
    return max_profit;
}

int main() {

    // Example input
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Call the function
    int result = maxProfit(prices);

    // Print the result
    cout << "Maximum Profit: " << result;
    return 0;
}
