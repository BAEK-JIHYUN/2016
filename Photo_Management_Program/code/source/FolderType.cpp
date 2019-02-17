#include "FolderType.h"

// Ű����κ��� Folder Name�� �Է¹޾� set�Ѵ�.
void FolderType::SetNameFromKB() {
	cout << "\tFolder Name: ";
	cin >> m_Name;
}

// Ű����κ��� Folder Date�� �Է¹޾� set�Ѵ�.
void FolderType::SetDateFromKB() {
	cout << "\tFolder Date: ";
	cin >> m_Date;
}

// Ű����κ��� Folder record�� �Է¹޾� set�Ѵ�.
void FolderType::SetRecordFromKB() {
	SetNameFromKB();
	SetDateFromKB();
}

// file�κ��� record�� �о�´�.
int  FolderType::ReadDataFromFile(ifstream& fin) {
	fin >> m_Name;
	fin >> m_Date;

	return 1;
}

//read mode�� file�� �����ϰ�, file�� ��� data�� �о� list�� set�Ѵ�.
void  FolderType::ReadAllDataFromFile(ifstream& fin) {
	FolderType fItem;	// �б�� �ӽ� ����
	PhotoType pItem;
	string read;

	FolderType* cur = this;						// ���� ������ ����Ű�� cur 
	FolderType* above = NULL;					// ���� ������ ����Ű�� above


	// ������ ��� ������ �о� list�� �߰�
	while (!fin.eof())
	{
		fin >> read;

		if (read == "-----------------------------") {
			cur = above;								// ���� ������ �̵�
		}

		else if (read == "Folder") {
			FolderType* newFold = new FolderType();
			newFold->ReadDataFromFile(fin);				// �� ������ �����Ͽ� �����͸� �о���� �� ���� ������ ����
			cur->addFolder(*newFold);

			above = cur;								// above�� cur ����
			cur = newFold;								// cur�� ���� ������ ������ �̵���Ŵ (���� ������ �̵�) 
		}

		else if (read == "Photo") {
			PhotoType* newPho = new PhotoType();
			newPho->ReadDataFromFile(fin);	// ���� ������ ���� ���� 
			cur->addPhoto(*newPho);
		}
	}
	fin.close();	// file close
}

// file�� record�� �Է��Ѵ�.
int  FolderType::WriteDataToFile(ofstream& fout) {
	fout << endl;
	fout << "Folder" << endl;
	fout << m_Name << " ";
	fout << m_Date;

	return 1;
}

// write mode�� file�� �����ϰ�, file�� ��� data�� �Է��Ѵ�.
void FolderType::WriteAllDataToFile(ofstream& fout)
{
	FolderType fItem;	// ����� �ӽ� ����
	FolderType fItem2;
	PhotoType pItem;


	// ���� ������ ���Ͽ� �Է�
	m_pTree.WriteTree(fout);

	// ���� ������ ���Ͽ� �Է�
	if (m_fList.LFirst(&fItem)) {							// ù ��° ������ ù ��° ���� �� ������ ���Ͽ� �Է�
		fItem.WriteDataToFile(fout);
		fItem.m_pTree.WriteTree(fout);

		if (fItem.m_fList.LFirst(&fItem2)) {				// ù ��° ���� �� ��������Ʈ���� �ݺ�  
			fItem2.WriteDataToFile(fout);
			fItem2.WriteAllDataToFile(fout);
			
			while (fItem.m_fList.LNext(&fItem2)) {
				fItem2.WriteDataToFile(fout);
				fItem2.WriteAllDataToFile(fout);
			}
		}
		fout << endl<< "-----------------------------" << endl;	// ���� �Է� �� ���������� �̵��ؾ��ϴ� ���� ����

		// list�� ��� �����͸� ���Ͽ� ����
		while (m_fList.LNext(&fItem))		
		{	
			fItem.WriteDataToFile(fout);					// �� ������ �ش� ���� �� ������ ���Ͽ� �Է�	
			fItem.m_pTree.WriteTree(fout);			

			if (fItem.m_fList.LFirst(&fItem2)) {			// �� ���� �� ��������Ʈ���� �ݺ� 
				fItem2.WriteDataToFile(fout);
				fItem2.WriteAllDataToFile(fout);

				while (fItem.m_fList.LNext(&fItem2)) {
					fItem2.WriteDataToFile(fout);
					fItem2.WriteAllDataToFile(fout);
				}
			}
			fout << endl<<"-----------------------------" << endl;
		}
	}

}

