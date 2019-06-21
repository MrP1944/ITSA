#include <iostream>
using namespace std;

int main(){
	int N;
	while(cin >> N)
		if(N>=3 && N<=5)
			cout <<"Spring"<<endl;
		else if(N>=6 && N<=8)
			cout <<"Summer"<<endl;
		else if(N>=9 && N<=11)
			cout <<"Autumn"<<endl;
		else
			cout <<"Winter"<<endl;
	return 0;
}
