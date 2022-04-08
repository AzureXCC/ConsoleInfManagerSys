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
		printf("\n�����μ��롰�����������༶���š������������ڣ�xxxx.xx.xx��������רҵ��𡱡����ɼ��ȼ����������䡱���ԡ��ո񡱻򡰻��С������\n");
		string name = ""; int classN = 0; string bd = ""; string mj = ""; string acm = ""; short age = 0;
		cin >> name >> classN >> bd >> mj>>acm  >> age;
		int result = AddPerson(person, name,classN,bd,mj,acm,age);
		if (result)
		{
			printf("\n���ʧ�ܣ����ܼ����˷Ƿ�ֵ��\n");
		}
		break;
	}
	case '1':
		DisplayAllPerson(person);
		break;
	case '2':
	{
		printf("\n�����Ҫɾ������Ա��������");
		string name = "";
		cin >> name;
		int result = DeletePerson(person,name);
		if (result)
		{
			printf("\nɾ��ʧ�ܣ�����û�д��ˡ�\n");
		}
		break;
	}
	case '3':
	{
		string name = "";
		PrintLine();
		printf("\n���������Բ��Ҵ��ˡ�\n");
		cin >> name;
		int result = FindPerson(person, name);
		if (result)
		{
			printf("\n����ʧ�ܣ�����û�д��ˡ�\n");
		}
		break;
	}
	case '4':
	{
		string name = "";
		string nameNew = ""; int classNew = 0; string bdNew = ""; string mjNew = ""; string acmNew = ""; short ageNew = 0;
		PrintLine();
		printf("\n���������Ա༭����Ա��Ϣ��\n");
		cin >> name;
		cout << endl << "��������Ϣ���ݣ����μ��롰�����������༶���š������������ڣ�xxxx.xx.xx��������רҵ��𡱡����ɼ��ȼ����������䡱���ԡ��ո񡱻򡰻��С������";
		cin >> nameNew >> classNew >> bdNew >> mjNew >> acmNew >> ageNew;
		int result = EditPerson(person, name,nameNew,classNew,bdNew,mjNew,acmNew,ageNew);
		if (result)
		{
			printf("\n�༭ʧ�ܣ������зǷ�ֵ��δ��ѯ������Ա��\n");
		}
		break;
	}
	case '5':
	{
		PrintLine();
		printf("\nȷ��Ҫ���ͨѶ�б�����������𣿡�ȷ����/���񡿣�\n");
		string sss = "��";
		cin >> sss;
		if (sss == "ȷ��")
		{
			int result = CleanAllInf(person);
			if (result)
			{
				printf("\nɾ��ʧ�ܡ�\n");
			}
		}
		else
		{
			printf("\n�˳���\n");
		}
		break;
	}
	case '6':
	{
		PrintLine();
		printf("\nȷ���˳�ϵͳ�𣿡�ȷ����/���񡿣�\n");
		string sss = "��";
		cin >> sss;
		if (sss == "ȷ��")
		{
			int result = ExitSystem(&flag);
			flag = 0;
			if (result)
			{
				printf("\n�˳�ʧ�ܡ�\n");
			}
		}
		else
		{
			printf("\nδ�˳���\n");
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