// Folder Time�� �������� �� ���� FolderTyp�� ���Ѵ�.
RelationType FolderType::CompareByDate(const FolderType item) {
	if (m_Date <= item.m_Date)
		return LESSorEQUAL;
	else if (m_Date >= item.m_Date)
		return GREATERorEQUAL;
}

// ���ο� ������ ���� ������ �߰��Ѵ�.
int FolderType::addFolder(FolderType item) {
	if (m_fList.Add(item)) {
		m_Num++;
		return 1;
	}
	else
		return 0;
}

// ������ �����Ѵ�.
void FolderType::deleteFolder(FolderType item) {
	FolderType folder;

	item.m_pTree.MakeEmpty();		// ���� �ӿ� ���Ե� ���� ���� ����

	if (item.m_fList.LFirst(&folder)) {			// ������ ���� �ӿ� ������ �����ϸ�
		folder.deleteFolder(folder);				// �Լ� �ڱ� �ڽ� ȣ��
		while (item.m_fList.LNext(&folder)) {	// ������ ���� �� ��������Ʈ�� ���� ������ ������ �ݺ�
			folder.deleteFolder(folder);
		}
	}

	this->m_fList.Delete(item);			// ���� �� ����, ������ ���� ������ �� delete
	m_Num--;
	
}

// ���ο� ���������� ���� ������ �߰��Ѵ�.
int  FolderType::addPhoto(PhotoType item) {
	bool found;							// �˻����ο� ���� ����� ������ found
	m_pTree.RetrieveItem(item, found);	// RetrieveItem �Լ��� ���ؼ� Tree���� �˻�

	if (found == false) {				// ���� �˻����������� (�ߺ��Ǵ� �����Ͱ� �ƴϸ�) �߰�
		m_pTree.Add(item);
		m_Num++;
		return 1;
	}
	else {
		cout << "\t�ߺ��Ǵ� �������Դϴ�." << endl;		// �׷��������� ���� ���� �ʰ� �Լ��� ��������
		return 0;
	}
}

// ������ �����Ѵ�.
int  FolderType::deletePhoto(PhotoType item) {
	if (m_pTree.GetLength() <= 0)		// ���Ե� �׸��� ������ 0 ����
		return 0;

	bool found;							// �˻����ο� ���� ����� ������ found
	m_pTree.RetrieveItem(item, found);	// RetrieveItem �Լ��� ���ؼ� Tree���� �˻�

	if (found == true)					// Tree�� item�� ������
	{
		m_pTree.DeleteItem(item);		// DeleteItem�Լ��� ���ؼ� Tree���� item���� �ش��ϴ� ��带 ������
		m_Num--;
		return 1;						// ������ �������� ���
	}
	else
		return 0;						// ������� �ϴ� ���� node�� ���� ���
}

// ������ �� �� ���·� �����.
void FolderType::MakeEmpty() {
	FolderType folder;

	this->m_pTree.MakeEmpty();

	if (m_fList.LFirst(&folder)) {			
		folder.deleteFolder(folder);				// ��������Ʈ�� ù ��° ���� �� ��� ����,���� ����
		while (m_fList.LNext(&folder)) {	
			folder.deleteFolder(folder);			// ��������Ʈ�� ���� ������ ������ �ݺ�
		}
	}
	this->m_fList.MakeEmptyList();
	m_Num = 0;
	
}

// ���� ������ �̸��� ���Ե� �׸� ��, ������ �׸��� �������� �̸������� ȭ�鿡 ����Ѵ�.
void FolderType::displayFolderByName() {

	DisplayNameOnScreen(); //���� �̸��� ȭ�鿡 ���
	DisplayNumOnScreen(); //������ ���Ե� �׸� ���� ȭ�鿡 ���

	FolderType fItem;
	PhotoType pItem;

	// ���� Folder���� ���Ե� ��� ������ ȭ�鿡 ���
	if (!m_fList.IsEmptyList()) {
		cout << "\n\t------------���� ���------------" << endl;
		m_fList.LFirst(&fItem);
		fItem.DisplayNameOnScreen();
		fItem.DisplayDateOnScreen();
		cout << endl;
		while (m_fList.LNext(&fItem))
		{
			fItem.DisplayNameOnScreen();
			fItem.DisplayDateOnScreen();
			cout << endl;
		}
	}

	// ���� Folder���� ���Ե� ��� ������ ȭ�鿡 ���
	if (!m_pTree.IsEmpty()) {
		cout << "\n\t------------���� ���------------" << endl;
		m_pTree.PrintTree(cout);
		cout << endl;
	}
}

