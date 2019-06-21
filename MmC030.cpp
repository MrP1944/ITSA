#include <iostream>
using namespace std;

int main(){
	int N;
	while(cin >> N)
	{
		bool Prime=1;
		for(int i=2;i<N;i++)
			if(N % i == 0)
			{
				Prime=0;
				break;
			}
		if(Prime)
		cout << "YES";
		else
		cout << "NO";
		cout << endl;		
	}

			
	return 0;
}
