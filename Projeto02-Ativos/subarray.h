#include <limits.h>

// Função para encontrar o subarray máximo que cruza o meio do array
void FindMaxCrossingSubArray(int arr[], int low, int mid, int high, int* max_left, int* max_right, int* max_sum) {
    int left_sum = INT_MIN;
    int sum = 0;
    *max_left = mid;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            *max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    *max_right = mid + 1;

    for (int j = mid + 1; j <= high; j++) {
        sum += arr[j];
        if (sum > right_sum) {
            right_sum = sum;
            *max_right = j;
        }
    }

    *max_sum = left_sum + right_sum;
}

// Função recursiva para encontrar o subarray máximo
void FindMaxSubArray(int arr[], int low, int high, int* max_low, int* max_high, int* max_sum) {
    if (low == high) {
        *max_low = low;
        *max_high = high;
        *max_sum = arr[low];
    } else {
        int mid = (low + high) / 2;

        int left_low, left_high, left_sum;
        FindMaxSubArray(arr, low, mid, &left_low, &left_high, &left_sum);

        int right_low, right_high, right_sum;
        FindMaxSubArray(arr, mid + 1, high, &right_low, &right_high, &right_sum);

        int cross_low, cross_high, cross_sum;
        FindMaxCrossingSubArray(arr, low, mid, high, &cross_low, &cross_high, &cross_sum);

        if (left_sum >= right_sum && left_sum >= cross_sum) {
            *max_low = left_low;
            *max_high = left_high;
            *max_sum = left_sum;
        } else if (right_sum >= left_sum && right_sum >= cross_sum) {
            *max_low = right_low;
            *max_high = right_high;
            *max_sum = right_sum;
        } else {
            *max_low = cross_low;
            *max_high = cross_high;
            *max_sum = cross_sum;
        }
    }
}