// Folder Name�� ��ġ�ϴ� list�� ������ ã�Ƽ� ��ȯ�Ѵ�.
int FolderType::GetSearchByName(FolderType& item) {
	if (m_fList.Get(item)) 
		return 1;								// �˻��� �������� ���
	else
		return 0;								// �˻��� ������ ���
}

// Folder Name�� ��ġ�ϴ� list�� ������ ã�´�.
FolderType* FolderType::GetAddressByName(FolderType item) {
	return m_fList.GetAddress(item);
}

// �Է��� ���� ���� ���ԵǴ� list�� ������ ã�Ƽ� ����Ѵ�.
void FolderType:: DisplayFolderInTimeInterval(FolderType& item1, FolderType& item2, bool& found) {
	FolderType fItem;

	if (m_fList.LFirst(&fItem)) {
		if (fItem.CompareByDate(item1) == GREATERorEQUAL && fItem.CompareByDate(item2) == LESSorEQUAL) {
			fItem.DisplayRecordOnScreen();
			found = true;
			cout << endl;
		}

		while (m_fList.LNext(&fItem)) {
			if (fItem.CompareByDate(item1) == GREATERorEQUAL && fItem.CompareByDate(item2) == LESSorEQUAL) {
				fItem.DisplayRecordOnScreen();
				found = true;
				cout << endl;
			}
		}
	}
}

// ��ü �������� Folder Name�� ��ġ�ϴ� list�� ������ ã�Ƽ� ��ȯ�Ѵ�.
void FolderType::GetOverallSearchByName(FolderType& item, bool& found) {
	FolderType fItem;

	if (this->m_fList.Get(item)) {
		cout << "\t��ġ: " << this->m_Name << endl;		// ���� ������ �����ϸ� ������ ��ġ ���
		item.DisplayRecordOnScreen();					// �������� ���
		found = true;
		cout << endl;
	}

	if (m_fList.LFirst(&fItem)) {						// ��������Ʈ ��ü�� Ž���ϸ� �ݺ� 
		fItem.GetOverallSearchByName(item,found);

		while (m_fList.LNext(&fItem)) {
			fItem.GetOverallSearchByName(item,found);
		}
	}
}


// ��ü �������� �Է��� ���� ���� ���ԵǴ� list�� ������ ã�Ƽ� ����Ѵ�.
void FolderType::DisplayOverallFolderInTimeInterval(FolderType& item1, FolderType& item2, bool& found) {
	FolderType fItem;

	if (this->m_fList.LFirst(&fItem)) {			// ���� ������ �����ϴ� ���� �� ������ ��ġ�� ���� ���
		if (fItem.CompareByDate(item1) == GREATERorEQUAL && fItem.CompareByDate(item2) == LESSorEQUAL) {
			cout << "\t��ġ: " << this->m_Name << endl;		
			fItem.DisplayRecordOnScreen();
			found = true;
			cout << endl;
		}

		while (this->m_fList.LNext(&fItem)) {
			if (fItem.CompareByDate(item1) == GREATERorEQUAL && fItem.CompareByDate(item2) == LESSorEQUAL) {
				cout << "\t��ġ: " << this->m_Name << endl;		
				fItem.DisplayRecordOnScreen();
				found = true;
				cout << endl;
			}
		}
	}

	if (m_fList.LFirst(&fItem)) {						// ��������Ʈ ��ü�� Ž���ϸ� �ݺ� 
		fItem.DisplayOverallFolderInTimeInterval(item1, item2, found);

		while (m_fList.LNext(&fItem)) {
			fItem.DisplayOverallFolderInTimeInterval(item1, item2, found);
		}
	}

}

// Photo Name�� ��ġ�ϴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
int FolderType::GetSearchByName(PhotoType& item) {
	bool found;									// �˻����θ� ������ found
	m_pTree.RetrieveItem(item, found);			// RetrieveItem �Լ��� ���� Tree���� �˻�
	if (found == true)						
		return 1;								// �˻��� �������� ���
	else 
		return 0;								// �˻��� ������ ���
}

