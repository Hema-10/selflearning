int getMaxProfit(int prices[], int size) {
    int maxProfit = prices[1] - prices[0];
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            int profit = prices[j] - prices[i];
            if (profit > maxProfit) maxProfit = profit;
        }
    }
    return maxProfit;
}
