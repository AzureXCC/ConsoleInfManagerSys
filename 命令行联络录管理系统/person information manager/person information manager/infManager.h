#pragma once
#include <iostream>

using namespace std;
#define PERSON_NUM 1000

struct Person
{
	string name = "";
	int classNum = 0;
	string birthdayDate = "";
	string major = "";
	string achievement = "";
	short age = 0;

};
int DisplayFucList();
int AddPerson(struct Person* p,string name,int classNum,string bd,string mj,string acm,short age);
int DisplayAllPerson(struct Person* ppp);
int DeletePerson(struct Person* ppp, string name);
int FindPerson(struct Person* ppp, string name);
int EditPerson(struct Person* ppp, string name, string nameN, int classNumN, string bdN, string mjN, string acmN, short ageN);
int CleanAllInf(struct Person* ppp);
int ExitSystem(int* p);
