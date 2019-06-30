#include <cstdio>
//#include <iostream>
#include "407410003_41bb05.h"

using namespace std;

Point half(Point A,Point B)
{
	return {(A.first+B.first)/2,(A.second+B.second)/2};
}

int main(){
	
	FILE *In,*Out;
	In = fopen("input.txt","r");
	Out = fopen("result.txt","w");
	int N;
	fscanf(In,"%d",&N);
	//cin >> N;
	vector<node> Node;
	
	for(int i=0;i<N;i++)
	{
		int No;
		double X,Y;
		fscanf(In,"%d %lf %lf",&No,&X,&Y);
		//cin >> No >> X >> Y; 
		Node.push_back(node(No,X,Y));
		for(int j=i-1;j>=0;j--)
		{
			if(dist(Node[i].getLocation(),Node[j].getLocation()) <= 1.0)
			{
				Node[j].setBneighbor(&Node[i]);
				Node[i].setBneighbor(&Node[j]);
				//cout << "Success Set" << Node[i].getNum() << '&' <<Node[j].getNum() << endl;
				printf("SuccussSet %d & %d\n",Node[i].getNum(),Node[j].getNum());
			}
		}////////check neighbor before planar graph	
	}
	//cout << "Set over\n";
	printf("SETOVER\n");
	for(int i=0;i<N;i++)
	{
		//node Now = Node[i];
		vector<node*> NowBnei;
		NowBnei.clear();
		NowBnei = Node[i].getBneighbor();
		Point NowPos = Node[i].getLocation();
		printf("%d'sNei= ",Node[i].getNum());
		for(int j=0;j<NowBnei.size();j++)
			printf("%d ",NowBnei[j]->getNum());
		printf("\n");
		for(int j=0;j<NowBnei.size();j++)
		{
			Point neiPoint = NowBnei[j]->getLocation();
			bool remove=0;
			Point mid = half(NowPos,neiPoint);
			double radius = dist(NowPos,mid);
			for(int k=0;k<NowBnei.size();k++)
			{
				if(k==j)
					continue;
				if(dist(mid,NowBnei[k]->getLocation()) <= radius)////////cut line if in circle
				{
					remove=1;
					break;
				}
			}
			if(remove==0)
			{
				Node[i].setAneighbor(NowBnei[j]);
				//cout << "Success Set" << Node[i].getNum() << '&' <<NowBnei[j].getNum() << endl;				
				printf("SuccessSet %d & %d\n",Node[i].getNum(),NowBnei[j]->getNum());
			}
		}
	}////////After planar graph.
	int NumOfGoal;
	fscanf(In,"%d",&NumOfGoal);
	//cin >> NumOfGoal;
	while(NumOfGoal--)
	{
		int From,Goal;
		//cin >> From >> Goal;
		fscanf(In,"%d %d",&From,&Goal);
		packet p = packet();
		p = packet(Node[From].getLocation(),Node[Goal].getLocation());
		p.setSource(Node[From].getLocation());
		Node[From].Recive(p);
		
		bool Found=0;
		while(!Found)
		{
			bool Still=0;
			for(int i=0;i<Node.size();i++)
			{
				Found = Node[i].checkQueue();
				if(Found==1)
					printf("Found!!!!\n");
			}
		}
		
	}
	
	return 0;
}



