#include <iostream>
#include <vector>
#include <string>

using namespace std;

void add(vector<vector<string>>& deal, const vector<int>& days, const int& m){////(3)ДОБАВКА ДЕЛА
	int d;
	cin >> d;
	if(d>days[m-1])
	{
		cout<<"В этом месяце "<<days[m-1]<<" дней"<<endl;
	}
	else
	{
		string delo;
		cin >> delo;
		deal[d-1].push_back(delo);
	}
	
	/*tail.resize(tail.size()+k,0);

	for(auto sus:tail)
	{
		cout << sus << ' ';
	}*/
	cout << endl;
}

void dump(const vector<vector<string>>& deal, const vector<int>& days, const int& m){	////(4)ВЫВОД ДЕЛ НА ДЕНЬ
	int d;
	cin >> d;
	if(d>days[m-1])
	{
		cout<<"В этом месяце "<<days[m-1]<<" дней"<<endl;
	}
	else
	{
		cout << deal[d-1].size() << ' ';
		for(auto sus:deal[d-1])
		{
			cout << sus << ' ';
		}
		cout << endl;
	}
}

void next(vector<vector<string>>& deal, const vector<int>& days, int& m){	////(5)СМЕНА МЕСЯЦА
	int end1,end2;
	if(m<12){
		end1=days[m-1];
		end2=days[m-1+1];
		m++;
	}
	else if(m==12){
		end1=days[m-1];
		m=1;
		end2=days[m-1];
	}
	
/*	int ys=1;
	for(auto kek:deal){		ТЕСТ
		cout << ys;
		for(auto lol:kek){
			cout << lol<<' ';
		}
		cout<<endl;
		ys++;
	}	*/
		
	if(end1>end2)
	{
		for(int i=end1;i>end2;i--)
		{
			deal[end2-1].insert(end(deal[end2-1]),begin(deal[i-1]),end(deal[i-1]));
		}
		deal.resize(end2);
	}
	else
	{
		deal.resize(end2);
	}
	
}

int main() {
	
	vector<int> days={31,28,31,30,31,30,30,31,30,31,30,31};		//вектор количества дней
	int m=1;		//счетчик месяца
	vector<vector<string>> deal(days[0]);
	string command;
	int q;
	cin >> q;		////(1)ВВОД ЧИСЛА КОМАНД
	cout << "введите команды add, dump или next" << endl;
	for(int i=0;i<q;i++)
	{
		cin >> command;	////(2)ВВОД КОМАНДЫ
		if(command=="add"){
			add(deal,days,m);
		}
		else if(command=="dump"){
			dump(deal,days,m);
		}
		else if(command=="next"){
			next(deal,days,m);
		}
		else
		{
			cout << "введите команду из предложенного списка" << endl;
		}
	}
	return 0;
}
