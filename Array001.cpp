#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
	
	int N;
	bool Table[50][50];
	memset(Table,0,2500);
	bool Pen=0;
	int Way[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int NowWay=0;
	int NowPos[2]={0,0};
	int MaxI=0,MaxJ=0;
	int Go,Goal[2]={NowPos[0],NowPos[1]};
	while(cin >> N)
	{
	
		switch(N)
		{
			case 1:
				Pen=0;
				break;
			case 2:
				Pen=1;
				break;
			case 3:
				NowWay = NowWay >= 3 ? 0 : NowWay+1;
				break;
			case 4:
				NowWay = NowWay <= 0 ? 3 : NowWay-1;
				break;
			case 5:
				char comma;
				cin >> comma >> Go;
				if(Way[NowWay][0])
					Goal[0]=NowPos[0] + Go*Way[NowWay][0];
				if(Way[NowWay][1])
					Goal[1]=NowPos[1] + Go*Way[NowWay][1];	
				if(Pen)
				{
					for(int i=min(Goal[0],NowPos[0]);i<=max(Goal[0],NowPos[0]);i++)
						for(int j=min(Goal[1],NowPos[1]);j<=max(Goal[1],NowPos[1]);j++)
								Table[i][j]=1;		
				if(max(Goal[0],NowPos[0])>MaxI)
				MaxI=Goal[0];
				if(max(Goal[1],NowPos[1])>MaxJ)
				MaxJ=Goal[1];											
				}
				
				NowPos[0]=Goal[0];
				NowPos[1]=Goal[1];
				//printf("NowPosis %d %d\n",NowPos[0],NowPos[1]);
				break;
			case 6:
				for(int i=0;i<=MaxI;i++)
				{
					for(int j=0;j<=MaxJ;j++)
						if(Table[i][j])
						cout << '*';
						else
						cout << ' ';
					cout << endl;
				}
				break;
			case 9:
				N=-1;
				break;					
		}
		if(N==-1)
		break;
		
	}
	
	
	
	return 0;
} 
