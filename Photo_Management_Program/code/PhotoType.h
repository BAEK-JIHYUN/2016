
#ifndef _PHOTOTYPE_H
#define _PHOTOTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/**
*	두 개의 아이템 사이의 관계 설정
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
	*	기본 생성자
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
	*	소멸자.
	*/
	~PhotoType() {}

	/**
	*	@brief	사진명을 얻는다
	*	@pre	사진명을 입력받는다
	*	@post	none
	*	@return	사진명 리턴
	*/
	string GetName() const
	{
		return m_Name;
	}

	/**
	*	@brief	이벤트명을 얻는다
	*	@pre	이벤트명을 입력받는다
	*	@post	none
	*	@return	이벤트명 리턴
	*/
	string GetEvent() const
	{
		return m_Event;
	}

	/**
	*	@brief	사진 속 사람들을 얻는다
	*	@pre	사진 속 사람들을 입력받는다
	*	@post	none
	*	@return	사진 속 사람들 리턴
	*/
	string GetPeople() const
	{
		return m_People;
	}

	/**
	*	@brief	사진 속 사람의 수를 얻는다
	*	@pre	사진 속 사람 배열이 초기화되어있다
	*	@post	none
	*	@return	사진 속 사람들 수 리턴
	*/
	int GetArrLength() const
	{
		return m_ArrLength;
	}

	/**
	*	@brief	사진 속 사람 배열 n번째 원소를 얻는다
	*	@pre	사진 속 사람 배열이 초기화되어있다
	*	@post	none
	*	@return	사진 속 사람들 배열 n번째 원소 리턴
	*/
	char* GetArrN(int n) const
	{
		return m_pArr[n];
	}

	/**
	*	@brief	사진 찍은 날짜를 얻는다
	*	@pre	사진 찍은 날짜를 입력받는다
	*	@post	none
	*	@return	사진 찍은 날짜 리턴
	*/
	string GetDate() const
	{
		return m_Date;
	}

	/**
	*	@brief	즐겨찾기 지정여부를 얻는다
	*	@pre	즐겨찾기 지정여부가 초기화되어있다
	*	@post	none
	*	@return	즐겨찾기 지정여부 리턴
	*/
	int GetFavorites() const
	{
		return m_favorites;
	}

	/**
	*	@brief	사진명을 입력받는다
	*	@pre	none
	*	@post	사진명이 입력됨
	*	@param	inName	photo name.
	*/
	void SetName(string inName)
	{
		m_Name = inName;
	}

	/**
	*	@brief	이벤트명을 입력받는다
	*	@pre	none
	*	@post	이벤트명이 입력됨
	*	@param	inEvent	event name.
	*/
	void SetEvent(string inEvent)
	{
		m_Event = inEvent;
	}

	/**
	*	@brief	사진 속 사람들을 입력받는다
	*	@pre	none
	*	@post	사진 속 사람들이 입력됨
	*	@param	in_People	people in photo.
	*/
	void SetPeople(char* inPeople)
	{
		m_People = inPeople;

	}

	/**
	*	@brief	사진 찍은 날짜를 입력받는다
	*	@pre	none
	*	@post	사진 찍은 날짜가 입력됨
	*	@param	in_pDate	photo date.
	*/
	void SetDate(string in_pDate)
	{
		m_Date = in_pDate;
	}

	/**
	*	@brief	사진 정보(레코드)를 입력
	*	@pre	none
	*	@post	사진 정보가 입력됨
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
	*	@brief	사진을 즐겨찾기로 지정
	*	@pre	none
	*	@post	사진이 즐겨찾기로 지정됨
	*/
	void setF() {
		this->m_favorites = 1;
	}

	/**
	*	@brief	사진이 기본으로 지정
	*	@pre	none
	*	@post	사진이 즐겨찾기가 아닌 기본으로 지정됨
	*/
	void deleteF() {
		this->m_favorites = 0;
	}

	/**
	*	@brief	사진 속에 포함된 사람을 각각 배열에 저장
	*	@pre	m_People이 initialized 되어있어야함
	*	@post	사진 속에 포함된 사람이 배열에 저장됨
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
	*	@brief	사진명을 스크린에 출력
	*	@pre	사진명이 입력됨
	*	@post	사진명이 스크린에 출력됨
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tPhoto Name   : " << m_Name << endl;
	};

	/**
	*	@brief	이벤트명을 스크린에 출력
	*	@pre	이벤트명이 입력됨
	*	@post	이벤트명이 스크린에 출력됨
	*/
	void DisplayEventOnScreen()
	{
		cout << "\tEvent : " << m_Event << endl;
	};

	/**
	*	@brief	사진 속 사람들을 스크린에 출력
	*	@pre	사진 속 사람들이 입력됨
	*	@post	사진 속 사람들이 스크린에 출력됨
	*/
	void DisplayPeopleOnScreen()
	{
		cout << "\tPeople : " << m_People << endl;

		setArr();
	};

	/**
	*	@brief	사진 찍은 날짜를 스크린에 출력
	*	@pre	사진 찍은 날짜가 입력됨
	*	@post	사진 찍은 날짜가 스크린에 출력됨
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tDate : " << m_Date << endl;
	};

	/**
	*	@brief	사진 정보(레코드)를 스크린에 출력
	*	@pre	사진 정보가 입력됨
	*	@post	사진 정보가 스크린에 출력됨
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayEventOnScreen();
		DisplayPeopleOnScreen();
		DisplayDateOnScreen();
	};

	/**
	*	@brief	키보드로부터 사진명을 입력받음
	*	@pre	none
	*	@post	사진명이 입력됨
	*/
	void SetNameFromKB();

	/**
	*	@brief	키보드로부터 이벤트명을 입력받음
	*	@pre	none
	*	@post	이벤트명이 입력됨
	*/
	void SetEventFromKB();

	/**
	*	@brief	키보드로부터 사진 속 사람들을 입력받음
	*	@pre	none
	*	@post	사진 속 사람들이 입력됨
	*/
	void SetPeopleFromKB();

	/**
	*	@brief	키보드로부터 사진 찍은 날짜를 입력받음
	*	@pre	none
	*	@post	사진 찍은 날짜가 입력됨
	*/
	void SetDateFromKB();

	/**
	*	@brief	키보드로부터 사진 정보를 입력받음
	*	@pre	none
	*	@post	사진 정보가 입력됨
	*/
	void SetRecordFromKB();

	/**
	*	@brief	파일에서 레코드를 읽는다
	*	@pre	타겟 파일이 오픈되어있음
	*	@post	사진 정보가 입력됨
	*	@param	fin	file descriptor.
	*	@return	함수가 잘 돌아가면 1을 리턴 아니면 0을 리턴
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	파일에 정보를 쓴다
	*	@pre	타겟 파일이 오픈되어있음, 리스트가 초기화됨
	*	@post	타겟 파일이 새 사진 정보를 포함함
	*	@param	fout	file descriptor.
	*	@return	함수가 잘 돌아가면 1을 리턴 아니면 0을 리턴
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	@brief	photo date으로 두 PhotoType을 비교한다
	*	@pre	두 PhotoType이 초기화되어야한다
	*	@post	타겟 파일이 새 사진 정보를 포함함
	*	@param	data	target item for comparing.
	*	@return	현재 사진의 date가 DATA의 date보다 작거나 같을 경우 LESSorEQUAL를 리턴,
	*			현재 사진의 date가 DATA의 date보다 크거나 같을 경우 GREATERorEQUAL를 리턴,
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
	string m_Name;			///< 사진명
	string m_Event;			///< 이벤트명
	char* m_People;			///< 사진 속 사람들
	char** m_pArr;			///< 사진 속 사람들 각각을 저장할 배열
	int m_ArrLength;		///< 배열의 길이 (사진 속 사람들의 수)
	string m_Date;			///< 사진 찍은 날짜 
	int m_favorites;		///< 즐겨찾기 여부. 1=즐겨찾기, 0=기본 

};

#endif	// _PHOTOTYPE_H
