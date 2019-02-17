#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "FolderType.h"
#include "Stack.h"
#include <iostream>
using namespace std;

#define FILENAMESIZE 1024


/**
*	@brief	Application class for item management simply.
*/
class Application
{
public:
	/**
	*	@brief 생성자.
	*/
	Application()
	{
		command = 0;
		m_Album.InitFolder();
		cout << "\t최상위 Album의\n ";
		m_Album.SetRecordFromKB();

		folderStack.InitStack();
		folderStack.Push(&m_Album);
		curFolder = folderStack.Peek();
	}

	/**
	*	@brief	소멸자
	*/
	~Application() {}

	/**
	*	@brief	프로그램 드라이버.
	*	@pre	프로그램이 시작된다.
	*	@post	프로그램이 끝난다.
	*/
	void Run();


	/*------------------------------------
	*				  커맨드
	*-------------------------------------
	*/
	/**
	*	@brief	Main Command를 보여주고 키보드로부터 input을 받는다.
	*	@pre	없음.
	*	@post	없음.
	*	@return	사용자의 Command.
	*/
	int GetMainCommand();

	/**
	*	@brief	데이터 추가와 관련된 Command를 보여주고 키보드로부터 input을 받는다.
	*	@pre	없음.
	*	@post	없음.
	*	@return	사용자의 Command.
	*/
	int GetAddCommand();

	/**
	*	@brief	데이터 삭제와 관련된 Command를 보여주고 키보드로부터 input을 받는다.
	*	@pre	없음.
	*	@post	없음.
	*	@return	사용자의 Command.
	*/
	int GetRemoveCommand();

	/**
	*	@brief	검색과 관련된 Command를 보여주고 키보드로부터 input을 받는다.
	*	@pre	없음.
	*	@post	없음.
	*	@return	사용자의 Command.
	*/
	int GetSearchCommand();

	/**
	*	@brief	즐겨찾기와 관련된 Command를 보여주고 키보드로부터 input을 받는다.
	*	@pre	없음.
	*	@post	없음.
	*	@return	사용자의 Command.
	*/
	int GetFavoritesCommand();

	/**
	*	@brief	현재 folder에 photo를 추가
	*	@pre	none
	*	@post	현재 folder에 photo가 추가됨
	*/
	void InsertPhoto();

	/**
	*	@brief	현재 folder에 folder를 추가
	*	@pre	none
	*	@post	현재 folder에 folder가 추가됨
	*/
	void InsertFolder();

	/**
	*	@brief	현재 folder에서 photo를 지움
	*	@pre	none
	*	@post	현재 folder에서 photo가 지워짐
	*/
	void RemovePhoto();

	/**
	*	@brief	현재 folder에서 folder를 지움
	*	@pre	none
	*	@post	현재 folder에서 folder가 지워짐
	*/
	void RemoveFolder();

	/**
	*	@brief	현재 폴더에 포함된 모든 항목들을 삭제한다.
	*	@pre	없음.
	*	@post	Folder내의 모든 항목들이 삭제된다.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	void makeEmptyFolder();

	/**
	*	@brief	현재 folder의 모든 item을 출력함
	*	@pre	none
	*	@post	현재 folder의 모든 folder list와 photo tree의 노드들이 출력됨
	*/
	void Display();

	/**
	*	@brief	전체 범위에서 photo가 있는지 name으로 검색함
	*	@pre	none
	*	@post	전체 범위 내에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	void SearchAllPhotoByName();

	/**
	*	@brief	전체 범위에서 photo가 있는지 이벤트명으로 검색함
	*	@pre	none
	*	@post	전체 범위 내에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	void SearchAllPhotoByEvent();

	/**
	*	@brief	전체 범위 folder에서 photo가 있는지 사진 속 포함된 사람으로 검색함
	*	@pre	none
	*	@post	전체 범위 내에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	void SearchAllPhotoByPeople();

	/**
	*	@brief	키보드에서 기간을 입력받아서 전체 범위에서 구간내 사진들을 출력.
	*	@pre	none
	*	@post	전체 범위 내에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	void SearchAllPhotoInTimeInterval();

	/**
	*	@brief	현재 folder에서 photo가 있는지 name으로 검색함
	*	@pre	none
	*	@post	현재 folder에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	void SearchPhotoByName();

	/**
	*	@brief	현재 folder에서 photo가 있는지 이벤트명으로 검색함
	*	@pre	none
	*	@post	현재 folder에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	void SearchPhotoByEvent();

	/**
	*	@brief	현재 folder에서 photo가 있는지 사진 속 포함된 사람으로 검색함
	*	@pre	none
	*	@post	현재 folder에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	void SearchPhotoByPeople();

	/**
	*	@brief	키보드에서 기간을 입력받아서 구간내 사진들을 출력.
	*	@pre	없음.
	*	@post	구간내 사진 출력.
	*/
	void SearchPhotoInTimeInterval();

