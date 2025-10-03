#include <stdio.h>
#include <string.h>

int findLRS(char str[]) {
    int n = strlen(str);
    int dp[n+1][n+1];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            dp[i][j] = 0;
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(str[i-1] == str[j-1] && i != j) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    return dp[n][n];
}

/* Output:
Length of LRS = 3
Longest Repeating Subsequence is: ABD
*/

void printLRS(char str[]) {
    int n = strlen(str);
    int dp[n+1][n+1];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }
            else if(str[i-1] == str[j-1] && i != j) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    int index = dp[n][n];
    char lrs[index+1];
    lrs[index] = '\0';

    int i=n, j=n;
    while(i>0 && j>0) {
        if(str[i-1] == str[j-1] && i != j) {
            lrs[index-1] = str[i-1];
            i--; j--; index--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Repeating Subsequence is: %s\n", lrs);
}

int main() {
    char s[] = "AABEBCDD";

    int length = findLRS(s);
    printf("Length of LRS = %d\n", length);

    printLRS(s);

    return 0;
}

