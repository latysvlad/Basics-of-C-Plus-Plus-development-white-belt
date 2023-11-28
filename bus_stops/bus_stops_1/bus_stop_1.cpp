#include <iostream>
#include <string> 
#include <vector> 
#include <map> 
 
 
using namespace std; 
 
void new_bus(map<int, vector<string>>& bus, map<string, vector<int>>& stop){
	////(3)НОВЫЙ АВТОБУС
 int bus_num, stop_count;
// string stop_name
 cin>>bus_num>>stop_count;
 bus[bus_num].resize(stop_count);
 for(auto& stop_name:bus[bus_num])
 {
 	cin>>stop_name;
 	stop[stop_name].push_back(bus_num);
 }
} 

void buses_for_stop(map<string, vector<int>>& stop){
	////(4)СПИСОК МАРШРУТОВ ОСТАНОВКИ 
	string stop_name;
	cin >> stop_name; 
	if(stop.count(stop_name)==0)
	{
		cout<<"No stop"<<endl;
	}
	else
	{
//		cout<<"Bus "<<stop_name<<": ";
		for(const auto& ses:stop[stop_name])
		{
 			cout<<ses<<' ';
 		}
 		cout<<endl;
	}
}

void stops_for_bus(map<int, vector<string>>& bus, map<string, vector<int>>& stop){
	////(5)ПЕРЕСАДКИ С АВТОБУСА
	int bus_num;
	cin>>bus_num;
	if(bus.count(bus_num)==0)
	{
		cout<<"No bus"<<endl;
		
	}
	else
	{
		for(const auto& ses:bus[bus_num])
		{
 			cout<<"Stop "<<ses<<": ";
 			if(stop[ses].size()>1)
 			{
 				for(const auto& sees:stop[ses])
 				{
 					if(sees!=bus_num)
 					{
 						cout<<sees<<' ';
 					}
 				}
 				cout<<endl;
 			}
 			else
 			{
 				cout<<"no interchange"<<endl;
 			}
 		}
	}
}

void all_buses(map<int, vector<string>>& bus){
	////(6)ВЫВОД ВСЕХ МАРШРУТОВ
	if(bus.size()==0)
	{
		cout<<"No buses"<<endl;
	}
	else
	{
		for(const auto& ses:bus)
		{
			cout<<ses.first<<": ";
			for(const auto& sees:ses.second)
			{
				cout<<sees<<' ';
			}
			cout<<endl;
		}
	}
}

int main() { 
 map<int, vector<string>> bus; 
 map<string, vector<int>> stop;
 string command; 
 int q; 
 cin >> q; ////(1)ВВОД ЧИСЛА КОМАНД 
 cout << "введите команды new_bus, buses_for_stop, stops_for_bus или all_buses" << endl; 
 for(int i=0;i<q;i++) 
 { 
  cin >> command; ////(2)ВВОД КОМАНДЫ 
  if(command=="new_bus"){ 
   new_bus(bus,stop); 
  } 
  else if(command=="buses_for_stop"){ 
   buses_for_stop(stop); 
  } 
  else if(command=="stops_for_bus"){ 
   stops_for_bus(bus,stop); 
  } 
  else if(command=="all_buses"){ 
   all_buses(bus); 
  }
  else 
  { 
   cout << "введите команду из предложенного списка" << endl; 
  } 
 } 
 return 0; 
}
