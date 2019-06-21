#include <iostream>

using namespace std;

int main(){
	
	int Num[6];
	
	for(int i=0;i<6;i++)
	cin >> Num[i];
	
	for(int j=5;j>=0;j--)
	{
		cout << Num[j];
		if(j!=0)
		cout << " ";
	}
	cout << endl;
	return 0;
}
