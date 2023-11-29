#include <iostream>
#include <string> 
#include <vector> 
#include <map> 
 
using namespace std; 
 
int main() { 
 map<vector<string>, int> bus;
 int q,n;
 cin >> q;
 for(int i=0;i<q;i++) 
 {
  vector<string> bus_stops;
  cin>>n;
  bus_stops.assign(n,"0");
  for(auto& stop:bus_stops)
  {
  	cin>>stop;
  }
  if(bus.count(bus_stops)==0)
  {
  	int num=bus.size()+1;
  	bus[bus_stops]=num;
  	cout<<"New bus "<<bus[bus_stops];
  }
  else
  {
  	cout<<"Already exists for "<<bus[bus_stops];
  }
 } 
 return 0; 
}
