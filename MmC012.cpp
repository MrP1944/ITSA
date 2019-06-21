#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int N;
	while(cin >> N)
	{
		N*=1000;
		if(N % 238==0)
		cout << N / 238 << endl;
		else
		cout << N/238+1 << endl;
	}
	return 0;
}

