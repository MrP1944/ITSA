#include <iostream>
#include <math.h>
using namespace std;

int main(){
	long long int N;
	while(cin >> N)
		if(N < 31)
		cout << (int)pow(2,N) << endl;
		else
		cout << "Value of more than 31" << endl;
	return 0;
}
