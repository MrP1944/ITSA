#include <iostream>
using namespace std;

int main(){
	int Year;
	while(cin >> Year)
		if(Year % 400 == 0 || (Year % 4 == 0 && Year % 100 !=0))
			cout << "Bissextile Year" << endl;
		else
			cout << "Common Year" << endl;
	return 0;
}
