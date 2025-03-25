
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;
    for (int i = 0; i < pricesSize; i++){
        for (int j = i+1; j < pricesSize; j++){
            // prices[i] must be decrease by the prices[j] if j > i and price of jth item < price of ith item
            if (prices[j] <= prices[i]){
                prices[i] -= prices[j];
                break;
            }
        }
    }
    return prices;
}
