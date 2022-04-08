#include <iostream>
#include "infManager.h"
#include <conio.h>


void PrintLine()
{
	printf("___________________________________________________________________\n");
}

struct Person person[PERSON_NUM];
int flag = 1;

int ReceiveKeyCode()
{
	char ch = _getch();
	switch (ch)
	{
	case '0':
	{	
		PrintLine();
		printf("\n请依次键入“姓名”、“班级代号”、“生日日期（xxxx.xx.xx）”、“专业类别”、“成绩等级”、“年龄”，以“空格”或“换行”相隔。\n");
		string name = ""; int classN = 0; string bd = ""; string mj = ""; string acm = ""; short age = 0;
		cin >> name >> classN >> bd >> mj>>acm  >> age;
		int result = AddPerson(person, name,classN,bd,mj,acm,age);
		if (result)
		{
			printf("\n添加失败，可能键入了非法值。\n");
		}
		break;
	}
	case '1':
		DisplayAllPerson(person);
		break;
	case '2':
	{
		printf("\n请键入要删除的人员的姓名：");
		string name = "";
		cin >> name;
		int result = DeletePerson(person,name);
		if (result)
		{
			printf("\n删除失败，可能没有此人。\n");
		}
		break;
	}
	case '3':
	{
		string name = "";
		PrintLine();
		printf("\n键入名称以查找此人。\n");
		cin >> name;
		int result = FindPerson(person, name);
		if (result)
		{
			printf("\n查找失败，可能没有此人。\n");
		}
		break;
	}
	case '4':
	{
		string name = "";
		string nameNew = ""; int classNew = 0; string bdNew = ""; string mjNew = ""; string acmNew = ""; short ageNew = 0;
		PrintLine();
		printf("\n键入名称以编辑此人员信息。\n");
		cin >> name;
		cout << endl << "输入新信息数据，依次键入“姓名”、“班级代号”、“生日日期（xxxx.xx.xx）”、“专业类别”、“成绩等级”、“年龄”，以“空格”或“换行”相隔：";
		cin >> nameNew >> classNew >> bdNew >> mjNew >> acmNew >> ageNew;
		int result = EditPerson(person, name,nameNew,classNew,bdNew,mjNew,acmNew,ageNew);
		if (result)
		{
			printf("\n编辑失败，可能有非法值或未查询到此人员。\n");
		}
		break;
	}
	case '5':
	{
		PrintLine();
		printf("\n确定要清空通讯列表的所有内容吗？【确定】/【否】：\n");
		string sss = "否";
		cin >> sss;
		if (sss == "确定")
		{
			int result = CleanAllInf(person);
			if (result)
			{
				printf("\n删除失败。\n");
			}
		}
		else
		{
			printf("\n退出。\n");
		}
		break;
	}
	case '6':
	{
		PrintLine();
		printf("\n确定退出系统吗？【确定】/【否】：\n");
		string sss = "否";
		cin >> sss;
		if (sss == "确定")
		{
			int result = ExitSystem(&flag);
			flag = 0;
			if (result)
			{
				printf("\n退出失败。\n");
			}
		}
		else
		{
			printf("\n未退出。\n");
		}
		break;
	}
	default:
		return -1;
		break;
	}
	return 0;
}
int main()
{
	DisplayFucList();
	while (flag)
	{
		ReceiveKeyCode();
	}

	return 0;
}