#include <cstdio>
//#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
using namespace std;

typedef pair<double,double> Point;

double Inner(Point A, Point B)
{
	return (A.first*B.first)+(A.second*B.second);
}
double dist(Point A)
{
	return sqrt((A.first*A.first)+(A.second*A.second));
}
double dist(Point A,Point B)
{
	double X = max(A.first,B.first)-min(A.first,B.first);
	double Y = max(A.second,B.second)-min(A.second,B.second);
	
	return sqrt((X*X)+(Y*Y));
}

class packet
{
	
	public:
		packet();
		packet(Point Start,Point End);
		void coutPath()
		{
			for(int i=0;i<Path.size();i++)
			{
				printf("%d ",Path[i]);				
			}
			printf("\n");
		}
		void pushPath(int ID)
		{
			Path.push_back(ID);
		}
		Point GetnHop()
		{
			return nextHop;			
		}
		void updateHop(Point next);
		Point getPrev()
		{
			return prev;
		}
		Point getlHop()
		{
			return lastHop;
		}
		Point getVec()
		{
			Point Zero={0,0};
			if(lastHop == Zero)
				return {goal.first-prev.first,goal.second-prev.second};
			else
				return {nextHop.first-lastHop.first,nextHop.second-lastHop.second};
		} 
		Point getGoal()
		{
			return goal;
		}
		vector<int> getPath()
		{
			return Path;
		}
		Point getSource()
		{
			return source;
		}
		void setSource(Point Start)
		{
			source = Start;
		}
		Point getIntersect()
		{
			return Inter;
		}
		void setIntersect(double x, double y)
		{
			Inter = {x, y};
		}
	private:
		vector<int> Path;
		Point prev;
		Point source;
		Point goal;
		Point lastHop;
		Point nextHop;
		Point Inter;
		
		
};

packet::packet()
{
	Path.clear();
	prev={0,0};
	source={0,0};
	goal={0,0};
	lastHop={0,0};
	nextHop={0,0};
	Inter={0,0}; 
}

packet::packet(Point Start, Point End)
{
	nextHop=Start;
	goal=End;
	Inter=Start;
}

void packet::updateHop(Point next)
{
	lastHop = nextHop;
	nextHop = next;
	printf("Now lastHop={%lf,%lf} nextHop={%lf,%lf}\n",lastHop.first,lastHop.second,nextHop.first,nextHop.second);
}

class node
{
	
	public:
		void initpacket();
		node(int Num, double X, double Y);
		int getNum()
		{
			return No;
		}
		void setBneighbor(node* nei)
		{
			Beforeneighbor.push_back(nei);
		}
		void setAneighbor(node* nei)
		{
			Afterneighbor.push_back(nei);
		}
		vector<node*> getBneighbor()
		{
			return Beforeneighbor;
		}
		node* getNextHop(packet p);
		
		bool checkQueue();
		void send(packet Mail);
		void Recive(packet Mail);
		Point getLocation()
		{
			return Location;
		}
		
	private:
		int No;
		Point Location;
		vector<node*> Beforeneighbor;
		vector<node*> Afterneighbor;
		queue<packet> packetQ;
		int isAbove(Point inter, Point dest, node *next)	//If next is above inter-dest
		{
			double m = (inter.second - (dest.second)) / (inter.first - (dest.first));
			double val = next -> Location.second - dest.second - m * (next -> Location.first - dest.first);

			//if(fabs(val) < PREC) return false;

			if(fabs(val) < 0.0000001)
				return 0;
			else if(val > 0) 
				return 1;
			else if(val < 0)
				return -1;
		}

		bool isCrossed(Point inter, Point dest, node *next)	//If Next is Crossing inter-dest
		{
			double m = (inter.second - (dest.second)) / (inter.first - (dest.first));////////BlueLine's m;
			double tVal = Location.second - dest.second - m * (Location.first - dest.first);//////////inter to Point
			double val = next -> Location.second - dest.second - m * (next -> Location.first - dest.first);////////Destion to next point

		
			double cx, cy;
			cx = (Location.first + next -> Location.first) / 2;
			cy = (Location.second + next -> Location.second) / 2;

			if((val * tVal < 0 || fabs(tVal) < 0.0000001))
				return true;
			else
				return false;
		}

		double ang(Point pos, node *target, Point dest)//////count angel
		{
			double x1 = pos.first;
			double y1 = pos.second;

			Point a = {dest.first - x1, dest.second - y1};
			Point b = {target->Location.first - x1, target -> Location.second - y1};
			
			return acos(Inner(a,b) / (dist(a) * dist(b)));
		}

