#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	string InPut;
	
	while(cin >> InPut)
	{
		int Result=0;
		
		for(int i=0;i<InPut.length();i++)
		{
			Result+=(int)(InPut[i]-'A'+1)*pow(26,(InPut.length()-i-1));
		}
		cout << Result << endl;
		
	}
	return 0;
}
