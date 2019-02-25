/*
皇后可放置條件

1.該行無放置

2.斜向無放置

3.有剩餘皇后



城堡可放置條件

1.該行無放置

2.斜向無皇后 (可以有城堡)

3.有剩餘城堡



判斷第二項的方法為

若放置皇后，則該斜向值為-1

若放置城堡，則每放一個斜向+1



若斜向值 = 0 ，可任意放置




若斜向值 > 0 ，只可放城堡

若斜向值 < 0 (-1) ，不可放置



放置前設定行值及斜向值

跳出後回復原狀



否

答案+1



posSlope  每增加一列，行數要-1

=> 行 + 列 = 定值



negSlope 每增加一列，行數要+1

=> 行數 - 列數 = 定值   (但可能減出來是負的，故加M+N來維持其正值)

*/

#include <bits/stdc++.h>

using namespace std;

int M, N, ans;

bool col[10];
int posSlope[20], negSlope[20];

void setMap(int row, int queenNum, int rookNum);

int main()
{
    while(cin >> M >> N)
    {
        //initialize
        memset(col, true, 10);
        memset(posSlope, 0, sizeof(posSlope));
        memset(negSlope, 0, sizeof(negSlope));

        ans = 0;
        setMap(0, 0, 0);

        cout << ans << endl;
    }

    return 0;
}

void setMap(int row, int queenNum, int rookNum)
{
    if(row < M+N)
    {
        for(int i = 0; i<M+N; i++)
        {
            if(col[i] && posSlope[i+row] == 0 && negSlope[i-row + M+N] == 0 && queenNum < M)
            {
                col[i] = false;
                posSlope[i+row] = -1;
                negSlope[i-row+M+N] = -1;
                setMap(row+1, queenNum+1, rookNum);
                col[i] = true;
                posSlope[i+row] = 0;
                negSlope[i-row+M+N] = 0;
            }

            if(col[i] && posSlope[i+row]>=0 && negSlope[i-row + M+N]>=0 && rookNum < N)
            {
                col[i] = false;
                posSlope[i+row]++;
                negSlope[i-row+M+N]++;
                setMap(row+1, queenNum, rookNum+1);
                col[i] = true;
                posSlope[i+row]--;
                negSlope[i-row+M+N]--;
            }
        }
    }
    else
        ans++;
}
