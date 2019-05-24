#include <iostream>
#include "10996_include.h"
using namespace std;
int main(){
	int numofpeople;

	while(cin>>numofpeople){
		Josephus Jose(numofpeople);
		int survival = Jose.kill();
		cout<<survival<<endl;
    }
}
