#include <iostream>
#include <string> 
#include <set> 
#include <map> 
 
using namespace std; 
 
int main() { 
 map<set<string>, int> bus;
 int q,n;
 cin >> q;
 for(int i=0;i<q;i++) 
 {
  cin>>n;
  set<string> bus_stops;
  for(int j=0;j<n;j++)
  {
	string stop;
  	cin>>stop;
  	bus_stops.insert(stop);
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
