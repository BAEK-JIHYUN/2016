#include "Application.h"


// ���α׷� ����̹�.
void Application::Run()
{
	while (1)
	{
		command = GetMainCommand();

		switch (command)
		{
		case 1:		// ���� ������ ���Ե� ��ü �׸� ���		
			Display();
			break;

		case 2:		// ���� ������ ���Ե� ��ü �׸� ����		
			makeEmptyFolder();
			break;

		case 3:		// ������ �߰� Ŀ�ǵ� 
			command = GetAddCommand();
			switch (command) {
			case 1:		// ���� �߰�
				InsertFolder();
				break;
			case 2:		// ���� �߰�
				InsertPhoto();
				break;
			}
			break;

		case 4:		// ������ ���� Ŀ�ǵ�
			command = GetRemoveCommand();
			switch (command) {
			case 1:		// ���� ����
				RemoveFolder();
				break;
			case 2:		// ���� ����
				RemovePhoto();
				break;
			}
			break;

		case 5:		// �˻� Ŀ�ǵ�		
			command = GetSearchCommand();
			switch (command) {
			case 0:			// ���� ���� ���� �˻�
				switch (command2) {
				case 1:			// �̸����� ���� �˻�
					SearchFolderByName();
					break;
				case 2:			// ������ �ð� ���� ���� ���� �˻�
					SearchFolderInTimeInterval();
					break;
				case 3:			// �̸����� ���� �˻�
					SearchPhotoByName();
					break;
				case 4:			// �̺�Ʈ������ ���� �˻�
					SearchPhotoByEvent();
					break;
				case 5:			// ���� �ӿ� ���Ե� ������� ���� �˻�
					SearchPhotoByPeople();
					break;
				case 6:		// ������ �ð� ���� ���� ���� �˻�
					SearchPhotoInTimeInterval();
					break;
				}
				break;
			case 1:			// ��ü ���� �˻�
				switch (command2) {
				case 1:			// ��ü �������� �̸����� ���� �˻�
					SearchAllFolderByName();
					break;
				case 2:			// ��ü �������� ������ �ð� ���� ���� ���� �˻�
					SearchAllFolderInTimeInterval();
					break;
				case 3:			// ��ü �������� �̸����� ���� �˻�
					SearchAllPhotoByName();
					break;
				case 4:			// ��ü �������� �̺�Ʈ������ ���� �˻�
					SearchAllPhotoByEvent();
					break;
				case 5:			// ��ü �������� ���� �ӿ� ���Ե� ������� ���� �˻�
					SearchAllPhotoByPeople();
					break;	
				case 6:			// ��ü �������� ������ �ð� ���� ���� ���� �˻�
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

		case 8:		// ���� ������ �̵�
			goPrevioueFolder();
			break;
		case 9:		// ���� ������ �̵�
			goNextFolder();
			break;
		case 10:	// ���ã�� ���� Ŀ�ǵ�
			command = GetFavoritesCommand();
			switch (command) {
			case 1:				// ������ ���ã�⿡ �߰�
				AddFavorites();
				break;
			case 2:				// ������ ���ã�⿡�� ����
				DeleteFavorites();
				break;
			case 3:				// ���ã�� ����
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


// Command�� �����ְ� Ű����κ��� input�� �޴´�. 
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

// ������ �߰��� ���õ� Command�� �����ְ� Ű����κ��� input�� �޴´�. 
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


// ������ ������ ���õ� Command�� �����ְ� Ű����κ��� input�� �޴´�. 
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


// �˻� ���õ� Command�� �����ְ� Ű����κ��� input�� �޴´�. 
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

	cout << "\t   ��������(0), ��ü����(1): ";
	cin >> command;
	cout << endl << "\t Choose a Command--> ";
	cin >> command2;
	cout << endl;

	return command;
}

// ���ã��� ���õ� Command�� �����ְ� Ű����κ��� input�� �޴´�.
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


// ���� folder�� photo�� �߰��ϴ� �Լ� 
void Application::InsertPhoto()
{
	PhotoType item;
	cout << "\t�߰��� ������\n";
	item.SetRecordFromKB();

	curFolder->addPhoto(item);				// addPhoto�Լ��� ���ؼ� photo�� ���� folder�� �߰�
	Display();								// ���� folder�� ��� �׸���� ���
}

// ���� folder�� folder�� �߰��ϴ� �Լ� 
void Application::InsertFolder()
{
	FolderType item;
	cout << "\t�߰��� ������\n";
	item.SetRecordFromKB();

	curFolder->addFolder(item);				// addFolder�Լ��� ���ؼ� folder�� ���� folder�� �߰�
	Display();								// ���� folder�� ��� �׸���� ���
}

// ���� folder���� photo�� ����� �Լ�
void Application::RemovePhoto()
{
	PhotoType item;
	cout << "\t������ ";
	item.SetNameFromKB();

	if (curFolder->deletePhoto(item)) {					// ������ �����ϸ�
		cout << "\t������ �����Ͽ����ϴ�." << endl;
		Display();										// �����ߴٴ� ������ �Բ�, ������ �����ϰ� ������ ���� ���
	}		
	else
		cout << "\t������ ã�� �� �����ϴ�." << endl;		// ������ �����ϸ� �� ã�Ҵٴ� ���� ��� 
}

// ���� folder���� folder�� ����� �Լ�
void Application::RemoveFolder()
{
	FolderType item;
	cout << "\t������ ";
	item.SetNameFromKB();

	if (curFolder->GetSearchByName(item)) {				// �ش� ������ ���� ���� ���� �����ϸ� ����
		curFolder->deleteFolder(item);
		cout << "\t������ �����Ͽ����ϴ�." << endl;
		Display();										// �����ߴٴ� ������ �Բ�, ������ �����ϰ� ������ ���� ���
	}
	else
		cout << "\t������ ã�� �� �����ϴ�." << endl;		// �׷��������� �� ã�Ҵٴ� ���� ��� 
}

// ���� ������ ���Ե� ��� �׸���� �����Ѵ�.
void Application::makeEmptyFolder() {
	curFolder->MakeEmpty();								// curFolder ����
	cout << "\n\t��ü �����Ǿ����ϴ�." << endl;
}

// ���� folder�� ��� �׸���� ����ϴ� �Լ�
void Application::Display()
{
	cout << "\n\t���� ���� ��ġ: ";
	for (int i = 0; i < folderStack.getNum(); i++) {
		folderStack.PeekN(i)->DisplayFolderName();
		cout<< " ->";
	}

	cout << "\n\t��--------current Folder--------��" << endl;
	curFolder->displayFolderByName();					// displayFolderByName�Լ��� ���ؼ� ���
	cout << "\t��------------------------------��" << endl;
}

// ���� folder���� photo�� �ִ��� name���� �˻��ϴ� �Լ�
void Application::SearchPhotoByName()
{
	PhotoType item;
	cout << "\tã�� ";
	item.SetNameFromKB();

	if (curFolder->GetSearchByName(item)) {					// �˻��� �����ϸ� 
		cout << "\t������ ã�ҽ��ϴ�.\n" << endl;
		item.DisplayRecordOnScreen();					// ã�Ҵٴ� ������ �Բ�, �ش� ������ ���� ���
	}
	else
		cout << "\t������ ã�� �� �����ϴ�." << endl;		// �˻��� �����ϸ� �� ã�Ҵٴ� ���� ��� 
}

// ���� folder���� photo�� �ִ��� �̺�Ʈ������ �˻��ϴ� �Լ�
void Application::SearchPhotoByEvent()
{
	bool found = false;
	PhotoType item;
	cout << "\tã�� ";
	item.SetEventFromKB();
	cout << endl;

	curFolder->GetSearchByEvent(item, found);

	if (found == false)
		cout << "\t������ ã�� �� �����ϴ�." << endl;		// �˻��� �����ϸ� �� ã�Ҵٴ� ���� ��� 
}

// ���� folder���� photo�� �ִ��� ���� �� ���Ե� ������� �˻��ϴ� �Լ�
void Application::SearchPhotoByPeople()
{
	bool found = false;
	PhotoType item;
	cout << "\tã�� ";
	item.SetPeopleFromKB();
	cout << endl;

	curFolder->GetSearchByPeople(item, found);

	if (found == false)
		cout << "\t������ ã�� �� �����ϴ�." << endl;		// �˻��� �����ϸ� �� ã�Ҵٴ� ���� ��� 
}

// Ű���忡�� �Ⱓ�� �Է¹޾Ƽ� ������ �������� ����ϴ� �Լ�
void Application::SearchPhotoInTimeInterval() 
{
	PhotoType item1;
	PhotoType item2;
	bool found = false;

	string time1, time2;
	cout << "\t�˻��� ������ ������ �ּ��� .\n";						// �˻��� ���� �Է�
	item1.SetDateFromKB();
	cout << "\t  ~  \n";
	item2.SetDateFromKB();
	cout << endl;

	curFolder->DisplayPhotoInTimeInterval(item1, item2, found);		// DisplayPhotoInTimeInterval�Լ��� ȣ�� 

	if (found == false)												// �˻��� �����ϸ� �� ã�Ҵٴ� ���� ��� 
		cout << "\t������ ã�� �� �����ϴ�." << endl;

}

// ��ü �������� photo�� �ִ��� name���� �˻��ϴ� �Լ�
void Application::SearchAllPhotoByName()
{
	bool found = false;
	PhotoType item;
	cout << "\tã�� ";
	item.SetNameFromKB();

	cout << endl;
	m_Album.GetOverallSearchByName(item, found);		// �˻��� �����ϸ� �ٷιٷ� �ش� ���� ���

	if (found == false)									// �˻��� �����ϸ� �� ã�Ҵٴ� ���� ��� 
		cout << "\t������ ã�� �� �����ϴ�." << endl;
}

// ��ü �������� photo�� �ִ��� �̺�Ʈ������ �˻���
void Application::SearchAllPhotoByEvent() {
	bool found = false;
	PhotoType item;
	cout << "\tã�� ";
	item.SetEventFromKB();

	cout << endl;
	m_Album.GetOverallSearchByEvent(item, found);		// �˻��� �����ϸ� �ٷιٷ� �ش� ���� ���

	if (found == false)									// �˻��� �����ϸ� �� ã�Ҵٴ� ���� ��� 
		cout << "\t������ ã�� �� �����ϴ�." << endl;
}

// ��ü ���� folder���� photo�� �ִ��� ���� �� ���Ե� ������� �˻���
void Application::SearchAllPhotoByPeople() {
	bool found = false;
	PhotoType item;
	cout << "\tã�� ";
	item.SetPeopleFromKB();

	cout << endl;
	m_Album.GetOverallSearchByPeople(item, found);		// �˻��� �����ϸ� �ٷιٷ� �ش� ���� ���

	if (found == false)									// �˻��� �����ϸ� �� ã�Ҵٴ� ���� ��� 
		cout << "\t������ ã�� �� �����ϴ�." << endl;
}

//Ű���忡�� �Ⱓ�� �Է¹޾Ƽ� ��ü �������� ������ �������� ���.
void Application::SearchAllPhotoInTimeInterval() {
	PhotoType item1;
	PhotoType item2;
	bool found = false;

	string time1, time2;
	cout << "\t�˻��� ������ ������ �ּ��� .\n";								// �˻��� ���� �Է�
	item1.SetDateFromKB();
	cout << "\t  ~  \n";
	item2.SetDateFromKB();
	cout << endl;

	m_Album.DisplayOverallPhotoInTimeInterval(item1, item2, found);			// DisplayOverallPhotoInTimeInterval�Լ��� ȣ�� 

	if (found == false)														// �˻��� �����ϸ� �� ã�Ҵٴ� ���� ��� 
		cout << "\t������ ã�� �� �����ϴ�." << endl;
}

// ���� folder���� folder�� �ִ��� name���� �˻��ϴ� �Լ�
void Application::SearchFolderByName()
{
	FolderType item;
	cout << "\tã�� ";
	item.SetNameFromKB();

	if (curFolder->GetSearchByName(item)) {				// �˻��� �����ϸ� 
		cout << "\t������ ã�ҽ��ϴ�.\n" << endl;
		item.DisplayRecordOnScreen();					// ã�Ҵٴ� ������ �Բ�, �ش� ������ ���� ���
	}
	else
		cout << "\t������ ã�� �� �����ϴ�." << endl;		// �˻��� �����ϸ� �� ã�Ҵٴ� ���� ��� 
}

// Ű���忡�� �Ⱓ�� �Է¹޾Ƽ� ������ �������� ����ϴ� �Լ�
void Application::SearchFolderInTimeInterval()
{
	FolderType item1;
	FolderType item2;
	bool found = false;

	string time1, time2;
	cout << "\t�˻��� ������ ������ �ּ��� .\n";							// �˻��� ���� �Է�
	item1.SetDateFromKB();
	cout << "\t  ~  \n";
	item2.SetDateFromKB();
	cout << endl;

	curFolder->DisplayFolderInTimeInterval(item1, item2, found);		// DisplayFolderInTimeInterval�Լ��� ȣ�� 

	if (found == false)													// �˻��� �����ϸ� �� ã�Ҵٴ� ���� ��� 
		cout << "\t������ ã�� �� �����ϴ�." << endl;

}

// ��ü �������� folder�� �ִ��� name���� �˻��ϴ� �Լ�
void Application::SearchAllFolderByName()
{
	bool found = false;
	FolderType item;
	cout << "\tã�� ";
	item.SetNameFromKB();

	cout << endl;
	m_Album.GetOverallSearchByName(item,found);		// �˻��� �����ϸ� �ٷιٷ� �ش� ���� ���

	if (found == false)									// �˻��� �����ϸ� �� ã�Ҵٴ� ���� ��� 
		cout << "\t������ ã�� �� �����ϴ�." << endl;
}

//Ű���忡�� �Ⱓ�� �Է¹޾Ƽ� ��ü �������� ������ �������� ���.
void Application::SearchAllFolderInTimeInterval() {
	FolderType item1;
	FolderType item2;
	bool found = false;

	string time1, time2;
	cout << "\t�˻��� ������ ������ �ּ��� .\n";							// �˻��� ���� �Է�
	item1.SetDateFromKB();
	cout << "\t  ~  \n";
	item2.SetDateFromKB();
	cout << endl;

	m_Album.DisplayOverallFolderInTimeInterval(item1, item2, found);	// DisplayOverallFolderInTimeInterval�Լ��� ȣ�� 

	if (found == false)													// �˻��� �����ϸ� �� ã�Ҵٴ� ���� ��� 
		cout << "\t������ ã�� �� �����ϴ�." << endl;
}

// Folder Stack���� ���� ������ �̵��Ѵ�.
void Application::goPrevioueFolder() {
	if (folderStack.getNum() <= 1) {
		cout << "\tó�� �����Դϴ�." << endl;				// ó�� ������ ��� �̵� �Ұ��� 
		return;
	}
	folderStack.Pop();									// �ƴ϶�� ���� ���ÿ��� �ϳ� ���� ���� curFolder�� ����
	curFolder = folderStack.Peek();
	Display();
}

// ����ڷκ��� �̵��� ������ �Է¹޾� �̵��Ѵ�.
void Application::goNextFolder() {
	FolderType item;
	cout << "\t�̵��� ";
	item.SetNameFromKB();									// �̵��� ���� �̸��� �Է¹���
	
	FolderType* tmp = curFolder->GetAddressByName(item);	// �̸��� ��ġ�ϴ� ������ �ּҰ� ����

	if (tmp != NULL) {										// ������ ã���� �ش� ������ �̵��� �� ��� 
		curFolder = tmp;
		folderStack.Push(curFolder);
		Display();
	}
	else
		cout << "\n\t������ ã�� ���߽��ϴ�." << endl;
}


// input file�μ� file descriptor�� ���� file�� �����Ѵ�.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}


// output file�μ� file descriptor�� ���� file�� �����Ѵ�.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// read mode�� file�� �����ϰ�, file�� ��� data�� �о� list�� set�Ѵ�.
int Application::ReadDataFromFile()
{
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
		return 0;

	curFolder->ReadAllDataFromFile(m_InFile);

	// ���� list ���
	Display();

	return 1;
}


// write mode�� file�� �����ϰ�, file�� ��� data�� �Է��Ѵ�.
int Application::WriteDataToFile()
{
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename)) 
		return 0;

	m_Album.WriteAllDataToFile(m_OutFile);

	return 1;
}

// ���ã�⿡ photo�� �߰�
void Application::AddFavorites() {
	PhotoType item;
	cout << "\t���ã�⿡ �߰���\n ";
	item.SetNameFromKB();

	if (curFolder->setFavorites(item)) {
		cout << "\n\t���ã�⿡ �߰��Ǿ����ϴ�." << endl;
	}
	else
		cout << "\n\t�����Ͽ����ϴ�." << endl;
}

// ���ã�⿡�� photo�� ����
void Application::DeleteFavorites() {
	PhotoType item;
	cout << "\t���ã�⿡�� ������\n";
	item.SetNameFromKB();

	if (curFolder->deleteFavorites(item))
		cout << "\n\t���ã�⿡�� �����Ǿ����ϴ�." << endl;
	else {
		cout << "\n\t�����Ͽ����ϴ�." << endl;
	}
}

// ���ã���� ��� item�� �����
void Application::DisplayFavorites() {
	cout << "\n\t��----------Favorites-----------��" << endl;
	
	m_Album.GetOverallFavorites();

	cout << "\n\t��------------------------------��" << endl;
}