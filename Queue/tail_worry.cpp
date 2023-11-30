#include <iostream>
#include <vector>
#include <string>

using namespace std;

void come(vector<int>& tail){
	int k;
	cin >> k;
	tail.resize(tail.size()+k,0);

	for(auto sus:tail)
	{
		cout << sus << ' ';
	}
	cout << endl;
}

void worry(vector<int>& tail){
	int i;
	cin >> i;
	tail[i]=1;

	for(auto sus:tail)
	{
		cout << sus << ' ';
	}
	cout << endl;
}

void quiet(vector<int>& tail){
	int i;
	cin >> i;
	tail[i]=0;

	for(auto sus:tail)
	{
		cout << sus << ' ';
	}
	cout << endl;
}

void worry_count(vector<int>& tail){
	int sum=0;
	for(auto s:tail)
	{
	sum+=s;
	}
	cout << sum;
	cout << endl;
	for(auto sus:tail)
	{
		cout << sus << ' ';
	}
	cout << endl;
}

int main() {
	vector<int> tail;
	string command;
	int q;
	cin >> q;
	cout << "введите команды worry, come, quiet или worry_count" << endl;
	for(int i=0;i<q;i++)
	{
		cin >> command;
		if(command=="come"){
			come(tail);
		}
		else if(command=="worry"){
			worry(tail);
		}
		else if(command=="quiet"){
			quiet(tail);
		}
		else if(command=="worry_count"){
			worry_count(tail);
		}
		else
		{
			cout << "введите команду из предложенного списка" << endl;
		}
	}
	return 0;
}
