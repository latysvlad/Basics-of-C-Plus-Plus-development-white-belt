#include <iostream>
#include <string> 
#include <map> 
 
 
using namespace std; 
 
void change_capital(map<string, string>& catalog){
		////(3)СМЕНА СТОЛИЦЫ 
	 string country, new_capital; 
	 cin >> country >> new_capital;
	
	 if(catalog.count(country)==0) 
	 {
		  catalog[country]=new_capital; 
		  cout<<"Introduce new country "<<country<<" with capital "<<new_capital<<endl; 
	 } 
	 else if(catalog[country]==new_capital) 
	 {
		  cout<<"Country "<<country<<" hasn't changed its capital"<<endl; 
	 } 
	 else 
	 { 
		  cout<<"Country "<<country<<" has changed its capital from "<<catalog[country]<<" to "<<new_capital<<endl; 
		  catalog[country]=new_capital; 
	 }
} 

void rename(map<string, string>& catalog){
	////(4)ПЕРЕИМЕНОВАНИЕ СТОЛИЦЫ 
	string old_country_name, new_country_name;
	cin >> old_country_name >> new_country_name; 

	if(catalog.count(old_country_name)==0||catalog.count(new_country_name)!=0||old_country_name==new_country_name)
	{
		cout<<"Incorret rename, skip"<<endl;
	}
	else
	{
		cout<<"Country "<<old_country_name<<" with capital "<<catalog[old_country_name]<<" has been renamed to "<<new_country_name<<endl;
		catalog[new_country_name]=catalog[old_country_name];
		catalog.erase(old_country_name);
	}
}

void about(map<string, string>& catalog){
	////(5)ИНФО ПО СТРАНЕ
	string country;
	cin>>country;
	
	if(catalog.count(country)==0)
	{
		cout<<"Country "<<country<<" doesn't exist"<<endl;
	}
	else
	{
		cout<<"Country "<<country<<" has capital "<<catalog[country]<<endl;
	}
}

void dump(map<string, string>& catalog){
	////(6)ВЫВОД СПРАВОЧНИКА
	if(catalog.size()==0)
	{
		cout<<"There are no countries in the world"<<endl;
	}
	else
	{
		for(auto item:catalog)
		{
			cout<<item.first<<'/'<<item.second<<' ';
		}
	}
	cout<<endl;
}

int main() { 
	 map<string, string> catalog; 
	 string command; 
	 int q; 
		
	 cin >> q; ////(1)ВВОД ЧИСЛА КОМАНД 
	 cout << "введите команды change_capital, rename, about или dump" << endl; 
		
	 for(int i=0;i<q;i++) 
	 { 
		  cin >> command; ////(2)ВВОД КОМАНДЫ 
		  if(command=="change_capital"){ 
			   change_capital(catalog); 
		  } 
		  else if(command=="rename"){ 
			   rename(catalog); 
		  } 
		  else if(command=="about"){ 
			   about(catalog); 
		  } 
		  else if(command=="dump"){ 
			   dump(catalog); 
		  } 
		  else 
		  { 
			   cout << "введите команду из предложенного списка" << endl; 
		  } 
	 } 
	 return 0; 
}
