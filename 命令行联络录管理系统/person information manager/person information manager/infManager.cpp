#include "infManager.h"
#include <process.h>

int personNum = 0;

int DisplayFucList()//显示功能列表
{
	cout << endl << "[0] 添加联络人" << endl << endl;
	cout << "[1] 显示所有人员的信息" << endl << endl;
	cout << "[2] 根据名称删除人员" << endl << endl;
	cout << "[3] 根据名称查找人员" << endl << endl;
	cout << "[4] 根据名称编辑人员信息" << endl << endl;
	cout << "[5] 清空联络录" << endl << endl;
	cout << "[6] 退出系统" << endl;
	return 0;
}
int AddPerson(struct Person* ppp, string name, int classNum, string bd, string mj, string acm, short age)//添加联络人
{
	if (personNum == PERSON_NUM)
	{
		system("cls");
		cout << endl << "人数已达到上限！请尝试删除一些人员或联系技术人员。" << endl;	
		DisplayFucList();
		return -1;
	}
	else
	{
		for (int i = 0; i < PERSON_NUM; i++)
		{
			if (ppp[i].name == "" && ppp[i].classNum == 0 && ppp[i].birthdayDate == "" && ppp[i].major == "" && ppp[i].achievement == "" && ppp[i].age == 0)
			{
				personNum++;
				ppp[i].name = name; ppp[i].classNum = classNum; ppp[i].birthdayDate = bd; ppp[i].major = mj; ppp[i].achievement = acm; ppp[i].age = age;
				i = PERSON_NUM + 10;
				break;
			}
		}
		system("cls");
		cout << endl <<"添加成功。" << endl;
		DisplayFucList();
		return 0;
	}
	
}
int DisplayAllPerson(struct Person*  ppp)//显示所有人员的信息
{
	system("cls");
	for (int i = 0; i < PERSON_NUM; i++)
	{	
		if(ppp[i].name != "")
			cout << endl << ppp[i].name << endl << ppp[i].classNum << endl << ppp[i].birthdayDate << endl << ppp[i].major << endl << ppp[i].achievement << endl << ppp[i].age << endl;
	}
	cout << endl << "显示完毕。" << endl;
	DisplayFucList();
	return 0;
}
int DeletePerson(struct Person* ppp, string name)//根据名称删除人员
{
	int dNum = 0;
	for (int i = 0; i < PERSON_NUM; i++)
	{
		if (ppp[i].name == name)
		{
			personNum--;
			dNum++;
			ppp[i].name = ""; ppp[i].classNum = 0; ppp[i].birthdayDate = ""; ppp[i].major = ""; ppp[i].achievement = ""; ppp[i].age = 0;

		}
	}
	system("cls");
	cout << endl << "删除完毕，共删除 " << dNum << " 个人员。" << endl;
	DisplayFucList();
	return 0;
}
int FindPerson(struct Person* ppp, string name)//根据名称查找人员
{
	int fNum = 0;
	system("cls");
	for (int i = 0; i < PERSON_NUM; i++)
	{
		if (ppp[i].name == name)
		{
			fNum++;
			cout << endl << ppp[i].name << endl << ppp[i].classNum << endl << ppp[i].birthdayDate << endl << ppp[i].major << endl << ppp[i].achievement << endl << ppp[i].age << endl;
		}
	}
	cout << endl << "检索完毕，共查找到 " << fNum << " 名人员。" << endl;
	DisplayFucList();
	return 0;
}
int EditPerson(struct Person* ppp, string name, string nameN, int classNumN, string bdN, string mjN, string acmN, short ageN)//根据名称编辑人员信息
{
	int dNum = 0;
	for (int i = 0; i < PERSON_NUM; i++)
	{
		if (ppp[i].name == name)
		{
			dNum++;
			ppp[i].name = nameN; ppp[i].classNum = classNumN; ppp[i].birthdayDate = bdN; ppp[i].major = mjN; ppp[i].achievement = acmN; ppp[i].age = ageN;

		}
	}
	system("cls");
	cout << endl << "编辑完成！共编辑了 " << dNum << " 位人员的信息。" << endl;
	DisplayFucList();
	return 0;
}
int CleanAllInf(struct Person* ppp )//清空联络录
{
	for (int i = 0; i < PERSON_NUM; i++)
	{
		ppp[i].name = ""; ppp[i].classNum = 0; ppp[i].birthdayDate = ""; ppp[i].major = ""; ppp[i].achievement = ""; ppp[i].age = 0;

	}
	system("cls");
	cout << endl << "您已清空数据库数据，误操作请联系技术人员，由其将您押送至附近的公安局。" << endl;
	DisplayFucList();
	return 0;
}
int ExitSystem(int * p)//退出系统
{
	*p = 0;
	cout << endl << "退出了系统！" << endl;
	return 0;
}