#include <stdio.h>
int main()
{
    int map[15][15];
    int i, j;
    int t, k;
    int N;
    int max = -1000000;
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (i=0; i<N-2; i++) {
        for (j=0; j<N-2; j++) {
            for (t=0; t<3; t++) {
                for (k=0; k<3; k++) {
                    if (map[i+t][j+k]>max) max = map[i+t][j+k];
                }
            }
            if (j==N-3)  printf("%d\n", max);
            else printf("%d ", max);
            max = -1000000;
        }
    }
}
