//順時針的順序是 右下左上
#include <stdio.h>
int mat[35][35];
int M,N,P;
int main()
{
    int i, j;
    int r=0, c=0;
    mat[0][0] = 1;
    int num = 2;
    scanf("%d%d", &M, &N);
    scanf("%d", &P);
    if (P==1) printf("1 1\n");
    while(num<=P) {
        while (isAvailable(r, c+1)) {
            c = c+1;
            mat[r][c] = num;
            if (num==P) printf("%d %d\n", r+1, c+1);
            num++;
        }
        while (isAvailable(r+1, c)) {
            r = r+1;
            mat[r][c] = num;
            if (num==P) printf("%d %d\n", r+1, c+1);
            num++;
        }
        while (isAvailable(r, c-1)) {
            c = c-1;
            mat[r][c] = num;
            if (num==P) printf("%d %d\n", r+1, c+1);
            num++;
        }
        while (isAvailable(r-1, c)) {
            r = r-1;
            mat[r][c] = num;
            if (num==P) printf("%d %d\n", r+1, c+1);
            num++;
        }
    }

    for (i=0; i<M;i++) {
        for (j=0; j<N; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }

}
int isAvailable(int row, int col)
{
    if (row>=0&&row<M&&col>=0&&col<N&&mat[row][col]==0) {
        return 1;
    }
    else return 0;
}
