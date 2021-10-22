#include <stdio.h>

inline static int max2(int a, int b) {
    return a > b ? a : b;
}

inline static int max3(int a, int b, int c) {
    if (a < b) {
        return max2(b, c);
    } else {
        return max2(a, b);
    }
}

static int helper(const int A[], int left, int right) {
    if (left == right) {
        if (A[left] > 0) {
            return A[left];
        }
        return 0;
    } 

    int mid = (right + left) >> 1;
    int maxLeftSum = helper(A, left, mid);
    int maxRightSum = helper(A, mid + 1, right);

    int maxCenterSum = 0;

    // 左边包含mid的最大和
    int maxLeftBorderSum = 0, leftBoarderSum = 0;
    for (int i = mid; i >= left; i--) {
        leftBoarderSum += A[i];
        if (leftBoarderSum > maxLeftBorderSum) {
            maxLeftBorderSum = leftBoarderSum;
        }
    }

    // 右边包含mid+1的最大和
    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int i = mid + 1; i <= right; i++) {
        rightBorderSum += A[i];
        if (rightBorderSum > maxRightBorderSum) {
            maxRightBorderSum = rightBorderSum;
        }
    }

    maxCenterSum = maxLeftBorderSum + maxRightBorderSum;
    return max3(maxLeftSum, 
                maxRightSum,
                maxCenterSum);
}

int maxSubsequenceSumV3(const int A[], int N) {
    return helper(A, 0, N - 1);
}

int maxSubsequenceSumV4(const int A[], int N) {
    int maxSum = 0;
    int thisSum = 0;
    for (int i = 0; i < N; i++) {
        thisSum += A[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        } else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    return maxSum;
}

int maxSubsequenceSumV2(const int A[], int N) {
    int thisSum, maxSum, i, j, k;
    maxSum = 0;
    for (i = 0; i < N; i++) {
        thisSum = 0;
        for (j = i; j < N; j++) {
            thisSum += A[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

int maxSubsequenceSumV1(const int A[], int N) {
    int thisSum, maxSum, i, j, k;

    maxSum = 0;
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            thisSum = 0;
            for (k = i; k <= j; k++) {
                thisSum += A[k];
            }
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }

    return maxSum;
}

int main() {
    int num[] = {4, -3, 5, -2, -1, 2, 6, -2};

    printf("%d\n", maxSubsequenceSumV1(num, 8));
    printf("%d\n", maxSubsequenceSumV2(num, 8));
    printf("%d\n", maxSubsequenceSumV3(num, 8));
    printf("%d\n", maxSubsequenceSumV4(num, 8));
    return 0;
}