		Point intersect(packet p, node *n1, node *n2)
		{
			Point p00 = p.getSource();
			Point p01 = p.getGoal();

			Point p10 = n1->getLocation();
			Point p11 = n2->getLocation();

			double m1 = (p00.second - p01.second) / (p00.first - p01.first);
			double m2 = (p10.second - p11.second) / (p10.first - p11.first);
	
			double a1 = m1;
			double b1 = -1.0;
			double c1 = p00.second - m1 * p00.first;

			double a2 = m2;
			double b2 = -1.0;
			double c2 = p10.second - m2 * p10.first;

			double xf = (c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1);
			double yf = (a1 * c2 - a2 * c1) / (a2 * b1 - a1 * b2);

			return {xf, yf};
		}////////intersecpoint! 

		bool zero(double d1, double d2)
		{
			return fabs(d1 - d2) < 0.000000000001;
		}
		
};

void node::initpacket()
{
	if(!packetQ.empty())
	packetQ.pop();
}

node::node(int Num, double X, double Y)
{
	No = Num;
	Location.first=X;
	Location.second=Y;
	Beforeneighbor.clear();
	Afterneighbor.clear();
}

node* node::getNextHop(packet p) //Route
{
	node *Temp, *Target;
	double MinWeight = 1008610086;
	double weight;
	double angle;
	Point inter = p.getIntersect();
	Point prev = p.getPrev();
	int above;

	for(int i=0;i<Afterneighbor.size();i++)
	{
		node *n = Afterneighbor[i];
		printf("NowCheck%d\n",n->getNum());
		angle = ang(getLocation(), n, prev);
		above = isAbove(prev, getLocation(), n);

		if(above > 0)
			weight = angle - 4;
		else if(above < 0)
			weight = 4 - angle;
		else if(zero(prev.first, n -> Location.first) && zero(prev.second, n -> Location.second))
			weight = 20;
		else
			weight = 0;

		if(Location.first < prev.first)
			weight *= -1.0;
		if(zero(prev.first, n->Location.first) && zero(prev.second, n->Location.second))
			weight = 20;
		if(zero(Location.first, p.getSource().first) && zero(Location.second, p.getSource().second) && zero(n -> Location.first, p.getGoal().first) && zero(n -> Location.second, p.getGoal().second))
			weight = -20;

		if(weight <= MinWeight)
		{
			MinWeight = weight;
			Temp = n;
		}
		printf("Weight=%lf\n",weight);
	}
		Target = Temp;

	inter = intersect(p, this, Temp);
	bool Crossed = isCrossed(p.getSource(), p.getGoal(), Temp);
	if (Crossed && ((inter.first - p.getSource().first) * (inter.first - p.getGoal().first) < 0 || (inter.second - p.getSource().second) * (inter.second - p.getGoal().second) <= 0))
	{
		//Update inter
		inter = intersect(p, this, Temp);

		if(dist(inter, p.getGoal()) < dist(p.getIntersect(), p.getGoal()))
		{
			p.setIntersect(inter.first, inter.second);
			Point tempIn = p.getIntersect();
			//Re-calculate Next Hop

			MinWeight = 1008610086;
			for(int i=0;i<Afterneighbor.size();i++)
			{
				node *n = Afterneighbor[i];
				
				
				angle = ang(inter, n, p.getGoal());
				above = isAbove(inter, p.getGoal(), n);

				if(above > 0)
					weight = angle - 4;
				else if(above < 0)
					weight = 4 - angle;
				else if(zero(prev.first, n->Location.first) && zero(prev.second, n->Location.second))
					weight = 20;
				else
					weight = -5;

				if(inter.first < p.getGoal().first) weight *= -1.0;
				if(weight <= MinWeight)
				{
					MinWeight = weight;
					Temp = n;
				}
				
			}
				
		}
	}

	Target = Temp;
	return Target;
	//nHop = Target -> id;
	
}

bool node::checkQueue()
{
	if(!packetQ.empty())
	{
		packet Now = packetQ.front();
		packetQ.pop();
		printf("Location{%lf,%lf}\n",Location.first,Location.second);
		if(Now.getGoal() == Location)
		{
			Now.pushPath(getNum());
			Now.coutPath();
			return true;
		}
		if(Now.GetnHop() == Location)
		{
			printf("Matched!\n");
			node *Next = getNextHop(Now);
			Now.updateHop(Next->Location);
			printf("NextIs %d\n",Next->getNum());
			Now.pushPath(getNum());
			////Will Send all of its neighbor;
			send(Now);
			return false;
		}
	}else
		return false;
}

void node::Recive(packet Mail)
{
	packetQ.push(Mail);
	printf("%dRecivedPacket,NowSize=%d\n",getNum(),packetQ.size());
}

void node::send(packet Mail)
{
	for(int i=0;i<Afterneighbor.size();i++)
	{
		node *n = Afterneighbor[i];
		if(Mail.getlHop()!= n -> getLocation())
		{
			printf("Sended to %d\n",n->getNum());
			n->Recive(Mail);
		}
	}
	printf("OverSend\n");
	
}


