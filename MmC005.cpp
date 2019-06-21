#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double N;
	while(cin>>N)
		cout << fixed << setprecision(1) << (N*N+0.01) << endl;
	
	
	return 0;
}
