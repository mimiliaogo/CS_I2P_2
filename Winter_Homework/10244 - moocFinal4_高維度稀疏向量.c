#include <stdio.h>
int vector[1000];
int dim[1000];
int main()
{
    char ch;
    int num, tmp_vec, tmp_dim;
    int i = 0;
    int ans = 0;
    while (1) {

        scanf("%d", &dim[i]);
        ch = getchar();//eat :
        scanf("%d", &vector[i]);
        ch = getchar();//eat space
        i++;
        if (ch=='\n') break;
    }
    num = i;

    while (1) {
        scanf("%d", &tmp_dim);
        ch = getchar();//eat :
        scanf("%d", &tmp_vec);
        for (i=0; i<num; i++) {
            if ((tmp_dim)==dim[i]) {
                ans += vector[i]*tmp_vec;
            }
        }
        ch = getchar();//eat space
        if (ch=='\n') break;
    }
    printf("%d\n", ans);
}
