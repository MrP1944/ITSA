#include <iostream>

using namespace std;

int main(){
	
	string InPut;
	while(getline(cin,InPut))
	{
		int Num[100]={0};
		int Pos=0;
		int TenTimes=1;
		for(int i=InPut.length()-1;i>=0;i--)
		{
			if(InPut[i] >= '0' && InPut[i] <= '9')
			{
				Num[Pos] = Num[Pos] + (int)(InPut[i]-'0')*TenTimes;
				TenTimes*=10;
			}else
			{
				Pos++;TenTimes=1;
			}
		}
		for(int j=0;j<=Pos;j++)
		{
			cout << Num[j];
			if(j!=Pos)
			cout << " ";			
		}

		cout << endl;
	}
	
	
	return 0;
}
