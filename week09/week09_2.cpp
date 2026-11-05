// week09_2.cpp SOIT106 ADVANCE 009
#include <iostream>
using namespace std;
void f(int N){
	if(N==0) return;
	cout << N%10;
	f(N/10);
}
int main()
{
	int N;
	cin >> N;
	f(N);
	cout <<"\n";
}
