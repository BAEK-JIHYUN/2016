#pragma once
#ifndef _FOLDERTYPE_H
#define _FOLDERTYPE_H

#include <iostream>
#include <fstream>	
#include <string>
#include <cstring>
using namespace std;

#include "PhotoType.h"
#include "BinarySearchTree.h"
#include "SortedListType.h"

/**
*	@brief	Folder class.
*
*/
class FolderType {
public:
	/**
	*	기본 생성자
	*/
	FolderType()
	{
		m_Name = "";
		m_Date = "";
		m_Num = 0;
		m_fList.InitList();
		m_pTree.InitTree();
		m_fListA.InitList();
		m_pTreeA.InitTree();
	}

	/**
	*	복사 생성자
	*/
	FolderType(const FolderType& folder)
	{
		m_Name = folder.m_Name;
		m_Date = folder.m_Date;
		m_Num = folder.m_Num;
		m_fList = folder.m_fList;
		m_pTree = folder.m_pTree;
		m_fListA = folder.m_fListA;
		m_pTreeA = folder.m_pTreeA;
	}

	/**
	*	소멸자
	*/
	~FolderType() {
	}

	/**
	*	@brief	Folder를 초기화한다.
	*	@pre	none.
	*	@post	Folder가 초기화된다.
	*/
	void InitFolder()
	{
		m_Name = "";
		m_Date = "";
		m_Num = 0;
		m_fList.InitList();
		m_pTree.InitTree();
		m_fListA.InitList();
		m_pTreeA.InitTree();
	}

	/**
	*	@brief	Folder Name을 get한다.
	*	@pre	Folder Name이 set 되어있다.
	*	@post	none.
	*	@return	Folder Name.
	*/
	string GetName() const
	{
		return m_Name;
	}

	/**
	*	@brief	Folder Date을 get한다.
	*	@pre	Folder Date이 set 되어있다.
	*	@post	none.
	*	@return	Folder Date.
	*/
	string GetDate()const
	{
		return m_Date;
	}

	/**
	*	@brief	폴더 속에 포함된 항목 수를 get한다.
	*	@pre	m_Num이 set 되어있다.
	*	@post	none.
	*	@return	m_Num.
	*/
	int GetNum()const
	{
		return m_Num;
	}

	/**
	*	@brief	Folder Name을 set한다.
	*	@pre	none.
	*	@post	Folder Name이 set 되어있다.
	*	@param	in_fName	Folder Name.
	*/
	void SetName(string in_fName)
	{
		m_Name = in_fName;
	}

	/**
	*	@brief	Folder Date을 set한다.
	*	@pre	none.
	*	@post	Folder Date이 set 되어있다.
	*	@param	in_Date		Folder Date.
	*/
	void SetDate(string in_Date)
	{
		m_Date = in_Date;
	}

	/**
	*	@brief	Folder record를 set한다.
	*	@pre	none.
	*	@post	Folder Record이 set 되어있다.
	*	@param	in_Name	Folder Name.
	*	@param	in_Date	Folder Date.
	*/
	void SetRecord(string in_Name, string in_Date)
	{
		SetName(in_Name);
		SetDate(in_Date);
	}

	/**
	*	@brief	Folder Name을 출력한다.
	*	@pre	Folder Name이 set 되어있다.
	*	@post	Folder Name이 출력된다.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tFolder Name   : " << m_Name << endl;
	}

	/**
	*	@brief	Folder Name을 출력한다.
	*	@pre	Folder Name이 set 되어있다.
	*	@post	Folder Name이 출력된다.
	*/
	void DisplayFolderName()
	{
		cout  << m_Name;
	}

	/**
	*	@brief	Folder Date을 출력한다.
	*	@pre	Folder Date이 set 되어있다.
	*	@post	Folder Date이 출력된다.
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tFolder Date : " << m_Date << endl;
	}

	/**
	*	@brief	폴더속에 포함된 항목 수를 출력한다.
	*	@pre	m_Num이 set 되어있다.
	*	@post	m_Num이 출력된다.
	*/
	void DisplayNumOnScreen()
	{
		cout << "\tItem Number in Folder: " << m_Num << endl;
	}

