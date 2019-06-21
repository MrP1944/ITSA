#include <iostream>
using namespace std;

int main(){
	int ST[2],ET[2];
	cin >> ST[0] >> ST[1];
	cin >> ET[0] >> ET[1];
	ST[1] += ST[0]*60;
	ET[1] += ET[0]*60;
	int Money=0,Time=ET[1]-ST[1];
	
	Time = Time/30 * 30;
	while(Time/30)
	{
		if(Time <= 120)
			Money+=30;
		else if(Time > 120 && Time <= 240)
			Money+=40;
		else
			Money+=60;		
		Time-=30;
	}

	cout << Money << endl;
	return 0;
}
