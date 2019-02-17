#include "Application.h"


// 프로그램 드라이버.
void Application::Run()
{
	while (1)
	{
		command = GetMainCommand();

		switch (command)
		{
		case 1:		// 현재 폴더에 포함된 전체 항목 출력		
			Display();
			break;

		case 2:		// 현재 폴더에 포함된 전체 항목 삭제		
			makeEmptyFolder();
			break;

		case 3:		// 데이터 추가 커맨드 
			command = GetAddCommand();
			switch (command) {
			case 1:		// 폴더 추가
				InsertFolder();
				break;
			case 2:		// 사진 추가
				InsertPhoto();
				break;
			}
			break;

		case 4:		// 데이터 삭제 커맨드
			command = GetRemoveCommand();
			switch (command) {
			case 1:		// 폴더 삭제
				RemoveFolder();
				break;
			case 2:		// 사진 삭제
				RemovePhoto();
				break;
			}
			break;

		case 5:		// 검색 커맨드		
			command = GetSearchCommand();
			switch (command) {
			case 0:			// 현재 폴더 내의 검색
				switch (command2) {
				case 1:			// 이름으로 폴더 검색
					SearchFolderByName();
					break;
				case 2:			// 임의의 시간 범위 내의 폴더 검색
					SearchFolderInTimeInterval();
					break;
				case 3:			// 이름으로 사진 검색
					SearchPhotoByName();
					break;
				case 4:			// 이벤트명으로 사진 검색
					SearchPhotoByEvent();
					break;
				case 5:			// 사진 속에 포함된 사람으로 사진 검색
					SearchPhotoByPeople();
					break;
				case 6:		// 임의의 시간 범위 내의 사진 검색
					SearchPhotoInTimeInterval();
					break;
				}
				break;
			case 1:			// 전체 범위 검색
				switch (command2) {
				case 1:			// 전체 범위에서 이름으로 폴더 검색
					SearchAllFolderByName();
					break;
				case 2:			// 전체 범위에서 임의의 시간 범위 내의 폴더 검색
					SearchAllFolderInTimeInterval();
					break;
				case 3:			// 전체 범위에서 이름으로 사진 검색
					SearchAllPhotoByName();
					break;
				case 4:			// 전체 범위에서 이벤트명으로 사진 검색
					SearchAllPhotoByEvent();
					break;
				case 5:			// 전체 범위에서 사진 속에 포함된 사람으로 사진 검색
					SearchAllPhotoByPeople();
					break;	
				case 6:			// 전체 범위에서 임의의 시간 범위 내의 사진 검색
					SearchAllPhotoInTimeInterval();
					break;
				}
				break;
			}
			break;

		case 6:		// load list data from a file.
			ReadDataFromFile();
			break;

		case 7:		// save list data into a file.
			WriteDataToFile();
			break;

		case 8:		// 이전 폴더로 이동
			goPrevioueFolder();
			break;
		case 9:		// 다음 폴더로 이동
			goNextFolder();
			break;
		case 10:	// 즐겨찾기 관리 커맨드
			command = GetFavoritesCommand();
			switch (command) {
			case 1:				// 사진을 즐겨찾기에 추가
				AddFavorites();
				break;
			case 2:				// 사진을 즐겨찾기에서 삭제
				DeleteFavorites();
				break;
			case 3:				// 즐겨찾기 보기
				DisplayFavorites();
				break;
			}
			break;
		case 0:
			return;
			break;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// Command를 보여주고 키보드로부터 input을 받는다. 
int Application::GetMainCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Display" << endl;
	cout << "\t   2 : Make empty" << endl;
	cout << "\t   3 : Add" << endl;
	cout << "\t   4 : Remove" << endl;
	cout << "\t   5 : Search" << endl;
	cout << "\t   6 : Get from file" << endl;
	cout << "\t   7 : Put to file" << endl;
	cout << "\t   8 : Back" << endl;
	cout << "\t   9 : Next" << endl;
	cout << "\t   10: Favorites" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// 데이터 추가와 관련된 Command를 보여주고 키보드로부터 input을 받는다. 
int Application::GetAddCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Folder" << endl;
	cout << "\t   2 : Add Photo" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// 데이터 삭제와 관련된 Command를 보여주고 키보드로부터 input을 받는다. 
int Application::GetRemoveCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Delete Folder" << endl;
	cout << "\t   2 : Delete Photo" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// 검색 관련된 Command를 보여주고 키보드로부터 input을 받는다. 
int Application::GetSearchCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Search Folder By Name " << endl;
	cout << "\t   2 : Search Folder In Time Interval" << endl;
	cout << "\t   3 : Search Photo By Name" << endl;
	cout << "\t   4 : Search Photo By Event" << endl;
	cout << "\t   5 : Search Photo By People" << endl;
	cout << "\t   6 : Search Photo In Time Interval" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << "\t   현재폴더(0), 전체폴더(1): ";
	cin >> command;
	cout << endl << "\t Choose a Command--> ";
	cin >> command2;
	cout << endl;

	return command;
}

// 즐겨찾기와 관련된 Command를 보여주고 키보드로부터 input을 받는다.
int Application::GetFavoritesCommand() {
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Favorites" << endl;
	cout << "\t   2 : Delete Favorites" << endl;
	cout << "\t   3 : Display" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// 현재 folder에 photo를 추가하는 함수 
void Application::InsertPhoto()
{
	PhotoType item;
	cout << "\t추가할 사진의\n";
	item.SetRecordFromKB();

	curFolder->addPhoto(item);				// addPhoto함수를 통해서 photo를 현재 folder에 추가
	Display();								// 현재 folder의 모든 항목들을 출력
}

// 현재 folder에 folder를 추가하는 함수 
void Application::InsertFolder()
{
	FolderType item;
	cout << "\t추가할 폴더의\n";
	item.SetRecordFromKB();

	curFolder->addFolder(item);				// addFolder함수를 통해서 folder를 현재 folder에 추가
	Display();								// 현재 folder의 모든 항목들을 출력
}

// 현재 folder에서 photo를 지우는 함수
void Application::RemovePhoto()
{
	PhotoType item;
	cout << "\t삭제할 ";
	item.SetNameFromKB();

	if (curFolder->deletePhoto(item)) {					// 삭제에 성공하면
		cout << "\t사진을 삭제하였습니다." << endl;
		Display();										// 삭제했다는 문구와 함께, 사진을 삭제하고 나서의 내용 출력
	}		
	else
		cout << "\t사진을 찾을 수 없습니다." << endl;		// 삭제에 실패하면 못 찾았다는 문구 출력 
}

// 현재 folder에서 folder를 지우는 함수
void Application::RemoveFolder()
{
	FolderType item;
	cout << "\t삭제할 ";
	item.SetNameFromKB();

	if (curFolder->GetSearchByName(item)) {				// 해당 폴더가 현재 폴더 내에 존재하면 삭제
		curFolder->deleteFolder(item);
		cout << "\t폴더를 삭제하였습니다." << endl;
		Display();										// 삭제했다는 문구와 함께, 폴더를 삭제하고 나서의 내용 출력
	}
	else
		cout << "\t폴더를 찾을 수 없습니다." << endl;		// 그렇지않으면 못 찾았다는 문구 출력 
}

// 현재 폴더에 포함된 모든 항목들을 삭제한다.
void Application::makeEmptyFolder() {
	curFolder->MakeEmpty();								// curFolder 삭제
	cout << "\n\t전체 삭제되었습니다." << endl;
}

// 현재 folder의 모든 항목들을 출력하는 함수
void Application::Display()
{
	cout << "\n\t현재 폴더 위치: ";
	for (int i = 0; i < folderStack.getNum(); i++) {
		folderStack.PeekN(i)->DisplayFolderName();
		cout<< " ->";
	}

	cout << "\n\t┌--------current Folder--------┐" << endl;
	curFolder->displayFolderByName();					// displayFolderByName함수를 통해서 출력
	cout << "\t└------------------------------┘" << endl;
}

// 현재 folder에서 photo가 있는지 name으로 검색하는 함수
void Application::SearchPhotoByName()
{
	PhotoType item;
	cout << "\t찾을 ";
	item.SetNameFromKB();

	if (curFolder->GetSearchByName(item)) {					// 검색에 성공하면 
		cout << "\t사진을 찾았습니다.\n" << endl;
		item.DisplayRecordOnScreen();					// 찾았다는 문구와 함께, 해당 사진의 정보 출력
	}
	else
		cout << "\t사진을 찾을 수 없습니다." << endl;		// 검색에 실패하면 못 찾았다는 문구 출력 
}

// 현재 folder에서 photo가 있는지 이벤트명으로 검색하는 함수
void Application::SearchPhotoByEvent()
{
	bool found = false;
	PhotoType item;
	cout << "\t찾을 ";
	item.SetEventFromKB();
	cout << endl;

	curFolder->GetSearchByEvent(item, found);

	if (found == false)
		cout << "\t사진을 찾을 수 없습니다." << endl;		// 검색에 실패하면 못 찾았다는 문구 출력 
}

// 현재 folder에서 photo가 있는지 사진 속 포함된 사람으로 검색하는 함수
void Application::SearchPhotoByPeople()
{
	bool found = false;
	PhotoType item;
	cout << "\t찾을 ";
	item.SetPeopleFromKB();
	cout << endl;

	curFolder->GetSearchByPeople(item, found);

	if (found == false)
		cout << "\t사진을 찾을 수 없습니다." << endl;		// 검색에 실패하면 못 찾았다는 문구 출력 
}

// 키보드에서 기간을 입력받아서 구간내 사진들을 출력하는 함수
void Application::SearchPhotoInTimeInterval() 
{
	PhotoType item1;
	PhotoType item2;
	bool found = false;

	string time1, time2;
	cout << "\t검색할 구간을 선택해 주세요 .\n";						// 검색할 구간 입력
	item1.SetDateFromKB();
	cout << "\t  ~  \n";
	item2.SetDateFromKB();
	cout << endl;

	curFolder->DisplayPhotoInTimeInterval(item1, item2, found);		// DisplayPhotoInTimeInterval함수를 호출 

	if (found == false)												// 검색에 실패하면 못 찾았다는 문구 출력 
		cout << "\t사진을 찾을 수 없습니다." << endl;

}

// 전체 범위에서 photo가 있는지 name으로 검색하는 함수
void Application::SearchAllPhotoByName()
{
	bool found = false;
	PhotoType item;
	cout << "\t찾을 ";
	item.SetNameFromKB();

	cout << endl;
	m_Album.GetOverallSearchByName(item, found);		// 검색에 성공하면 바로바로 해당 사진 출력

	if (found == false)									// 검색에 실패하면 못 찾았다는 문구 출력 
		cout << "\t사진을 찾을 수 없습니다." << endl;
}

// 전체 범위에서 photo가 있는지 이벤트명으로 검색함
void Application::SearchAllPhotoByEvent() {
	bool found = false;
	PhotoType item;
	cout << "\t찾을 ";
	item.SetEventFromKB();

	cout << endl;
	m_Album.GetOverallSearchByEvent(item, found);		// 검색에 성공하면 바로바로 해당 사진 출력

	if (found == false)									// 검색에 실패하면 못 찾았다는 문구 출력 
		cout << "\t사진을 찾을 수 없습니다." << endl;
}

// 전체 범위 folder에서 photo가 있는지 사진 속 포함된 사람으로 검색함
void Application::SearchAllPhotoByPeople() {
	bool found = false;
	PhotoType item;
	cout << "\t찾을 ";
	item.SetPeopleFromKB();

	cout << endl;
	m_Album.GetOverallSearchByPeople(item, found);		// 검색에 성공하면 바로바로 해당 사진 출력

	if (found == false)									// 검색에 실패하면 못 찾았다는 문구 출력 
		cout << "\t사진을 찾을 수 없습니다." << endl;
}

//키보드에서 기간을 입력받아서 전체 범위에서 구간내 사진들을 출력.
void Application::SearchAllPhotoInTimeInterval() {
	PhotoType item1;
	PhotoType item2;
	bool found = false;

	string time1, time2;
	cout << "\t검색할 구간을 선택해 주세요 .\n";								// 검색할 구간 입력
	item1.SetDateFromKB();
	cout << "\t  ~  \n";
	item2.SetDateFromKB();
	cout << endl;

	m_Album.DisplayOverallPhotoInTimeInterval(item1, item2, found);			// DisplayOverallPhotoInTimeInterval함수를 호출 

	if (found == false)														// 검색에 실패하면 못 찾았다는 문구 출력 
		cout << "\t사진을 찾을 수 없습니다." << endl;
}

// 현재 folder에서 folder가 있는지 name으로 검색하는 함수
void Application::SearchFolderByName()
{
	FolderType item;
	cout << "\t찾을 ";
	item.SetNameFromKB();

	if (curFolder->GetSearchByName(item)) {				// 검색에 성공하면 
		cout << "\t폴더를 찾았습니다.\n" << endl;
		item.DisplayRecordOnScreen();					// 찾았다는 문구와 함께, 해당 폴더의 정보 출력
	}
	else
		cout << "\t폴더를 찾을 수 없습니다." << endl;		// 검색에 실패하면 못 찾았다는 문구 출력 
}

// 키보드에서 기간을 입력받아서 구간내 폴더들을 출력하는 함수
void Application::SearchFolderInTimeInterval()
{
	FolderType item1;
	FolderType item2;
	bool found = false;

	string time1, time2;
	cout << "\t검색할 구간을 선택해 주세요 .\n";							// 검색할 구간 입력
	item1.SetDateFromKB();
	cout << "\t  ~  \n";
	item2.SetDateFromKB();
	cout << endl;

	curFolder->DisplayFolderInTimeInterval(item1, item2, found);		// DisplayFolderInTimeInterval함수를 호출 

	if (found == false)													// 검색에 실패하면 못 찾았다는 문구 출력 
		cout << "\t폴더를 찾을 수 없습니다." << endl;

}

// 전체 범위에서 folder가 있는지 name으로 검색하는 함수
void Application::SearchAllFolderByName()
{
	bool found = false;
	FolderType item;
	cout << "\t찾을 ";
	item.SetNameFromKB();

	cout << endl;
	m_Album.GetOverallSearchByName(item,found);		// 검색에 성공하면 바로바로 해당 폴더 출력

	if (found == false)									// 검색에 실패하면 못 찾았다는 문구 출력 
		cout << "\t폴더를 찾을 수 없습니다." << endl;
}

//키보드에서 기간을 입력받아서 전체 범위에서 구간내 폴더들을 출력.
void Application::SearchAllFolderInTimeInterval() {
	FolderType item1;
	FolderType item2;
	bool found = false;

	string time1, time2;
	cout << "\t검색할 구간을 선택해 주세요 .\n";							// 검색할 구간 입력
	item1.SetDateFromKB();
	cout << "\t  ~  \n";
	item2.SetDateFromKB();
	cout << endl;

	m_Album.DisplayOverallFolderInTimeInterval(item1, item2, found);	// DisplayOverallFolderInTimeInterval함수를 호출 

	if (found == false)													// 검색에 실패하면 못 찾았다는 문구 출력 
		cout << "\t폴더를 찾을 수 없습니다." << endl;
}

// Folder Stack에서 이전 폴더로 이동한다.
void Application::goPrevioueFolder() {
	if (folderStack.getNum() <= 1) {
		cout << "\t처음 폴더입니다." << endl;				// 처음 폴더일 경우 이동 불가능 
		return;
	}
	folderStack.Pop();									// 아니라면 폴더 스택에서 하나 꺼낸 다음 curFolder에 저장
	curFolder = folderStack.Peek();
	Display();
}

// 사용자로부터 이동할 폴더를 입력받아 이동한다.
void Application::goNextFolder() {
	FolderType item;
	cout << "\t이동할 ";
	item.SetNameFromKB();									// 이동할 폴더 이름을 입력받음
	
	FolderType* tmp = curFolder->GetAddressByName(item);	// 이름과 일치하는 폴더의 주소값 저장

	if (tmp != NULL) {										// 폴더를 찾으면 해당 폴더로 이동한 뒤 출력 
		curFolder = tmp;
		folderStack.Push(curFolder);
		Display();
	}
	else
		cout << "\n\t폴더를 찾지 못했습니다." << endl;
}


// input file로서 file descriptor에 의해 file을 오픈한다.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// output file로서 file descriptor에 의해 file을 오픈한다.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// read mode로 file을 오픈하고, file의 모든 data를 읽어 list를 set한다.
int Application::ReadDataFromFile()
{
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
		return 0;

	curFolder->ReadAllDataFromFile(m_InFile);

	// 현재 list 출력
	Display();

	return 1;
}


// write mode로 file을 오픈하고, file에 모든 data를 입력한다.
int Application::WriteDataToFile()
{
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename)) 
		return 0;

	m_Album.WriteAllDataToFile(m_OutFile);

	return 1;
}

// 즐겨찾기에 photo를 추가
void Application::AddFavorites() {
	PhotoType item;
	cout << "\t즐겨찾기에 추가할\n ";
	item.SetNameFromKB();

	if (curFolder->setFavorites(item)) {
		cout << "\n\t즐겨찾기에 추가되었습니다." << endl;
	}
	else
		cout << "\n\t실패하였습니다." << endl;
}

// 즐겨찾기에서 photo를 지움
void Application::DeleteFavorites() {
	PhotoType item;
	cout << "\t즐겨찾기에서 삭제할\n";
	item.SetNameFromKB();

	if (curFolder->deleteFavorites(item))
		cout << "\n\t즐겨찾기에서 삭제되었습니다." << endl;
	else {
		cout << "\n\t실패하였습니다." << endl;
	}
}

// 즐겨찾기의 모든 item을 출력함
void Application::DisplayFavorites() {
	cout << "\n\t┌----------Favorites-----------┐" << endl;
	
	m_Album.GetOverallFavorites();

	cout << "\n\t└------------------------------┘" << endl;
}