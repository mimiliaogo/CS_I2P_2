#include <iostream>
using namespace std;
int num[105];
int swapnum=0;
void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void insertion(int n)
{
    int i;
    if (n==1) return;
    insertion(n-1);
    for (i=n-1;num[i]<num[i-1]&&i>0; i--) {
        swapnum++;
//        cout<<n-1<<i<<endl;
//        cout<<num[n-1]<<num[i]<<endl;
        swap(num[i-1], num[i]);
    }

}
int main()
{
    int T, N;
    int ans=0;
    cin>>T;
    while (T>0) {
        T--;
        cin>>N;
        for (int i=0; i<N; i++) {
            cin>>num[i];
        }
        insertion(N);
        for (int i=0; i<N; i++) {
            num[i] = 0;
        }
    }
    cout<<swapnum<<endl;
}


