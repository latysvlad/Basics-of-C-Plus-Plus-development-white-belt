﻿#include <string>
#include <iostream>

using namespace std;

struct Specialization{
	string value;
	explicit Specialization(string new_value){
		value=new_value;
	}
};

struct Course{
	string value;
	explicit Course(string new_value){
		value=new_value;
	}
};

struct Week{
	string value;
	explicit Week(string new_value){
		value=new_value;
	}
};

struct LectureTitle{
	string specialization;
	string course;
	string week;
	
	LectureTitle(Specialization new_specialization, Course new_course, Week new_week)
	{
		specialization=new_specialization.value;
		course=new_course.value;
		week=new_week.value;
	}
};

void PrintName(const LectureTitle& title){
	cout<<title.specialization<<" "<<title.course<<" "<<title.week<<endl;
}

int main(){
	
//	LectureTitle title("C++","White belt","4th");
//	LectureTitle title(string("C++"),string("White belt"),string("4th"));
//	LectureTitle title{"C++","White belt","4th"};
//	LectureTitle title({"C++"},{"White belt"},{"4th"});
/*	LectureTitle title(
		Course{"White belt"},
		Specialization{"C++"},
		Week{"4th"}
	);*/
/*	LectureTitle title(
		Specialization{"C++"},
		Week{"4th"},
		Course{"White belt"}
	);*/
	
	
	LectureTitle title{
		Specialization{"C++"},
		Course{"White belt"},
		Week{"4th"}
	};
	PrintName(title);
	
	return 0;
}
