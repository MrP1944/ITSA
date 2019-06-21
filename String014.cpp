#include <iostream>

using namespace std;

int main(){

	int N;
	
	cin >> N;
	
	string Result="",InPut;

	while(N--)
	{
		cin >> InPut;
		if(Result=="")
		Result = InPut;
		else
		{
			int InPos=0;
			for(int i=Result.length()-1,j=0;i>=0 && j<InPut.length();i--,j++)
			{
				bool Equal=1;
				for(int a=i,b=0;a<Result.length() && b<=j;a++,b++)
				{
				//	cout << a << "&" << b << endl;
				//	cout << "Compare " << Result[a] << " && " << InPut[b] << endl;
					if(Result[a]!=InPut[b])
					{
						Equal=0;
						break;
					}
				}
				if(Equal)
				{
					InPos=j+1;//cout << "Equal!! " << InPos << endl;
				}
			}
			for(int j=InPos;j<InPut.length();j++)
			Result+=InPut[j];
		}
	//	cout << Result << endl;
	}
	cout << Result << endl;
	return 0;

}
