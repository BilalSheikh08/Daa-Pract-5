#include <stdio.h>
#include <string.h>


void show(char *a, char *b, int val[100][100], int m, int n) {
    int i,j;
    printf("\nmatrix \n   ");
    for(j=0;j<n;j++) {
        printf(" %c ", b[j]);
    }
    printf("\n");
    for(i=0;i<=m;i++) {
        if(i==0) printf("  ");
        else printf("%c ", a[i-1]);
        for(j=0;j<=n;j++) {
            printf("%d ", val[i][j]);
        }
        printf("\n");
    }
}


void lcs(char *a, char *b) {
    int m=strlen(a), n=strlen(b);
    int val[100][100];
    char dir[100][100];
    int i,j;


    for(i=0;i<=m;i++) {
        for(j=0;j<=n;j++) {
            if(i==0||j==0) {
                val[i][j]=0;
                dir[i][j]='0';
            } 
            else if(a[i-1]==b[j-1]) {
                val[i][j]=val[i-1][j-1]+1;
                dir[i][j]='d'; 
            } 
            else {
                if(val[i-1][j]>=val[i][j-1]) {
                    val[i][j]=val[i-1][j];
                    dir[i][j]='u'; 
                } else {
                    val[i][j]=val[i][j-1];
                    dir[i][j]='l'; 
                }
            }
        }
    }


    show(a,b,val,m,n);


    int k=val[m][n];
    char ans[100];
    ans[k]='\0';


    i=m; j=n;
    while(i>0 && j>0) {
        if(dir[i][j]=='d') {
            ans[k-1]=a[i-1];
            i--; j--; k--;
        } else if(dir[i][j]=='u') {
            i--;
        } else {
            j--;
        }
    }


    printf("\nLCS len = %d\n", (int)strlen(ans));
    printf("LCS is: %s\n", ans);
}


int main() {
   
    char a[]="AGCCCTAAGGGCTACCTAGCTT"; 
    char b[]="GACAGCCTACAAGCGTTAGCTTG";


    printf("Task1: LCS\n");
    lcs(a,b);


    
    return 0;
}
