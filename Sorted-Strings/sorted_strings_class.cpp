#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings{
public:
	void AddString(const string& s){
		DefaultStrings.push_back(s);
	}
	vector<string> GetSortedStrings(){
		sort(begin(DefaultStrings),end(DefaultStrings));
		return DefaultStrings;
	}
private:
	vector<string> DefaultStrings;
};

void PrintSortedStrings(SortedStrings& strings){
	for(const string& s:strings.GetSortedStrings()){
		cout<<s<<' ';
	}
	cout<<endl;
}
	
int main(){
	SortedStrings strings;
	strings.AddString("firtst");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);
		
	strings.AddString("second");
	PrintSortedStrings(strings);
		
	return 0;
}
		
