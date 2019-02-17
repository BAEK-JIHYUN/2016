#include "PhotoType.h"

// 키보드로 통해 사진명을 입력받음
void PhotoType::SetNameFromKB()
{
	cout << "\tPhoto Name : ";
	cin >> m_Name;
}

// 키보드로 통해 이벤트명을 입력받음
void PhotoType::SetEventFromKB()
{
	cout << "\tEvent Name : ";
	cin >> m_Event;
}

// 키보드로 통해 사진 속 사람들을 입력받음
void PhotoType::SetPeopleFromKB()
{
	cout << "\tPeople : ";
	cin >> m_People;

	setArr();
}

// 키보드로 통해 사진 찍은 날짜를 입력받음
void PhotoType::SetDateFromKB()
{
	cout << "\tDate : ";
	cin >> m_Date;
}

// 키보드로 통해 사진 정보를 입력받음
void PhotoType::SetRecordFromKB()
{
	SetNameFromKB();
	SetEventFromKB();
	SetPeopleFromKB();
	SetDateFromKB();
}

// 파일에서 레코드를 읽는다
int PhotoType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Name;
	fin >> m_Event;
	fin >> m_People;
	fin >> m_Date;

	return 1;
}

// 파일에 레코드를 쓴다
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

// Date으로 2개의 아이템타입을 비교한다
RelationType PhotoType::ComparedByDate(const PhotoType &data)
{
	if (this->m_Date >= data.GetDate())
		return GREATERorEQUAL;
	else if (this->m_Name <= data.GetDate())
		return LESSorEQUAL;
}