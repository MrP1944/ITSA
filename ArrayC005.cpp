#include <iostream>

using namespace std;

int main(){
	
	int N;
	cin >> N;
	int Car[25]={0};
	while(N--)
	{
		int a,b;
		cin >> a >> b;
		for(int i=a;i<b;i++)
		{
			Car[i]++;
			if(Car[i] > Car[0])
			Car[0] = Car[i];
		}
		
	}
	cout << Car[0] << endl;
	
	
	
	return 0;
}