	/**
	*	@brief	Folder record를 출력한다.
	*	@pre	Folder record가 set 되어있다.
	*	@post	Folder record가 출력된다.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayDateOnScreen();
		DisplayNumOnScreen();
	}

	/**
	*	@brief	키보드로부터 Folder Name을 입력받아 set한다.
	*	@pre	none.
	*	@post	Folder Name이 set된다.
	*/
	void SetNameFromKB();

	/**
	*	@brief	키보드로부터 Folder Date을 입력받아 set한다.
	*	@pre	none.
	*	@post	Folder Date이 set된다.
	*/
	void SetDateFromKB();

	/**
	*	@brief	키보드로부터 Folder record를 입력받아 set한다.
	*	@pre	none.
	*	@post	Folder record가 set된다.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	file로부터 record를 읽어온다.
	*	@pre	target file이 오픈된다.
	*	@post	Image record가 set된다.
	*	@param	fin		file descriptor.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	read mode로 file을 오픈하고, file의 모든 data를 읽어 list를 set한다.
	*	@pre	file이 오픈되어있지 않다.
	*	@post	list는 file로부터의 모든 record를 보유한다.
	*/
	void ReadAllDataFromFile(ifstream& fin);

	/**
	*	@brief	file에 record를 입력한다.
	*	@pre	target file이 오픈되고, list는 initialized 되어있어야 한다.
	*	@post	target file이 새 Image record를 포함한다.
	*	@param	fout	file descriptor.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	@brief	write mode로 file을 오픈하고, file에 모든 data를 입력한다.
	*	@pre	file이 오픈되어있지 않다.
	*	@post	output file에 list가 저장된다.
	*/
	void WriteAllDataToFile(ofstream& fout);

	/**
	*	Compare two FolderTypes.
	*	@brief	Folder Date을 기준으로 두 개의 Foldertype을 비교한다.
	*	@pre	두 Foldertype은 initialized 되어있어야 한다.
	*	@post	없음.
	*	@param	data	비교를 위한 target Folder.
	*	@return	this.Date <= data.Date이면 LESSorEQUAL을,
	*			this.Date >= data.Date이면 GREATERorEQUAL을 리턴한다.
	*/
	RelationType CompareByDate(const FolderType item);

	/**
	*	@brief	새로운 폴더를 현재 폴더에 추가한다.
	*	@pre	Folder list가 initialized 되어 있어야 한다.
	*	@post	새 Folder가 현재 폴더에 추가된다.
	*	@param	item	추가할 데이터.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int addFolder(FolderType item);

	/**
	*	@brief	폴더를 삭제한다.
	*	@pre	삭제하고자하는 Folder Name이 list 내에 존재하는 값이어야 한다.
	*	@post	List 내의 해당 Folder가 삭제된다.
	*	@param	item	삭제할 데이터.
	*/
	void deleteFolder(FolderType item);

	/**
	*	@brief	새로운 사진파일을 현재 폴더에 추가한다.
	*	@pre	Photo Tree가 initialized 되어 있어야 한다.
	*	@post	새 Photo가 현재 폴더에 추가된다.
	*	@param	item	추가할 데이터.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int addPhoto(PhotoType item);

	/**
	*	@brief	사진을 삭제한다.
	*	@pre	삭제하고자하는 Photo Name이 Tree 내에 존재하는 값이어야 한다.
	*	@post	Tree 내의 해당 Photo가 삭제된다.
	*	@param	item	삭제할 데이터.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int deletePhoto(PhotoType item);

	/**
	*	@brief	폴더를 텅 빈 상태로 만든다.
	*	@pre	없음.
	*	@post	폴더 내의 모든 항목이 삭제된다.
	*/
	void MakeEmpty();

	/**
	*	@brief	현재 폴더의 이름과 포함된 항목 수, 폴더들 그리고 사진들을 이름순으로 화면에 출력한다.
	*	@pre	Folder에 포함된 항목들이 set되어있어야한다.
	*	@post	Folder내의 모든 항목들이 출력된다.
	*/
	void displayFolderByName();

