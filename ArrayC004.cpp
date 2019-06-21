#include <iostream>

using namespace std;

int main(){
	
	int N;
	cin >> N;
	while(N--)
	{
	int x,y;
	cin >> x >> y;
	
	bool map[x][y];
	bool Result[x][y];
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
		{
			cin >> map[i][j];
			Result[i][j]=0;
		}
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			if(map[i][j])
			{
				if(i-1>=0)
					if(map[i-1][j]==0)
						Result[i][j]=1;
				if(i+1<x)
					if(map[i+1][j]==0)
						Result[i][j]=1;
				if(j-1>=0)
					if(map[i][j-1]==0)
						Result[i][j]=1;
				if(j+1<y)
					if(map[i][j+1]==0)
						Result[i][j]=1;
			}
			if(Result[i][j])
			cout << "0 ";
			else
			cout << "_ ";
		}
		cout << endl;		
	}
	if(N!=0)
	cout << endl;
	}	
	
	
	
	return 0;
}
