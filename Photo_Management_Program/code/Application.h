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
	*	@brief ������.
	*/
	Application()
	{
		command = 0;
		m_Album.InitFolder();
		cout << "\t�ֻ��� Album��\n ";
		m_Album.SetRecordFromKB();

		folderStack.InitStack();
		folderStack.Push(&m_Album);
		curFolder = folderStack.Peek();
	}

	/**
	*	@brief	�Ҹ���
	*/
	~Application() {}

	/**
	*	@brief	���α׷� ����̹�.
	*	@pre	���α׷��� ���۵ȴ�.
	*	@post	���α׷��� ������.
	*/
	void Run();


	/*------------------------------------
	*				  Ŀ�ǵ�
	*-------------------------------------
	*/
	/**
	*	@brief	Main Command�� �����ְ� Ű����κ��� input�� �޴´�.
	*	@pre	����.
	*	@post	����.
	*	@return	������� Command.
	*/
	int GetMainCommand();

	/**
	*	@brief	������ �߰��� ���õ� Command�� �����ְ� Ű����κ��� input�� �޴´�.
	*	@pre	����.
	*	@post	����.
	*	@return	������� Command.
	*/
	int GetAddCommand();

	/**
	*	@brief	������ ������ ���õ� Command�� �����ְ� Ű����κ��� input�� �޴´�.
	*	@pre	����.
	*	@post	����.
	*	@return	������� Command.
	*/
	int GetRemoveCommand();

	/**
	*	@brief	�˻��� ���õ� Command�� �����ְ� Ű����κ��� input�� �޴´�.
	*	@pre	����.
	*	@post	����.
	*	@return	������� Command.
	*/
	int GetSearchCommand();

	/**
	*	@brief	���ã��� ���õ� Command�� �����ְ� Ű����κ��� input�� �޴´�.
	*	@pre	����.
	*	@post	����.
	*	@return	������� Command.
	*/
	int GetFavoritesCommand();

	/**
	*	@brief	���� folder�� photo�� �߰�
	*	@pre	none
	*	@post	���� folder�� photo�� �߰���
	*/
	void InsertPhoto();

	/**
	*	@brief	���� folder�� folder�� �߰�
	*	@pre	none
	*	@post	���� folder�� folder�� �߰���
	*/
	void InsertFolder();

	/**
	*	@brief	���� folder���� photo�� ����
	*	@pre	none
	*	@post	���� folder���� photo�� ������
	*/
	void RemovePhoto();

	/**
	*	@brief	���� folder���� folder�� ����
	*	@pre	none
	*	@post	���� folder���� folder�� ������
	*/
	void RemoveFolder();

	/**
	*	@brief	���� ������ ���Ե� ��� �׸���� �����Ѵ�.
	*	@pre	����.
	*	@post	Folder���� ��� �׸���� �����ȴ�.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	void makeEmptyFolder();

	/**
	*	@brief	���� folder�� ��� item�� �����
	*	@pre	none
	*	@post	���� folder�� ��� folder list�� photo tree�� ������ ��µ�
	*/
	void Display();

	/**
	*	@brief	��ü �������� photo�� �ִ��� name���� �˻���
	*	@pre	none
	*	@post	��ü ���� ���� ������ ���� ������ ���� ���, ������ ���ٴ� ���� ���
	*/
	void SearchAllPhotoByName();

	/**
	*	@brief	��ü �������� photo�� �ִ��� �̺�Ʈ������ �˻���
	*	@pre	none
	*	@post	��ü ���� ���� ������ ���� ������ ���� ���, ������ ���ٴ� ���� ���
	*/
	void SearchAllPhotoByEvent();

	/**
	*	@brief	��ü ���� folder���� photo�� �ִ��� ���� �� ���Ե� ������� �˻���
	*	@pre	none
	*	@post	��ü ���� ���� ������ ���� ������ ���� ���, ������ ���ٴ� ���� ���
	*/
	void SearchAllPhotoByPeople();

	/**
	*	@brief	Ű���忡�� �Ⱓ�� �Է¹޾Ƽ� ��ü �������� ������ �������� ���.
	*	@pre	none
	*	@post	��ü ���� ���� ������ ���� ������ ���� ���, ������ ���ٴ� ���� ���
	*/
	void SearchAllPhotoInTimeInterval();

	/**
	*	@brief	���� folder���� photo�� �ִ��� name���� �˻���
	*	@pre	none
	*	@post	���� folder�� ������ ���� ������ ���� ���, ������ ���ٴ� ���� ���
	*/
	void SearchPhotoByName();

	/**
	*	@brief	���� folder���� photo�� �ִ��� �̺�Ʈ������ �˻���
	*	@pre	none
	*	@post	���� folder�� ������ ���� ������ ���� ���, ������ ���ٴ� ���� ���
	*/
	void SearchPhotoByEvent();

	/**
	*	@brief	���� folder���� photo�� �ִ��� ���� �� ���Ե� ������� �˻���
	*	@pre	none
	*	@post	���� folder�� ������ ���� ������ ���� ���, ������ ���ٴ� ���� ���
	*/
	void SearchPhotoByPeople();

	/**
	*	@brief	Ű���忡�� �Ⱓ�� �Է¹޾Ƽ� ������ �������� ���.
	*	@pre	����.
	*	@post	������ ���� ���.
	*/
	void SearchPhotoInTimeInterval();

	/**
	*	@brief	��ü �������� folder�� �ִ��� name���� �˻���
	*	@pre	none
	*	@post	��ü ���� ���� ������ ���� ������ ���� ���, ������ ���ٴ� ���� ���
	*/
	void SearchAllFolderByName();

	/**
	*	@brief	Ű���忡�� �Ⱓ�� �Է¹޾Ƽ� ��ü �������� ������ �������� ���.
	*	@pre	����.
	*	@post	��ü �������� ������ ���� ���.
	*/
	void SearchAllFolderInTimeInterval();

	/**
	*	@brief	���� folder���� folder�� �ִ��� name���� �˻���
	*	@pre	none
	*	@post	���� folder�� ������ ���� ������ ���� ���, ������ ���ٴ� ���� ���
	*/
	void SearchFolderByName();

	/**
	*	@brief	Ű���忡�� �Ⱓ�� �Է¹޾Ƽ� ������ �������� ���.
	*	@pre	����.
	*	@post	������ ���� ���.
	*/
	void SearchFolderInTimeInterval();

	/**
	*	@brief	Folder Stack���� ���� ������ �̵��Ѵ�.
	*	@pre	Folder Stack�� set�Ǿ��־���Ѵ�.
	*	@post	Folder Stack���� ���� ������ ������.
	*/
	void goPrevioueFolder();

	/**
	*	@brief	����ڷκ��� �̵��� ������ �Է¹޾� �̵��Ѵ�.
	*	@pre	Folder Stack�� set�Ǿ��־���Ѵ�.
	*	@post	Folder Stack���� ���� ������ ������.
	*/
	void goNextFolder();

	/**
	*	@brief	input file�μ� file descriptor�� ���� file�� �����Ѵ�.
	*	@pre	���� file�� �����ؾ��Ѵ�.
	*	@post	�б� ���� file�� �����Ѵ�.
	*	@param	fileName	�б� ���� ������ filename.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	output file�μ� file descriptor�� ���� file�� �����Ѵ�.
	*	@pre	list�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	���� ���� file�� �����Ѵ�.
	*	@param	fileName	���� ���� ������ filename.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	read mode�� file�� �����ϰ�, file�� ��� data�� �о� list�� set�Ѵ�.
	*	@pre	file�� ���µǾ����� �ʴ�.
	*	@post	list�� file�κ����� ��� record�� �����Ѵ�.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	write mode�� file�� �����ϰ�, file�� ��� data�� �Է��Ѵ�.
	*	@pre	file�� ���µǾ����� �ʴ�.
	*	@post	output file�� list�� ����ȴ�.
	*	@return ������ 1, ���н� 0�� �����Ѵ�.
	*/
	int WriteDataToFile();
	
	/**
	*	@brief	���ã�⿡ photo�� �߰�
	*	@pre	none
	*	@post	���ã�⿡ photo�� �߰���
	*/
	void AddFavorites();
	
	/**
	*	@brief	���ã�⿡�� photo�� ����
	*	@pre	none
	*	@post	���ã�⿡�� photo�� ������
	*/
	void DeleteFavorites();
	
	/**
	*	@brief	���ã���� ��� item�� �����
	*	@pre	none
	*	@post	���ã���� ��� folder list�� photo tree�� ������ ��µ�
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