	/**
	*	@brief	Folder Name이 일치하는 list내 폴더를 찾아서 반환한다.
	*	@pre	Folder list가 initialized 되어 있어야 한다.
	*	@post	List 내에 넘겨받은 폴더와 Folder Name이 일치하는 값을 찾아서 item으로 반환된다.
	*	@param	item	찾고자 하는 Folder Name이 입력된 FolderType값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int GetSearchByName(FolderType& item);

	/**
	*	@brief	입력한 구간 내에 포함되는 list내 폴더를 찾아서 출력한다.
	*	@pre	Folder list가 initialized 되어 있어야 한다.
	*	@post	입력한 구간 내에 포함되는 list내 폴더를 찾아서 출력한다.
	*	@param	item1,item2		입력한 구간의 시작지점과 끝지점이 입력된 FolderType
	*/
	void DisplayFolderInTimeInterval(FolderType& item1, FolderType& item2, bool& found);

	/**
	*	@brief	Folder Name이 일치하는 list내 폴더를 찾는다.
	*	@pre	Folder list가 initialized 되어 있어야 한다.
	*	@post	List 내에 넘겨받은 폴더와 Folder Name이 일치하는 값을 찾아서 주소값을 반환된다.
	*	@param	item	찾고자 하는 Folder Name이 입력된 FolderType값.
	*/
	FolderType* GetAddressByName(FolderType item);

	/**
	*	@brief	전체 범위에서 Folder Name이 일치하는 list내 폴더를 찾아서 반환한다.
	*	@pre	Folder list가 initialized 되어 있어야 한다.
	*	@post	List 내에 넘겨받은 폴더와 Folder Name이 일치하는 값을 찾아서 item으로 반환된다.
	*	@param	item	찾고자 하는 Folder Name이 입력된 FolderType값.
	*/
	void GetOverallSearchByName(FolderType& item, bool& found);

	/**
	*	@brief	전체 범위에서 입력한 구간 내에 포함되는 list내 폴더를 찾아서 출력한다.
	*	@pre	Folder list가 initialized 되어 있어야 한다.
	*	@post	입력한 구간 내에 포함되는 list내 폴더를 찾아서 출력한다.
	*	@param	item1,item2		입력한 구간의 시작지점과 끝지점이 입력된 FolderType
	*/
	void DisplayOverallFolderInTimeInterval(FolderType& item1, FolderType& item2, bool& found);

	/**
	*	@brief	Photo Name이 일치하는 Tree내 사진을 찾아서 반환한다.
	*	@pre	Photo Tree가 initialized 되어 있어야 한다.
	*	@post	Tree 내에 넘겨받은 사진과 Photo Name이 일치하는 값을 찾아서 item으로 반환된다.
	*	@param	item	찾고자 하는 Photo Name이 입력된 PhotoType값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int GetSearchByName(PhotoType& item);

	/**
	*	@brief	Photo Event Name이 일치하는 Tree내 사진을 찾아서 반환한다.
	*	@pre	Photo Tree가 initialized 되어 있어야 한다.
	*	@post	Tree 내에 넘겨받은 사진과 Photo Event Name이 일치하는 값을 찾아서 item으로 반환된다.
	*	@param	item	찾고자 하는 Photo Event Name이 입력된 PhotoType값.
	*/
	void GetSearchByEvent(PhotoType& item, bool& found);

	/**
	*	@brief	입력된 사람을 포함하는 Tree내 사진을 찾아서 반환한다.
	*	@pre	Photo Tree가 initialized 되어 있어야 한다.
	*	@post	입력된 사람을 포함하는 사진을 찾아서 item으로 반환된다.
	*	@param	item	입력된 사람을 포함하는 PhotoType값.
	*/
	void GetSearchByPeople(PhotoType& item, bool& found);

	/**
	*	@brief	입력한 구간 내에 포함되는 Tree내 사진을 찾아서 반환한다.
	*	@pre	Photo Tree가 initialized 되어 있어야 한다.
	*	@post	입력한 구간 내에 포함되는 Tree내 사진을 찾아서 반환한다.
	*	@param	item1,item2		입력한 구간의 시작지점과 끝지점이 입력된 PhotoType
	*/
	void DisplayPhotoInTimeInterval(PhotoType& item1, PhotoType& item2, bool& found);

