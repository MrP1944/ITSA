#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	cout << N/86400 << " days" << endl;
	N%=86400;
	cout << N/3600 << " hours" << endl;
	N%=3600;
	cout << N/60 << " minutes" << endl;
	N%=60;
	cout << N << " seconds" << endl;
	return 0;
}
