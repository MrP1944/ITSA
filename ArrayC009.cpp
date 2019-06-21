#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	string InPut;
	int MaxA[10]={0},MinA[10]={0};
	int N=0;
	cin >> InPut;
	for(int i=0;i<InPut.length();i++)
	{
		if(InPut[i]>= '0' && InPut[i]<= '9')
		{
			MaxA[(int)(InPut[i]-'0')]++;
			MinA[(int)(InPut[i]-'0')]++;	
			N++;		
		}
	}
	int max=0,min=0,Ten=pow(10,N-1);
	while(N--)
	{
		for(int i=9;i>=0;i--)
			if(MaxA[i])
			{
				max+=i*Ten;
				MaxA[i]--;
				break;
			}
			
		for(int i=0;i<10;i++)
		{
			if(i==0 && min==0)
			continue;
			if(MinA[i])
			{
				min+=i*Ten;
				MinA[i]--;
				break;
			}		
		}
		Ten/=10;			
	}
	cout << max-min << endl;
	
	return 0;
}
