﻿#include <iostream>
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
		
	string GetFullNameWithHistory(int year){
		string info,first_name,last_name;
		vector<string> first_history, last_history;
//ОБРАБОТКА ИСТОРИИ ИМЕНИ
		full_history_record(year,first_name,first_history,FirstNameHistory);

		
//ОБРАБОТКА ИСТОРИИ ФАМИЛИИ		
		full_history_record(year,last_name,last_history,LastNameHistory);

		if(first_name.empty()&&last_name.empty()){

			info="Incognito";
			return info;
		}
		else if(first_name.empty()){
			info=last_name;
			history_fill(info, last_history);
			info+=" with unknown first name";
			return info;
		}
		else if(last_name.empty()){
			info=first_name;
			history_fill(info, first_history);
			info+=" with unknown last name";
			return info;
		}
		else{
			info=first_name;
			
			history_fill(info, first_history);
			
			info+=" ";
			
			info+=last_name;
			
			history_fill(info, last_history);
			
			return info;
		}
	}
private:
	map<int,string> FirstNameHistory;
	map<int,string> LastNameHistory;
	
	void full_history_record(const int& year, string& name, vector<string>& history, const map<int,string>& NameHistory){
		int i=0;
		for(auto& item:NameHistory)
		{
			if(item.first<=year)
			{
				name=item.second;
			}
			else 
			{
				break;
			}
			
			if(i==0)
			{
				history.push_back(name);
				i++;
			}
			else if(history[i-1]!=name)
			{
				history.push_back(name);
				i++;
			}
		}
		i--;
		if(i>=0)
		{
		history.erase(history.begin()+i);
		}
		reverse(history.begin(),history.end());
	}
	
	void history_fill(string& info, const vector<string>& history){
		int i=0;
		if(!history.empty())
			{
				info+=" (";
				for(auto& item:history)
				{
					info+=item;
					if(history.size()!=1&&i!=history.size()-1)
					{
						info+=", ";
					}
					i++;
				}
				info+=")";
			}
	}
	
};

int main(){
	
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}
	
	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}
	
	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}
	
	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;
	
	person.ChangeFirstName(1966, "Pauline") ;
	cout << person.GetFullNameWithHistory(1966) << endl;
	
	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}
	
	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}
