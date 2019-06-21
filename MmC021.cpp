#include <iostream>
#include <string.h>
using namespace std;
long long int Table[20];
long long int count(int N)
{
	if(Table[N])
		return Table[N];
	else
	{
		Table[N] = N * count(N-1);
		return Table[N];
	}
}

int main(){
	int N;
	memset(Table,0,20);
	Table[1]=1;Table[2]=2;
	while(cin >> N)
		cout << count(N) << endl;
	return 0;
}
