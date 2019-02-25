/*
�ӦZ�i��m����

1.�Ӧ�L��m

2.�צV�L��m

3.���Ѿl�ӦZ



�����i��m����

1.�Ӧ�L��m

2.�צV�L�ӦZ (�i�H������)

3.���Ѿl����



�P�_�ĤG������k��

�Y��m�ӦZ�A�h�ӱצV�Ȭ�-1

�Y��m�����A�h�C��@�ӱצV+1



�Y�צV�� = 0 �A�i���N��m




�Y�צV�� > 0 �A�u�i�񫰳�

�Y�צV�� < 0 (-1) �A���i��m



��m�e�]�w��ȤαצV��

���X��^�_�쪬



�_

����+1



posSlope  �C�W�[�@�C�A��ƭn-1

=> �� + �C = �w��



negSlope �C�W�[�@�C�A��ƭn+1

=> ��� - �C�� = �w��   (���i���X�ӬO�t���A�G�[M+N�Ӻ����䥿��)

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
