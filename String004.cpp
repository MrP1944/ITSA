#include <iostream>
using namespace std;

int main(){
	
	string InPut;
	
	while(getline(cin,InPut))
	{
		
		string Result="";
		bool Found=0;
		for(int i=0;i<InPut.length();i++)
		{
			for(int j=InPut.length()-1;j>=0;j--)
			{
				Found=1;
				string Tmp="";
				for(int a=i,b=j;a<=j && b>=i;a++,b--)	
				{
					if(InPut[a]==InPut[b])
					Tmp+=InPut[a];
					else
					{
						Tmp="";
						Found=0;
						break;
					}
				}
				if(Found && Tmp.length() > Result.length())
				Result = Tmp;
			}	
		}
		if(Result.length()>1)
		cout << Result << endl;
		else 
		cout << "There's no palindrome in this string!"<<endl; 	
	}
		
	return 0;
}
