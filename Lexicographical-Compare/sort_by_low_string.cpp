#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool comp(string a,string b){
	vector<int> a_s,b_s;
	
	for(int i=0;i<a.size();i++)
	{
		a_s.push_back(tolower(a[i]));
	}
	
	for(int i=0;i<b.size();i++)
	{
		b_s.push_back(tolower(b[i]));
	}
//	return 1;
	return a_s<b_s;
}
int main(){
	int n;
	cin>>n;
	vector<string> a(n);
	for(auto& item:a)
	{
		cin>>item;
	}
	
	sort(begin(a),end(a),comp);
	
	for(const auto& item:a)
	{
		cout<<item<<' ';
	}
	cout<<endl;
	
	return 0;
}
