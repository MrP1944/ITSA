#include <iostream>
using namespace std;

int main(){
	int a,b;
	while(cin >> a >> b)
		cout << (a+b)*(max(a,b)-min(a,b)+1)/2 << endl;
	return 0;
}
