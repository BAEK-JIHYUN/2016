#include "PhotoType.h"

// Ű����� ���� �������� �Է¹���
void PhotoType::SetNameFromKB()
{
	cout << "\tPhoto Name : ";
	cin >> m_Name;
}

// Ű����� ���� �̺�Ʈ���� �Է¹���
void PhotoType::SetEventFromKB()
{
	cout << "\tEvent Name : ";
	cin >> m_Event;
}

// Ű����� ���� ���� �� ������� �Է¹���
void PhotoType::SetPeopleFromKB()
{
	cout << "\tPeople : ";
	cin >> m_People;

	setArr();
}

// Ű����� ���� ���� ���� ��¥�� �Է¹���
void PhotoType::SetDateFromKB()
{
	cout << "\tDate : ";
	cin >> m_Date;
}

// Ű����� ���� ���� ������ �Է¹���
void PhotoType::SetRecordFromKB()
{
	SetNameFromKB();
	SetEventFromKB();
	SetPeopleFromKB();
	SetDateFromKB();
}

// ���Ͽ��� ���ڵ带 �д´�
int PhotoType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Name;
	fin >> m_Event;
	fin >> m_People;
	fin >> m_Date;

	return 1;
}

// ���Ͽ� ���ڵ带 ����
int PhotoType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << "Photo" << endl;
	fout << m_Name << " ";
	fout << m_Event << " ";
	fout << m_People << " ";
	fout << m_Date;

	return 1;
}

// Date���� 2���� ������Ÿ���� ���Ѵ�
RelationType PhotoType::ComparedByDate(const PhotoType &data)
{
	if (this->m_Date >= data.GetDate())
		return GREATERorEQUAL;
	else if (this->m_Name <= data.GetDate())
		return LESSorEQUAL;
}