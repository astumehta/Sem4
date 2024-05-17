#include<stdio.h>
#define MAX 100

int num_items, max_weight, count;
int profits[MAX], weights[MAX];
int temp_profits[MAX], temp_weights[MAX];

void knapsack(){
    int i, j;
    int temp_count;
    int max_profit = 0;
    temp_profits[0] = 0;
    temp_weights[0] = 0;
    count = 1;
    for(i = 0; i < num_items; i++){
        temp_count = 0;
        for(j = 0; j < count; j++){
            temp_profits[temp_count] = temp_profits[j] + profits[i];
            temp_weights[temp_count] = temp_weights[j] + weights[i];
            temp_count++;
        }
        for(j = 0; j < temp_count; j++){
            if(temp_weights[j] <= max_weight){
                temp_profits[count] = temp_profits[j];
                temp_weights[count] = temp_weights[j];
                count++;
            }
        }
    }
    for (i = 0; i < count; i++) {
        if (temp_profits[i] > max_profit && temp_weights[i] <= max_weight) {
            max_profit = temp_profits[i];
        }
    }
    printf("Maximum Profit: %d\n", max_profit);
}

int main() {
    int i;
    printf("Enter number of items:\n");
    scanf("%d", &num_items);
    printf("Enter weight and profit for each item:\n");
    for (i = 0; i < num_items; i++) {
        scanf("%d %d", &weights[i], &profits[i]);
    }
    printf("Enter maximum weight capacity:\n");
    scanf("%d", &max_weight);
    knapsack();
    return 0;
}
