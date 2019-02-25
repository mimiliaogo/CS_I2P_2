#include <stdio.h>
#include <string.h>
int m, n, p;
int map[30][30];
int isAvailable(int row, int col)
{
    if (row>=0&&row<m&&col>=0&&col<n&&(map[row][col]==0)) {
        return 1;
    }
    else return 0;
}
int main()
{

    int dir = 0;// 0 1 2 3 right down left up
    int r, c;

    int i, j;
    int num = 1;
    memset(map, 0, sizeof(map));
    scanf("%d%d", &m, &n);
    scanf("%d", &p);
    r = 0;
    c = 0;
    map[0][0] = 1;

    while (num<p) {
        switch (dir) {
            case 0://right
                if (isAvailable(r, c+1))  {
                    c = c+1;
                    num++;
                }
                else dir ++;
                break;
            case 1://down
                if (isAvailable(r+1, c)) {
                    r++;
                    num++;
                }
                else dir ++;
                break;
            case 2://left
                if (isAvailable(r, c-1))  {
                    c--;
                    num++;
                }
                else dir ++;
                break;
            case 3://up
                if (isAvailable(r-1, c)) {
                    r--;
                    num++;
                }
                else dir ++;
                break;
        }
        map[r][c] = 1;
        if (dir>3) dir = dir % 4;


    }
    printf("%d %d\n", r+1, c+1);


}