//Photo Event Name�� ��ġ�ϴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
void FolderType::GetSearchByEvent(PhotoType& item, bool& found) {

	for (int i = 0; i < m_pTree.GetLength(); i++) {
		if (m_pTree.CallItem(i)->data.GetEvent() == item.GetEvent()) {
			m_pTree.CallItem(i)->data.DisplayRecordOnScreen();
			cout << endl;
			found = true;
		}
	}

}

// �Էµ� ����� �����ϴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
void FolderType::GetSearchByPeople(PhotoType& item, bool& found) {

	for (int i = 0; i < m_pTree.GetLength(); i++) {									// ���� Tree�� ��� ���� �˻�
		for (int j = 0; j < m_pTree.CallItem(i)->data.GetArrLength(); j++)			// ���� Tree�� �� ���� �� people �迭�� ���� ����
				if (m_pTree.CallItem(i)->data.GetArrN(j) == item.GetPeople()) {		
					m_pTree.CallItem(i)->data.DisplayRecordOnScreen();				// ������ ã���� ������ ���� ���
					cout << endl;
					found = true;
				}
			}
}

// �Է��� ���� ���� ���ԵǴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
void FolderType::DisplayPhotoInTimeInterval(PhotoType& item1, PhotoType& item2, bool& found) {

	for (int i = 0; i < m_pTree.GetLength(); i++) {
		if (((m_pTree.CallItem(i)->data).ComparedByDate(item1)==GREATERorEQUAL) && ((m_pTree.CallItem(i)->data).ComparedByDate(item2) == LESSorEQUAL)) {
			m_pTree.CallItem(i)->data.DisplayRecordOnScreen();
			cout << endl;
			found = true;
		}
	}
}


// ��ü �������� Photo Name�� ��ġ�ϴ� list�� ������ ã�Ƽ� ��ȯ�Ѵ�.
void FolderType::GetOverallSearchByName(PhotoType& item, bool& found) {
	FolderType fItem;

	this->m_pTree.RetrieveItem(item, found);			// RetrieveItem �Լ��� ���� Tree���� �˻�

	if (found == true) {
		cout << "\t��ġ: " << this->m_Name << endl;		// ���� ������ �����ϸ� ������ ��ġ ���
		item.DisplayRecordOnScreen();					// �������� ���
		cout << endl;
	}

	if (m_fList.LFirst(&fItem)) {						// ��������Ʈ ��ü�� Ž���ϸ� �ݺ� 
		fItem.GetOverallSearchByName(item, found);

		while (m_fList.LNext(&fItem)) {
			fItem.GetOverallSearchByName(item, found);
		}
	}
}

// ��ü �������� Photo Event Name�� ��ġ�ϴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
void FolderType::GetOverallSearchByEvent(PhotoType& item, bool& found){
	FolderType fItem;

	for (int i = 0; i < this-> m_pTree.GetLength(); i++) {						// ���� ������ �����ϸ� ���� ��ġ�� �������� ���
		if (this->m_pTree.CallItem(i)->data.GetEvent() == item.GetEvent()) {
			cout << "\t��ġ: " << this->m_Name << endl;
			this->m_pTree.CallItem(i)->data.DisplayRecordOnScreen();
			cout << endl;
			found = true;
		}
	}

	if (m_fList.LFirst(&fItem)) {						// ��������Ʈ ��ü�� Ž���ϸ� �ݺ� 
		fItem.GetOverallSearchByEvent(item, found);

		while (m_fList.LNext(&fItem)) {
			fItem.GetOverallSearchByEvent(item, found);
		}
	}
}

// ��ü �������� �Էµ� ����� �����ϴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
void FolderType::GetOverallSearchByPeople(PhotoType& item, bool& found){
	FolderType fItem;

	for (int i = 0; i < this->m_pTree.GetLength(); i++) {						// ���� ������ �����ϸ� ���� ��ġ�� �������� ���
		for (int j = 0; j < this->m_pTree.CallItem(i)->data.GetArrLength(); j++) {
			if (this->m_pTree.CallItem(i)->data.GetArrN(j) == item.GetPeople()) {
				cout << "\t��ġ: " << this->m_Name << endl;
				m_pTree.CallItem(i)->data.DisplayRecordOnScreen();
				cout << endl;
				found = true;
			}
		}
	}

	if (m_fList.LFirst(&fItem)) {							// ��������Ʈ ��ü�� Ž���ϸ� �ݺ� 
		fItem.GetOverallSearchByPeople(item, found);

		while (m_fList.LNext(&fItem)) {
			fItem.GetOverallSearchByPeople(item, found);
		}
	}
}

