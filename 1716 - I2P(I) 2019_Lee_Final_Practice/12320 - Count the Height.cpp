#include <iostream>
using namespace std;
int arr[1000][5];
int countHeight(int, int);
int main()
{
    int N, root;
    while (1) {
        cin>>N;
        if (N==0) break;
        for (int i=0; i<N; i++) {
            cin>>arr[i][0]>>arr[i][1];
            arr[i][2] = 0;
        }
        cin>>root;
        cout<<countHeight(N, root)<<'\n';
    }
}
int countHeight(int N, int root)
{
    int max=0;
    int h;
    bool isfind=false;
    for (int i=0; i<N; i++) {
        for (int j=0; j<2; j++) {
            if (arr[i][j]==root&&arr[i][2]==0) {
                isfind = true;
                arr[i][2] = 1;
                if (j==0) h = countHeight(N, arr[i][1]);
                else h = countHeight(N, arr[i][0]);
                if (h>max) max = h;
            }

        }
    }
    if (!isfind) return 0;
    else return max+1;
}
