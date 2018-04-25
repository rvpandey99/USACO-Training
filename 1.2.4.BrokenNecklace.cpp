/*
ID: rvpande1
TASK: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ofstream fout ("beads.out");
    ifstream fin ("beads.in");
	int n;
	fin >> n;
	string s;
	fin >> s;
	vector<char> v;
	vector<int> c;
	char first='b';
	for(int i=0;i<n;i++){
		v.push_back(s[i]);
	}
	for(int i=0;i<n;i++){
		v.push_back(s[i]);
	}
//	for(int i=0;i<2*n;i++){
//		cout<<v[i];
//	}
//	cout<<endl;
	for(int i=0;i<2*n;i++){
		if(v[i]!='w'){
			first=v[i];
		}
		if(v[i]=='w'){
			v[i]=first;
		}
	}
//	for(int i=0;i<2*n;i++){
//		cout<<v[i];
//	}
	int count=0,flag=0,l=-1,beads=0;
	char last=v[0];
	for(int i=0;i<2*n;i++){
		//cout<<v[i];
		if(v[i]==last && i-l==1){
			last=v[i];
			l=i;
			count++;
		}else{
			c.push_back(count);
			count=1;
			last=v[i];
			l=i;
		}
	}
//	cout<<endl;
//	for(int i=0;i<c.size();i++){
//		cout<<c[i];
//	}
	int max=0;
	for(int i=0;i<c.size()-1;i++){
		int x=c[i]+c[i+1];
		if(x>max){
			max=x;
		}
	}
	fout<<max+1<<endl;
	//system("pause");
	return 0;
}


