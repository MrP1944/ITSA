#include <iostream>

using namespace std;

int main(){
	
	string InPut;
	int ASCII[127]={0};
	getline(cin,InPut);
	
	for(int i=0;i<InPut.length();i++)
		ASCII[(int)InPut[i]]++;
	for(int i=126;i>=0;i--)
		if(ASCII[i])
		cout << i << " " << ASCII[i] << endl;

	return 0;
}
