#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

void add(map<string,set<string>>& synonyms){
	string word1, word2;
	cin>>word1>>word2;
	synonyms[word1].insert(word2);
	synonyms[word2].insert(word1);
}

void count(map<string,set<string>>& synonyms){
	string word;
	cin>>word;
	if(synonyms.count(word)>0)
	{
		cout<<synonyms[word].size()<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
}

void check(map<string,set<string>>& synonyms){
	string word1, word2;
	cin>>word1>>word2;
	if(synonyms.count(word1)!=0&&synonyms.count(word2)!=0)
	{
		if(synonyms[word1].count(word2)!=0||synonyms[word2].count(word1)!=0)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	else
	{
		cout<<"No"<<endl;
	}
}

int main(){
	int q;
	string command;
	map<string,set<string>> synonyms;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>command;
		if(command=="add"){
			add(synonyms);
		}
		else if(command=="count"){
			count(synonyms);
		}
		else if(command=="check"){
			check(synonyms);
		}
		else
		{
			cout<<"Неверная команда"<<endl;
		}
	}
	return 0;
}
