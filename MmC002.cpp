#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	double B,H;
	while(cin >> B >> H)
		cout << fixed << setprecision(1) << B*H/2 << endl;
		
	return 0;
}
