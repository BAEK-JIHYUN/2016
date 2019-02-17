
#ifndef _PHOTOTYPE_H
#define _PHOTOTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/**
*	�� ���� ������ ������ ���� ����
*/
enum RelationType { LESS, GREATER, EQUAL, LESSorEQUAL, GREATERorEQUAL};


#define PEOPLENUM 20

/**
*	@brief	Photo class.
*
*/
class PhotoType
{
public:
	/**
	*	�⺻ ������
	*/
	PhotoType()
	{
		m_Name = "";
		m_Event = "";
		m_People = new char[50];
		m_pArr = new char*[PEOPLENUM];
		m_ArrLength = 0;
		m_Date = "";
		m_favorites = 0;
	}

	/**
	*	�Ҹ���.
	*/
	~PhotoType() {}

	/**
	*	@brief	�������� ��´�
	*	@pre	�������� �Է¹޴´�
	*	@post	none
	*	@return	������ ����
	*/
	string GetName() const
	{
		return m_Name;
	}

	/**
	*	@brief	�̺�Ʈ���� ��´�
	*	@pre	�̺�Ʈ���� �Է¹޴´�
	*	@post	none
	*	@return	�̺�Ʈ�� ����
	*/
	string GetEvent() const
	{
		return m_Event;
	}

	/**
	*	@brief	���� �� ������� ��´�
	*	@pre	���� �� ������� �Է¹޴´�
	*	@post	none
	*	@return	���� �� ����� ����
	*/
	string GetPeople() const
	{
		return m_People;
	}

	/**
	*	@brief	���� �� ����� ���� ��´�
	*	@pre	���� �� ��� �迭�� �ʱ�ȭ�Ǿ��ִ�
	*	@post	none
	*	@return	���� �� ����� �� ����
	*/
	int GetArrLength() const
	{
		return m_ArrLength;
	}

	/**
	*	@brief	���� �� ��� �迭 n��° ���Ҹ� ��´�
	*	@pre	���� �� ��� �迭�� �ʱ�ȭ�Ǿ��ִ�
	*	@post	none
	*	@return	���� �� ����� �迭 n��° ���� ����
	*/
	char* GetArrN(int n) const
	{
		return m_pArr[n];
	}

	/**
	*	@brief	���� ���� ��¥�� ��´�
	*	@pre	���� ���� ��¥�� �Է¹޴´�
	*	@post	none
	*	@return	���� ���� ��¥ ����
	*/
	string GetDate() const
	{
		return m_Date;
	}

	/**
	*	@brief	���ã�� �������θ� ��´�
	*	@pre	���ã�� �������ΰ� �ʱ�ȭ�Ǿ��ִ�
	*	@post	none
	*	@return	���ã�� �������� ����
	*/
	int GetFavorites() const
	{
		return m_favorites;
	}

	/**
	*	@brief	�������� �Է¹޴´�
	*	@pre	none
	*	@post	�������� �Էµ�
	*	@param	inName	photo name.
	*/
	void SetName(string inName)
	{
		m_Name = inName;
	}

	/**
	*	@brief	�̺�Ʈ���� �Է¹޴´�
	*	@pre	none
	*	@post	�̺�Ʈ���� �Էµ�
	*	@param	inEvent	event name.
	*/
	void SetEvent(string inEvent)
	{
		m_Event = inEvent;
	}

	/**
	*	@brief	���� �� ������� �Է¹޴´�
	*	@pre	none
	*	@post	���� �� ������� �Էµ�
	*	@param	in_People	people in photo.
	*/
	void SetPeople(char* inPeople)
	{
		m_People = inPeople;

	}

	/**
	*	@brief	���� ���� ��¥�� �Է¹޴´�
	*	@pre	none
	*	@post	���� ���� ��¥�� �Էµ�
	*	@param	in_pDate	photo date.
	*/
	void SetDate(string in_pDate)
	{
		m_Date = in_pDate;
	}

	/**
	*	@brief	���� ����(���ڵ�)�� �Է�
	*	@pre	none
	*	@post	���� ������ �Էµ�
	*	@param	inName	photo name
	*	@param	inEvent	event name
	*	@param	inPeople	people in photo
	*	@param	inDate	photo date
	*/
	void SetRecord(string inName, string inEvent, char* inPeople, string inDate)
	{
		SetName(inName);
		SetEvent(inEvent);
		SetPeople(inPeople);
		SetDate(inDate);
	}

	/**
	*	@brief	������ ���ã��� ����
	*	@pre	none
	*	@post	������ ���ã��� ������
	*/
	void setF() {
		this->m_favorites = 1;
	}

	/**
	*	@brief	������ �⺻���� ����
	*	@pre	none
	*	@post	������ ���ã�Ⱑ �ƴ� �⺻���� ������
	*/
	void deleteF() {
		this->m_favorites = 0;
	}

	/**
	*	@brief	���� �ӿ� ���Ե� ����� ���� �迭�� ����
	*	@pre	m_People�� initialized �Ǿ��־����
	*	@post	���� �ӿ� ���Ե� ����� �迭�� �����
	*/
	void setArr() {
		string temp;
		string p;
		char* people = new char[50];

		for (int i = 0; i < strlen(m_People)+1; i++) {
			people[i] = m_People[i];
		}
		
		int index = 0;

		m_pArr[index++] = strtok(people, ",");

		while (m_pArr[index] = strtok(NULL, ",")) 
			index++;

		m_ArrLength = index;
	}

