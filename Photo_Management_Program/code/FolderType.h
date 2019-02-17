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
	*	�⺻ ������
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
	*	���� ������
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
	*	�Ҹ���
	*/
	~FolderType() {
	}

	/**
	*	@brief	Folder�� �ʱ�ȭ�Ѵ�.
	*	@pre	none.
	*	@post	Folder�� �ʱ�ȭ�ȴ�.
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
	*	@brief	Folder Name�� get�Ѵ�.
	*	@pre	Folder Name�� set �Ǿ��ִ�.
	*	@post	none.
	*	@return	Folder Name.
	*/
	string GetName() const
	{
		return m_Name;
	}

	/**
	*	@brief	Folder Date�� get�Ѵ�.
	*	@pre	Folder Date�� set �Ǿ��ִ�.
	*	@post	none.
	*	@return	Folder Date.
	*/
	string GetDate()const
	{
		return m_Date;
	}

	/**
	*	@brief	���� �ӿ� ���Ե� �׸� ���� get�Ѵ�.
	*	@pre	m_Num�� set �Ǿ��ִ�.
	*	@post	none.
	*	@return	m_Num.
	*/
	int GetNum()const
	{
		return m_Num;
	}

	/**
	*	@brief	Folder Name�� set�Ѵ�.
	*	@pre	none.
	*	@post	Folder Name�� set �Ǿ��ִ�.
	*	@param	in_fName	Folder Name.
	*/
	void SetName(string in_fName)
	{
		m_Name = in_fName;
	}

	/**
	*	@brief	Folder Date�� set�Ѵ�.
	*	@pre	none.
	*	@post	Folder Date�� set �Ǿ��ִ�.
	*	@param	in_Date		Folder Date.
	*/
	void SetDate(string in_Date)
	{
		m_Date = in_Date;
	}

	/**
	*	@brief	Folder record�� set�Ѵ�.
	*	@pre	none.
	*	@post	Folder Record�� set �Ǿ��ִ�.
	*	@param	in_Name	Folder Name.
	*	@param	in_Date	Folder Date.
	*/
	void SetRecord(string in_Name, string in_Date)
	{
		SetName(in_Name);
		SetDate(in_Date);
	}

	/**
	*	@brief	Folder Name�� ����Ѵ�.
	*	@pre	Folder Name�� set �Ǿ��ִ�.
	*	@post	Folder Name�� ��µȴ�.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tFolder Name   : " << m_Name << endl;
	}

	/**
	*	@brief	Folder Name�� ����Ѵ�.
	*	@pre	Folder Name�� set �Ǿ��ִ�.
	*	@post	Folder Name�� ��µȴ�.
	*/
	void DisplayFolderName()
	{
		cout  << m_Name;
	}

	/**
	*	@brief	Folder Date�� ����Ѵ�.
	*	@pre	Folder Date�� set �Ǿ��ִ�.
	*	@post	Folder Date�� ��µȴ�.
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tFolder Date : " << m_Date << endl;
	}

	/**
	*	@brief	�����ӿ� ���Ե� �׸� ���� ����Ѵ�.
	*	@pre	m_Num�� set �Ǿ��ִ�.
	*	@post	m_Num�� ��µȴ�.
	*/
	void DisplayNumOnScreen()
	{
		cout << "\tItem Number in Folder: " << m_Num << endl;
	}

	/**
	*	@brief	Folder record�� ����Ѵ�.
	*	@pre	Folder record�� set �Ǿ��ִ�.
	*	@post	Folder record�� ��µȴ�.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayDateOnScreen();
		DisplayNumOnScreen();
	}

	/**
	*	@brief	Ű����κ��� Folder Name�� �Է¹޾� set�Ѵ�.
	*	@pre	none.
	*	@post	Folder Name�� set�ȴ�.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Ű����κ��� Folder Date�� �Է¹޾� set�Ѵ�.
	*	@pre	none.
	*	@post	Folder Date�� set�ȴ�.
	*/
	void SetDateFromKB();

	/**
	*	@brief	Ű����κ��� Folder record�� �Է¹޾� set�Ѵ�.
	*	@pre	none.
	*	@post	Folder record�� set�ȴ�.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	file�κ��� record�� �о�´�.
	*	@pre	target file�� ���µȴ�.
	*	@post	Image record�� set�ȴ�.
	*	@param	fin		file descriptor.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	read mode�� file�� �����ϰ�, file�� ��� data�� �о� list�� set�Ѵ�.
	*	@pre	file�� ���µǾ����� �ʴ�.
	*	@post	list�� file�κ����� ��� record�� �����Ѵ�.
	*/
	void ReadAllDataFromFile(ifstream& fin);

	/**
	*	@brief	file�� record�� �Է��Ѵ�.
	*	@pre	target file�� ���µǰ�, list�� initialized �Ǿ��־�� �Ѵ�.
	*	@post	target file�� �� Image record�� �����Ѵ�.
	*	@param	fout	file descriptor.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	@brief	write mode�� file�� �����ϰ�, file�� ��� data�� �Է��Ѵ�.
	*	@pre	file�� ���µǾ����� �ʴ�.
	*	@post	output file�� list�� ����ȴ�.
	*/
	void WriteAllDataToFile(ofstream& fout);

	/**
	*	Compare two FolderTypes.
	*	@brief	Folder Date�� �������� �� ���� Foldertype�� ���Ѵ�.
	*	@pre	�� Foldertype�� initialized �Ǿ��־�� �Ѵ�.
	*	@post	����.
	*	@param	data	�񱳸� ���� target Folder.
	*	@return	this.Date <= data.Date�̸� LESSorEQUAL��,
	*			this.Date >= data.Date�̸� GREATERorEQUAL�� �����Ѵ�.
	*/
	RelationType CompareByDate(const FolderType item);

	/**
	*	@brief	���ο� ������ ���� ������ �߰��Ѵ�.
	*	@pre	Folder list�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	�� Folder�� ���� ������ �߰��ȴ�.
	*	@param	item	�߰��� ������.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int addFolder(FolderType item);

	/**
	*	@brief	������ �����Ѵ�.
	*	@pre	�����ϰ����ϴ� Folder Name�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	List ���� �ش� Folder�� �����ȴ�.
	*	@param	item	������ ������.
	*/
	void deleteFolder(FolderType item);

	/**
	*	@brief	���ο� ���������� ���� ������ �߰��Ѵ�.
	*	@pre	Photo Tree�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	�� Photo�� ���� ������ �߰��ȴ�.
	*	@param	item	�߰��� ������.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int addPhoto(PhotoType item);

	/**
	*	@brief	������ �����Ѵ�.
	*	@pre	�����ϰ����ϴ� Photo Name�� Tree ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	Tree ���� �ش� Photo�� �����ȴ�.
	*	@param	item	������ ������.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int deletePhoto(PhotoType item);

	/**
	*	@brief	������ �� �� ���·� �����.
	*	@pre	����.
	*	@post	���� ���� ��� �׸��� �����ȴ�.
	*/
	void MakeEmpty();

	/**
	*	@brief	���� ������ �̸��� ���Ե� �׸� ��, ������ �׸��� �������� �̸������� ȭ�鿡 ����Ѵ�.
	*	@pre	Folder�� ���Ե� �׸���� set�Ǿ��־���Ѵ�.
	*	@post	Folder���� ��� �׸���� ��µȴ�.
	*/
	void displayFolderByName();

	/**
	*	@brief	Folder Name�� ��ġ�ϴ� list�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	Folder list�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	List ���� �Ѱܹ��� ������ Folder Name�� ��ġ�ϴ� ���� ã�Ƽ� item���� ��ȯ�ȴ�.
	*	@param	item	ã���� �ϴ� Folder Name�� �Էµ� FolderType��.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int GetSearchByName(FolderType& item);

	/**
	*	@brief	�Է��� ���� ���� ���ԵǴ� list�� ������ ã�Ƽ� ����Ѵ�.
	*	@pre	Folder list�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	�Է��� ���� ���� ���ԵǴ� list�� ������ ã�Ƽ� ����Ѵ�.
	*	@param	item1,item2		�Է��� ������ ���������� �������� �Էµ� FolderType
	*/
	void DisplayFolderInTimeInterval(FolderType& item1, FolderType& item2, bool& found);

	/**
	*	@brief	Folder Name�� ��ġ�ϴ� list�� ������ ã�´�.
	*	@pre	Folder list�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	List ���� �Ѱܹ��� ������ Folder Name�� ��ġ�ϴ� ���� ã�Ƽ� �ּҰ��� ��ȯ�ȴ�.
	*	@param	item	ã���� �ϴ� Folder Name�� �Էµ� FolderType��.
	*/
	FolderType* GetAddressByName(FolderType item);

	/**
	*	@brief	��ü �������� Folder Name�� ��ġ�ϴ� list�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	Folder list�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	List ���� �Ѱܹ��� ������ Folder Name�� ��ġ�ϴ� ���� ã�Ƽ� item���� ��ȯ�ȴ�.
	*	@param	item	ã���� �ϴ� Folder Name�� �Էµ� FolderType��.
	*/
	void GetOverallSearchByName(FolderType& item, bool& found);

	/**
	*	@brief	��ü �������� �Է��� ���� ���� ���ԵǴ� list�� ������ ã�Ƽ� ����Ѵ�.
	*	@pre	Folder list�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	�Է��� ���� ���� ���ԵǴ� list�� ������ ã�Ƽ� ����Ѵ�.
	*	@param	item1,item2		�Է��� ������ ���������� �������� �Էµ� FolderType
	*/
	void DisplayOverallFolderInTimeInterval(FolderType& item1, FolderType& item2, bool& found);

	/**
	*	@brief	Photo Name�� ��ġ�ϴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	Photo Tree�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	Tree ���� �Ѱܹ��� ������ Photo Name�� ��ġ�ϴ� ���� ã�Ƽ� item���� ��ȯ�ȴ�.
	*	@param	item	ã���� �ϴ� Photo Name�� �Էµ� PhotoType��.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int GetSearchByName(PhotoType& item);

	/**
	*	@brief	Photo Event Name�� ��ġ�ϴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	Photo Tree�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	Tree ���� �Ѱܹ��� ������ Photo Event Name�� ��ġ�ϴ� ���� ã�Ƽ� item���� ��ȯ�ȴ�.
	*	@param	item	ã���� �ϴ� Photo Event Name�� �Էµ� PhotoType��.
	*/
	void GetSearchByEvent(PhotoType& item, bool& found);

	/**
	*	@brief	�Էµ� ����� �����ϴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	Photo Tree�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	�Էµ� ����� �����ϴ� ������ ã�Ƽ� item���� ��ȯ�ȴ�.
	*	@param	item	�Էµ� ����� �����ϴ� PhotoType��.
	*/
	void GetSearchByPeople(PhotoType& item, bool& found);

	/**
	*	@brief	�Է��� ���� ���� ���ԵǴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	Photo Tree�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	�Է��� ���� ���� ���ԵǴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@param	item1,item2		�Է��� ������ ���������� �������� �Էµ� PhotoType
	*/
	void DisplayPhotoInTimeInterval(PhotoType& item1, PhotoType& item2, bool& found);

	/**
	*	@brief	��ü �������� Photo Name�� ��ġ�ϴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	Photo Tree�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	Tree ���� �Ѱܹ��� ������ Photo Name�� ��ġ�ϴ� ���� ã�Ƽ� item���� ��ȯ�ȴ�.
	*	@param	item	ã���� �ϴ� Photo Name�� �Էµ� PhotoType��.
	*	@param	found	ã���� true, �ƴϸ� false ����
	*/
	void GetOverallSearchByName(PhotoType& item, bool& found);

	/**
	*	@brief	��ü �������� Photo Event Name�� ��ġ�ϴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	Photo Tree�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	Tree ���� �Ѱܹ��� ������ Photo Event Name�� ��ġ�ϴ� ���� ã�Ƽ� item���� ��ȯ�ȴ�.
	*	@param	item	ã���� �ϴ� Photo Event Name�� �Էµ� PhotoType��.
	*/
	void GetOverallSearchByEvent(PhotoType& item, bool& found);

	/**
	*	@brief	��ü �������� �Էµ� ����� �����ϴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	Photo Tree�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	�Էµ� ����� �����ϴ� ������ ã�Ƽ� item���� ��ȯ�ȴ�.
	*	@param	item	�Էµ� ����� �����ϴ� PhotoType��.
	*/
	void GetOverallSearchByPeople(PhotoType& item, bool& found);

	/**
	*	@brief	�Է��� ���� ���� ���ԵǴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	Photo Tree�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	�Է��� ���� ���� ���ԵǴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@param	item1,item2		�Է��� ������ ���������� �������� �Էµ� PhotoType
	*/
	void DisplayOverallPhotoInTimeInterval(PhotoType& item1, PhotoType& item2, bool& found);

	/**
	*	@brief	Photo Name�� ��ġ�ϴ� Tree�� ������ ã�Ƽ� ���ã��� �����Ѵ�
	*	@pre	Photo Tree�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	Tree ���� �Ѱܹ��� ������ Photo Name�� ��ġ�ϴ� ���� ã�Ƽ� ���ã��� �����Ѵ�.
	*	@param	item	ã���� �ϴ� Photo Name�� �Էµ� PhotoType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int setFavorites(PhotoType& item);

	/**
	*	@brief	Photo Name�� ��ġ�ϴ� Tree�� ������ ã�Ƽ� ���ã�⿡�� �����Ѵ�
	*	@pre	Photo Tree�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	Tree ���� �Ѱܹ��� ������ Photo Name�� ��ġ�ϴ� ���� ã�Ƽ� ���ã�⿡�� �����Ѵ�
	*	@param	item	ã���� �ϴ� Photo Name�� �Էµ� PhotoType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int deleteFavorites(PhotoType& item);

	/**
	*	@brief	��ü �������� ���ã��� ������ Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	Photo Tree�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	���ã�⵵ ������ ������ ã�Ƽ� item���� ��ȯ�ȴ�.
	*/
	void GetOverallFavorites();

	/**
	*	@brief	���Կ����� �����ε�.
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