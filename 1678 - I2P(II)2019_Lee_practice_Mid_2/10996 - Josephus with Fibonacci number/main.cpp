#include <iostream>
#include "function.h"
using namespace std;
int main(){
	int numofpeople;

	while(cin>>numofpeople){
		Josephus Jose(numofpeople);
		int survival = Jose.kill();
		cout<<survival<<endl;
    }
}