	/**
	*	@brief	�������� ��ũ���� ���
	*	@pre	�������� �Էµ�
	*	@post	�������� ��ũ���� ��µ�
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tPhoto Name   : " << m_Name << endl;
	};

	/**
	*	@brief	�̺�Ʈ���� ��ũ���� ���
	*	@pre	�̺�Ʈ���� �Էµ�
	*	@post	�̺�Ʈ���� ��ũ���� ��µ�
	*/
	void DisplayEventOnScreen()
	{
		cout << "\tEvent : " << m_Event << endl;
	};

	/**
	*	@brief	���� �� ������� ��ũ���� ���
	*	@pre	���� �� ������� �Էµ�
	*	@post	���� �� ������� ��ũ���� ��µ�
	*/
	void DisplayPeopleOnScreen()
	{
		cout << "\tPeople : " << m_People << endl;

		setArr();
	};

	/**
	*	@brief	���� ���� ��¥�� ��ũ���� ���
	*	@pre	���� ���� ��¥�� �Էµ�
	*	@post	���� ���� ��¥�� ��ũ���� ��µ�
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tDate : " << m_Date << endl;
	};

	/**
	*	@brief	���� ����(���ڵ�)�� ��ũ���� ���
	*	@pre	���� ������ �Էµ�
	*	@post	���� ������ ��ũ���� ��µ�
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayEventOnScreen();
		DisplayPeopleOnScreen();
		DisplayDateOnScreen();
	};

	/**
	*	@brief	Ű����κ��� �������� �Է¹���
	*	@pre	none
	*	@post	�������� �Էµ�
	*/
	void SetNameFromKB();

	/**
	*	@brief	Ű����κ��� �̺�Ʈ���� �Է¹���
	*	@pre	none
	*	@post	�̺�Ʈ���� �Էµ�
	*/
	void SetEventFromKB();

	/**
	*	@brief	Ű����κ��� ���� �� ������� �Է¹���
	*	@pre	none
	*	@post	���� �� ������� �Էµ�
	*/
	void SetPeopleFromKB();

	/**
	*	@brief	Ű����κ��� ���� ���� ��¥�� �Է¹���
	*	@pre	none
	*	@post	���� ���� ��¥�� �Էµ�
	*/
	void SetDateFromKB();

	/**
	*	@brief	Ű����κ��� ���� ������ �Է¹���
	*	@pre	none
	*	@post	���� ������ �Էµ�
	*/
	void SetRecordFromKB();

	/**
	*	@brief	���Ͽ��� ���ڵ带 �д´�
	*	@pre	Ÿ�� ������ ���µǾ�����
	*	@post	���� ������ �Էµ�
	*	@param	fin	file descriptor.
	*	@return	�Լ��� �� ���ư��� 1�� ���� �ƴϸ� 0�� ����
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	���Ͽ� ������ ����
	*	@pre	Ÿ�� ������ ���µǾ�����, ����Ʈ�� �ʱ�ȭ��
	*	@post	Ÿ�� ������ �� ���� ������ ������
	*	@param	fout	file descriptor.
	*	@return	�Լ��� �� ���ư��� 1�� ���� �ƴϸ� 0�� ����
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	@brief	photo date���� �� PhotoType�� ���Ѵ�
	*	@pre	�� PhotoType�� �ʱ�ȭ�Ǿ���Ѵ�
	*	@post	Ÿ�� ������ �� ���� ������ ������
	*	@param	data	target item for comparing.
	*	@return	���� ������ date�� DATA�� date���� �۰ų� ���� ��� LESSorEQUAL�� ����,
	*			���� ������ date�� DATA�� date���� ũ�ų� ���� ��� GREATERorEQUAL�� ����,
	*/
	RelationType ComparedByDate(const PhotoType &data);

	// operator overloading
	bool operator == (const PhotoType& item)
	{
		if (this->m_Name == item.GetName())
			return 1;
		else
			return 0;
	}

	// operator overloading
	bool operator > (const PhotoType& item)
	{
		if (this->m_Name > item.GetName())
			return 1;
		else
			return 0;
	}

	// operator overloading
	bool operator < (const PhotoType& item)
	{
		if (this->m_Name < item.GetName())
			return 1;
		else
			return 0;
	}

	// operator overloading
	friend ostream& operator << (ostream& out, PhotoType& item)
	{
		out << "\tName : " << item.GetName() << endl;
		out << "\tEvent : " << item.GetEvent() << endl;
		out << "\tPeople : " << item.GetPeople() << endl;
		out << "\tDate: " << item.GetDate() << endl;
		out << endl;

		return out;
	}

protected:
	string m_Name;			///< ������
	string m_Event;			///< �̺�Ʈ��
	char* m_People;			///< ���� �� �����
	char** m_pArr;			///< ���� �� ����� ������ ������ �迭
	int m_ArrLength;		///< �迭�� ���� (���� �� ������� ��)
	string m_Date;			///< ���� ���� ��¥ 
	int m_favorites;		///< ���ã�� ����. 1=���ã��, 0=�⺻ 

};

#endif	// _PHOTOTYPE_H
