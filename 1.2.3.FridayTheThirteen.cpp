/*
ID: rvpande1
TASK: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

#define ll long long

using namespace std;

bool isLeap(int year){
	if(year%100==0 && year%400!=0){
		return false;
	}else if(year%4!=0){
		return false;
	}
	return true;
}

int main() {
	ofstream fout ("friday.out");
    ifstream fin ("friday.in");
	int d[7];
	for(int i=0;i<7;i++){
		d[i]=0;
	}
	int n,lday=5;
	fin>>n;
	for(int i=0;i<n;i++){
		for(int j=1;j<=12;j++){
			int day;
			if(j==1 || j==2 || j==4 || j==6 || j==8 || j==9 || j==11){
				day=(lday+(31%7))%7;
				day=(day==0)?7:day;
			}
			else if(j==5 || j==7 || j==10 || j==12){
				day=(lday+(30%7))%7;
				day=(day==0)?7:day;
			}
			else if(j==3 && isLeap(1900+i)){
				day=(lday+(29%7))%7;
				day=(day==0)?7:day;
			}
			else if(j==3 && !isLeap(1900+i)){
				day=(lday+(28%7))%7;
				day=(day==0)?7:day;
			}
			d[day-1]++;
			lday=day;
		}
	}
	for(int i=0;i<7;i++){
		if(i<6)
		fout<<d[i]<<" ";
		else
		fout<<d[i]<<endl;
	}
	return 0;
}


