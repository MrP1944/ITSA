#include <iostream>
using namespace std;

int main(){
	int N;
	while(cin>>N)
	{
		cout << "NT10=" <<N/10 << endl;
		N=N%10;
		cout << "NT5=" << N/5 << endl;
		N=N%5;
		cout << "NT1=" << N << endl;
	}
	return 0;
}