	/**
	*	@brief	전체 범위에서 folder가 있는지 name으로 검색함
	*	@pre	none
	*	@post	전체 범위 내에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	void SearchAllFolderByName();

	/**
	*	@brief	키보드에서 기간을 입력받아서 전체 범위에서 구간내 폴더들을 출력.
	*	@pre	없음.
	*	@post	전체 범위에서 구간내 폴더 출력.
	*/
	void SearchAllFolderInTimeInterval();

	/**
	*	@brief	현재 folder에서 folder가 있는지 name으로 검색함
	*	@pre	none
	*	@post	현재 folder에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	void SearchFolderByName();

	/**
	*	@brief	키보드에서 기간을 입력받아서 구간내 폴더들을 출력.
	*	@pre	없음.
	*	@post	구간내 폴더 출력.
	*/
	void SearchFolderInTimeInterval();

	/**
	*	@brief	Folder Stack에서 이전 폴더로 이동한다.
	*	@pre	Folder Stack이 set되어있어야한다.
	*	@post	Folder Stack에서 이전 폴더로 가진다.
	*/
	void goPrevioueFolder();

	/**
	*	@brief	사용자로부터 이동할 폴더를 입력받아 이동한다.
	*	@pre	Folder Stack이 set되어있어야한다.
	*	@post	Folder Stack에서 다음 폴더로 가진다.
	*/
	void goNextFolder();

	/**
	*	@brief	input file로서 file descriptor에 의해 file을 오픈한다.
	*	@pre	읽을 file이 존재해야한다.
	*	@post	읽기 위해 file을 오픈한다.
	*	@param	fileName	읽기 위해 오픈할 filename.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	output file로서 file descriptor에 의해 file을 오픈한다.
	*	@pre	list가 initialized 되어 있어야 한다.
	*	@post	쓰기 위해 file을 오픈한다.
	*	@param	fileName	쓰기 위해 오픈할 filename.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	read mode로 file을 오픈하고, file의 모든 data를 읽어 list를 set한다.
	*	@pre	file이 오픈되어있지 않다.
	*	@post	list는 file로부터의 모든 record를 보유한다.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	write mode로 file을 오픈하고, file에 모든 data를 입력한다.
	*	@pre	file이 오픈되어있지 않다.
	*	@post	output file에 list가 저장된다.
	*	@return 성공시 1, 실패시 0을 리턴한다.
	*/
	int WriteDataToFile();
	
	/**
	*	@brief	즐겨찾기에 photo를 추가
	*	@pre	none
	*	@post	즐겨찾기에 photo가 추가됨
	*/
	void AddFavorites();
	
	/**
	*	@brief	즐겨찾기에서 photo를 지움
	*	@pre	none
	*	@post	즐겨찾기에서 photo가 지워짐
	*/
	void DeleteFavorites();
	
	/**
	*	@brief	즐겨찾기의 모든 item을 출력함
	*	@pre	none
	*	@post	즐겨찾기의 모든 folder list와 photo tree의 노드들이 출력됨
	*/
	void DisplayFavorites();


private:
	ifstream m_InFile;							///< input file descriptor.
	ofstream m_OutFile;							///< output file descriptor.
	FolderType m_Album;							///< Album.
	StackType<FolderType*> folderStack;			///< folder Stack 
	FolderType* curFolder;						///< currend Folder
	int command;								///< current command number
	int command2;								///< current command number2

};
#endif