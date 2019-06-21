#include <iostream>

using namespace std;

int main(){
	
	long long int Num;
	long long int Result=0;
	for(int i=0;i<6;i++)
	{
		cin >> Num;
		Result+=Num*Num*Num;
	}
	cout << Result << endl;
	
	
	return 0;
}
