#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Person{
public:
	void ChangeFirstName(int year,const string& first_name){
		
		FirstNameHistory[year]=first_name;
	}
	
	void ChangeLastName(int year,const string& last_name){
		
		LastNameHistory[year]=last_name;
	}
	
	string GetFullName(int year){
		string info,first_name,last_name;
		for(auto& item:FirstNameHistory)
		{
			if(item.first<=year)
			{
				first_name=item.second;
			}
			else break;
		}
		for(auto& item:LastNameHistory)
		{
			if(item.first<=year)
			{
				last_name=item.second;
			}
			else break;
		}
		if(first_name.empty()&&last_name.empty()){

			info="Incognito";
			return info;
		}
		else if(first_name.empty()){
			info=last_name;
			info+=" with unknown first name";
			return info;
		}
		else if(last_name.empty()){
			info=first_name;
			info+=" with unknown last name";
			return info;
		}
		else{
			info=first_name;
			info+=" ";
			info+=last_name;
			return info;
		}
	}
private:
	map<int,string> FirstNameHistory;
	map<int,string> LastNameHistory;
};

int main(){
	Person person;
	
	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967,"Sergeeva");
	for(int year:{1900,1965,1990}){
		cout<<person.GetFullName(year)<<endl;
	}
	
	person.ChangeFirstName(1970, "Appolinaria");
	for(int year:{1969,1970}){
		cout<<person.GetFullName(year)<<endl;
	}
	
	person.ChangeLastName(1970, "Volkova");
	for(int year:{1969,1970}){
		cout<<person.GetFullName(year)<<endl;
	}
		
	return 0;
}
