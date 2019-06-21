#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int N;
	while(cin >> N)
	{
		for(int i=1;i<=N;i++)
			if(N%i==0)
				if(i!=N)
				cout << i << " ";
				else
				cout << i;
		cout << endl;
	}
	return 0;
}
