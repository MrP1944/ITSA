#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	double T,B,H;
	while(cin >> T >> B >> H)
		cout << fixed  <<  setprecision(1) << "Trapezoid area:" << (T+B)*H/2 << endl;

	return 0;
}
