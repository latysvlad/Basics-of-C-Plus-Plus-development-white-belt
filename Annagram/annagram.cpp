#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool BuildCharCounters(const string& word1,const string& word2)
{
	map<char,int> counters1,counters2;
	for(const char& sym : word1){
	++counters1[sym];
	}
	for(const char& sym : word2){
	++counters2[sym];
	}
	if(counters1==counters2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(){
	int n;
	cin >> n;
	vector<vector<string>> words(n);
	string word1,word2;
	
	for(int i=0;i<n;i++)
	{
		cin >> word1;
		cin >> word2;
		words[i].push_back(word1);
		words[i].push_back(word2);
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		word1=words[i][0];
		word2=words[i][1];
		if(BuildCharCounters(word1,word2))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
/*	for(int i=0;i<n;i++){
		for(auto lol:words[i])
		{
			cout<<lol<<' ';
		}
		cout<<endl;
	}
	*/
	return 0;
}