	/**
	*	@brief	전체 범위에서 Photo Name이 일치하는 Tree내 사진을 찾아서 반환한다.
	*	@pre	Photo Tree가 initialized 되어 있어야 한다.
	*	@post	Tree 내에 넘겨받은 사진과 Photo Name이 일치하는 값을 찾아서 item으로 반환된다.
	*	@param	item	찾고자 하는 Photo Name이 입력된 PhotoType값.
	*	@param	found	찾으면 true, 아니면 false 저장
	*/
	void GetOverallSearchByName(PhotoType& item, bool& found);

	/**
	*	@brief	전체 범위에서 Photo Event Name이 일치하는 Tree내 사진을 찾아서 반환한다.
	*	@pre	Photo Tree가 initialized 되어 있어야 한다.
	*	@post	Tree 내에 넘겨받은 사진과 Photo Event Name이 일치하는 값을 찾아서 item으로 반환된다.
	*	@param	item	찾고자 하는 Photo Event Name이 입력된 PhotoType값.
	*/
	void GetOverallSearchByEvent(PhotoType& item, bool& found);

	/**
	*	@brief	전체 범위에서 입력된 사람을 포함하는 Tree내 사진을 찾아서 반환한다.
	*	@pre	Photo Tree가 initialized 되어 있어야 한다.
	*	@post	입력된 사람을 포함하는 사진을 찾아서 item으로 반환된다.
	*	@param	item	입력된 사람을 포함하는 PhotoType값.
	*/
	void GetOverallSearchByPeople(PhotoType& item, bool& found);

	/**
	*	@brief	입력한 구간 내에 포함되는 Tree내 사진을 찾아서 반환한다.
	*	@pre	Photo Tree가 initialized 되어 있어야 한다.
	*	@post	입력한 구간 내에 포함되는 Tree내 사진을 찾아서 반환한다.
	*	@param	item1,item2		입력한 구간의 시작지점과 끝지점이 입력된 PhotoType
	*/
	void DisplayOverallPhotoInTimeInterval(PhotoType& item1, PhotoType& item2, bool& found);

	/**
	*	@brief	Photo Name이 일치하는 Tree내 사진을 찾아서 즐겨찾기로 지정한다
	*	@pre	Photo Tree가 initialized 되어 있어야 한다.
	*	@post	Tree 내에 넘겨받은 사진과 Photo Name이 일치하는 값을 찾아서 즐겨찾기로 지정한다.
	*	@param	item	찾고자 하는 Photo Name이 입력된 PhotoType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int setFavorites(PhotoType& item);

	/**
	*	@brief	Photo Name이 일치하는 Tree내 사진을 찾아서 즐겨찾기에서 삭제한다
	*	@pre	Photo Tree가 initialized 되어 있어야 한다.
	*	@post	Tree 내에 넘겨받은 사진과 Photo Name이 일치하는 값을 찾아서 즐겨찾기에서 삭제한다
	*	@param	item	찾고자 하는 Photo Name이 입력된 PhotoType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int deleteFavorites(PhotoType& item);

	/**
	*	@brief	전체 범위에서 즐겨찾기로 지정된 Tree내 사진을 찾아서 반환한다.
	*	@pre	Photo Tree가 initialized 되어 있어야 한다.
	*	@post	즐겨찾기도 지정된 사진을 찾아서 item으로 반환된다.
	*/
	void GetOverallFavorites();

	/**
	*	@brief	대입연산자 오버로딩.
	*/
	FolderType operator =(FolderType& folder);


	/**
	*	@brief	operator overloading
	*/
	bool operator == (const FolderType& item)
	{
		if (this->m_Name == item.GetName())
			return 1;
		else
			return 0;
	}

	/**
	*	@brief	operator overloading
	*/
	bool operator > (const FolderType& item)
	{
		if (this->m_Name > item.GetName())
			return 1;
		else
			return 0;
	}

	/**
	*	@brief	operator overloading
	*/
	bool operator < (const FolderType& item)
	{
		if (this->m_Name < item.GetName())
			return 1;
		else
			return 0;
	}


private:
	string m_Name;		///< Folder name.
	string m_Date;		///< Date to generate folder.
	int m_Num;			///< Item number in folder.
	SortedListType<FolderType> m_fList;
	BinarySearchTree<PhotoType> m_pTree;
	SortedListType<FolderType*> m_fListA;
	BinarySearchTree<PhotoType*> m_pTreeA;
};


#endif	// _FOLDERTYPE_H