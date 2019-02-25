#include <stdio.h>
int sum;
int m, n;
int col[10];//col[i] = 0/1 -->這行未放置 /已放置
int posSlope[20];//斜向值
int negSlope[20];
void place(int r, int queen_num, int castle_num);
int main()
{

    scanf("%d%d", &m ,&n);
    place(0, 0, 0);
    printf("%d\n", sum);

}
void place(int r, int queen_num, int castle_num)
{
    int i , j;
    if (r==m+n) {
        sum++;
    }
    else if (r<m+n){
        for (i=0; i<m+n; i++) {
            //put queen
            if (col[i]==0 && posSlope[r+i]==0 && negSlope[r-i+m+n]==0 && queen_num<m) {
                col[i] = 1;
                posSlope[r+i] = -1;
                negSlope[r-i+m+n] = -1;
                place(r+1, queen_num+1, castle_num);
                col[i] = 0;
                posSlope[r+i] = 0;
                negSlope[r-i+m+n] = 0;
            }
            //put castle
            if (col[i]==0 && posSlope[r+i]>=0 && negSlope[r-i+m+n]>=0 && castle_num<n) {
                col[i] = 1;
                posSlope[r+i]++;
                negSlope[r-i+m+n]++;
                place(r+1, queen_num, castle_num+1);
                col[i] = 0;
                posSlope[r+i]--;
                negSlope[r-i+m+n]--;
            }
        }
    }

}
