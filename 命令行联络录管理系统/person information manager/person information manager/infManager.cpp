#include "infManager.h"
#include <process.h>

int personNum = 0;

int DisplayFucList()//��ʾ�����б�
{
	cout << endl << "[0] ���������" << endl << endl;
	cout << "[1] ��ʾ������Ա����Ϣ" << endl << endl;
	cout << "[2] ��������ɾ����Ա" << endl << endl;
	cout << "[3] �������Ʋ�����Ա" << endl << endl;
	cout << "[4] �������Ʊ༭��Ա��Ϣ" << endl << endl;
	cout << "[5] �������¼" << endl << endl;
	cout << "[6] �˳�ϵͳ" << endl;
	return 0;
}
int AddPerson(struct Person* ppp, string name, int classNum, string bd, string mj, string acm, short age)//���������
{
	if (personNum == PERSON_NUM)
	{
		system("cls");
		cout << endl << "�����Ѵﵽ���ޣ��볢��ɾ��һЩ��Ա����ϵ������Ա��" << endl;	
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
		cout << endl <<"��ӳɹ���" << endl;
		DisplayFucList();
		return 0;
	}
	
}
int DisplayAllPerson(struct Person*  ppp)//��ʾ������Ա����Ϣ
{
	system("cls");
	for (int i = 0; i < PERSON_NUM; i++)
	{	
		if(ppp[i].name != "")
			cout << endl << ppp[i].name << endl << ppp[i].classNum << endl << ppp[i].birthdayDate << endl << ppp[i].major << endl << ppp[i].achievement << endl << ppp[i].age << endl;
	}
	cout << endl << "��ʾ��ϡ�" << endl;
	DisplayFucList();
	return 0;
}
int DeletePerson(struct Person* ppp, string name)//��������ɾ����Ա
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
	cout << endl << "ɾ����ϣ���ɾ�� " << dNum << " ����Ա��" << endl;
	DisplayFucList();
	return 0;
}
int FindPerson(struct Person* ppp, string name)//�������Ʋ�����Ա
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
	cout << endl << "������ϣ������ҵ� " << fNum << " ����Ա��" << endl;
	DisplayFucList();
	return 0;
}
int EditPerson(struct Person* ppp, string name, string nameN, int classNumN, string bdN, string mjN, string acmN, short ageN)//�������Ʊ༭��Ա��Ϣ
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
	cout << endl << "�༭��ɣ����༭�� " << dNum << " λ��Ա����Ϣ��" << endl;
	DisplayFucList();
	return 0;
}
int CleanAllInf(struct Person* ppp )//�������¼
{
	for (int i = 0; i < PERSON_NUM; i++)
	{
		ppp[i].name = ""; ppp[i].classNum = 0; ppp[i].birthdayDate = ""; ppp[i].major = ""; ppp[i].achievement = ""; ppp[i].age = 0;

	}
	system("cls");
	cout << endl << "����������ݿ����ݣ����������ϵ������Ա�����佫��Ѻ���������Ĺ����֡�" << endl;
	DisplayFucList();
	return 0;
}
int ExitSystem(int * p)//�˳�ϵͳ
{
	*p = 0;
	cout << endl << "�˳���ϵͳ��" << endl;
	return 0;
}