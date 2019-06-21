#include <iostream>
using namespace std;

int main(){
	long long int N;
	cin >> N;
	for(long long int i=1;i<=N;i++)
		cout << i << "*" << i << "=" << i*i << endl;
	return 0;
}
