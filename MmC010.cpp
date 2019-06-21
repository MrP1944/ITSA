#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double N;
	while(cin >> N)
		cout << fixed << setprecision(1) << N*9/5+32+0.01 << endl;
	return 0;
}