// ��ü �������� �Է��� ���� ���� ���ԵǴ� Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
void FolderType::DisplayOverallPhotoInTimeInterval(PhotoType& item1, PhotoType& item2, bool& found) {
	FolderType fItem;

	for (int i = 0; i < m_pTree.GetLength(); i++) {				// ���� ������ �����ϸ� ���� ��ġ�� �������� ���
		if (this->m_pTree.CallItem(i)->data.ComparedByDate(item1) == GREATERorEQUAL && this->m_pTree.CallItem(i)->data.ComparedByDate(item2) == LESSorEQUAL) {
			cout << "\t��ġ: " << this->m_Name << endl;
			m_pTree.CallItem(i)->data.DisplayRecordOnScreen();
			cout << endl;
			found = true;
		}
	}

	if (m_fList.LFirst(&fItem)) {							// ��������Ʈ ��ü�� Ž���ϸ� �ݺ� 
		fItem.DisplayOverallPhotoInTimeInterval(item1, item2, found);

		while (m_fList.LNext(&fItem)) {
			fItem.DisplayOverallPhotoInTimeInterval(item1, item2, found);
		}
	}

}

//Photo Name�� ��ġ�ϴ� Tree�� ������ ã�Ƽ� ���ã��� �����Ѵ�
int FolderType::setFavorites(PhotoType& item) {
	bool found;									// �˻����θ� ������ found
	m_pTree.RetrieveItem(item, found);			// RetrieveItem �Լ��� ���� Tree���� �˻�

	PhotoType temp = item;

	if ((found == true) && (item.GetFavorites() == 0)) {				// ������ ã��, ���ã�Ⱑ �ƴ� ��� ���ã��� �߰�
		temp.setF();								// temp�� ���ã��� ������ �� item�� �����ϰ� temp�� �������
		deletePhoto(item);
		addPhoto(temp);
		return 1;
	}

	return 0;
}

// Photo Name�� ��ġ�ϴ� Tree�� ������ ã�Ƽ� ���ã�⿡�� �����Ѵ�
int FolderType::deleteFavorites(PhotoType& item) {
	bool found;									// �˻����θ� ������ found
	m_pTree.RetrieveItem(item, found);			// RetrieveItem �Լ��� ���� Tree���� �˻�

	PhotoType temp = item;

	if ((found == true) &&(item.GetFavorites() == 1)) {			// ������ ã��, ���ã��� �����Ǿ��ִ� ��� ���ã�⿡�� ����
		temp.deleteF();						// temp�� �⺻���� ������ �� item�� �����ϰ� temp�� �������
		deletePhoto(item);
		addPhoto(temp);
		return 1;
	}

	return 0;
}

// ��ü �������� ���ã��� ������ Tree�� ������ ã�Ƽ� ��ȯ�Ѵ�.
void FolderType::GetOverallFavorites() {
	FolderType fItem;

	for (int i = 0; i < m_pTree.GetLength(); i++) {
		if ((m_pTree.CallItem(i)->data.GetFavorites()) == 1) {
			cout << "\t��ġ: " << this->m_Name << endl;
			m_pTree.CallItem(i)->data.DisplayRecordOnScreen();
			cout << endl;
		}
	}

	if (m_fList.LFirst(&fItem)) {						// ��������Ʈ ��ü�� Ž���ϸ� �ݺ� 
		fItem.GetOverallFavorites();

		while (m_fList.LNext(&fItem)) {
			fItem.GetOverallFavorites();
		}
	}
}

// ���Կ����� �����ε�
FolderType FolderType::operator =(FolderType& folder) {
	m_Name = folder.m_Name;
	m_Date = folder.m_Date;
	m_Num = folder.m_Num;
	m_fList = folder.m_fList;
	m_pTree = folder.m_pTree;

	return *this;
}