#include "FolderType.h"

// 키보드로부터 Folder Name을 입력받아 set한다.
void FolderType::SetNameFromKB() {
	cout << "\tFolder Name: ";
	cin >> m_Name;
}

// 키보드로부터 Folder Date을 입력받아 set한다.
void FolderType::SetDateFromKB() {
	cout << "\tFolder Date: ";
	cin >> m_Date;
}

// 키보드로부터 Folder record를 입력받아 set한다.
void FolderType::SetRecordFromKB() {
	SetNameFromKB();
	SetDateFromKB();
}

// file로부터 record를 읽어온다.
int  FolderType::ReadDataFromFile(ifstream& fin) {
	fin >> m_Name;
	fin >> m_Date;

	return 1;
}

//read mode로 file을 오픈하고, file의 모든 data를 읽어 list를 set한다.
void  FolderType::ReadAllDataFromFile(ifstream& fin) {
	FolderType fItem;	// 읽기용 임시 변수
	PhotoType pItem;
	string read;

	FolderType* cur = this;						// 현재 폴더를 가리키는 cur 
	FolderType* above = NULL;					// 상위 폴더를 가리키는 above


	// 파일의 모든 내용을 읽어 list에 추가
	while (!fin.eof())
	{
		fin >> read;

		if (read == "-----------------------------") {
			cur = above;								// 상위 폴더로 이동
		}

		else if (read == "Folder") {
			FolderType* newFold = new FolderType();
			newFold->ReadDataFromFile(fin);				// 새 폴더를 생성하여 데이터를 읽어들인 뒤 현재 폴더에 저장
			cur->addFolder(*newFold);

			above = cur;								// above에 cur 저장
			cur = newFold;								// cur을 새로 생성한 폴더로 이동시킴 (하위 폴더로 이동) 
		}

		else if (read == "Photo") {
			PhotoType* newPho = new PhotoType();
			newPho->ReadDataFromFile(fin);	// 현재 폴더에 사진 저장 
			cur->addPhoto(*newPho);
		}
	}
	fin.close();	// file close
}

// file에 record를 입력한다.
int  FolderType::WriteDataToFile(ofstream& fout) {
	fout << endl;
	fout << "Folder" << endl;
	fout << m_Name << " ";
	fout << m_Date;

	return 1;
}

// write mode로 file을 오픈하고, file에 모든 data를 입력한다.
void FolderType::WriteAllDataToFile(ofstream& fout)
{
	FolderType fItem;	// 쓰기용 임시 변수
	FolderType fItem2;
	PhotoType pItem;


	// 사진 정보를 파일에 입력
	m_pTree.WriteTree(fout);

	// 폴더 정보를 파일에 입력
	if (m_fList.LFirst(&fItem)) {							// 첫 번째 폴더와 첫 번째 폴더 속 사진을 파일에 입력
		fItem.WriteDataToFile(fout);
		fItem.m_pTree.WriteTree(fout);

		if (fItem.m_fList.LFirst(&fItem2)) {				// 첫 번째 폴더 속 폴더리스트에서 반복  
			fItem2.WriteDataToFile(fout);
			fItem2.WriteAllDataToFile(fout);
			
			while (fItem.m_fList.LNext(&fItem2)) {
				fItem2.WriteDataToFile(fout);
				fItem2.WriteAllDataToFile(fout);
			}
		}
		fout << endl<< "-----------------------------" << endl;	// 파일 입력 시 상위폴더로 이동해야하는 지점 구분

		// list의 모든 데이터를 파일에 쓰기
		while (m_fList.LNext(&fItem))		
		{	
			fItem.WriteDataToFile(fout);					// 각 폴더와 해당 폴더 속 사진을 파일에 입력	
			fItem.m_pTree.WriteTree(fout);			

			if (fItem.m_fList.LFirst(&fItem2)) {			// 각 폴더 속 폴더리스트에서 반복 
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

// Folder Time을 기준으로 두 개의 FolderTyp을 비교한다.
RelationType FolderType::CompareByDate(const FolderType item) {
	if (m_Date <= item.m_Date)
		return LESSorEQUAL;
	else if (m_Date >= item.m_Date)
		return GREATERorEQUAL;
}

// 새로운 폴더를 현재 폴더에 추가한다.
int FolderType::addFolder(FolderType item) {
	if (m_fList.Add(item)) {
		m_Num++;
		return 1;
	}
	else
		return 0;
}

// 폴더를 삭제한다.
void FolderType::deleteFolder(FolderType item) {
	FolderType folder;

	item.m_pTree.MakeEmpty();		// 폴더 속에 포함된 사진 전부 삭제

	if (item.m_fList.LFirst(&folder)) {			// 삭제할 폴더 속에 폴더가 존재하면
		folder.deleteFolder(folder);				// 함수 자기 자신 호출
		while (item.m_fList.LNext(&folder)) {	// 삭제할 폴더 속 폴더리스트의 끝에 도달할 때까지 반복
			folder.deleteFolder(folder);
		}
	}

	this->m_fList.Delete(item);			// 폴더 속 폴더, 사진을 전부 삭제한 뒤 delete
	m_Num--;
	
}

// 새로운 사진파일을 현재 폴더에 추가한다.
int  FolderType::addPhoto(PhotoType item) {
	bool found;							// 검색여부에 따른 결과를 저장할 found
	m_pTree.RetrieveItem(item, found);	// RetrieveItem 함수를 통해서 Tree에서 검색

	if (found == false) {				// 값이 검색되지않으면 (중복되는 데이터가 아니면) 추가
		m_pTree.Add(item);
		m_Num++;
		return 1;
	}
	else {
		cout << "\t중복되는 데이터입니다." << endl;		// 그렇지않으면 값을 넣지 않고 함수를 빠져나옴
		return 0;
	}
}

// 사진을 삭제한다.
int  FolderType::deletePhoto(PhotoType item) {
	if (m_pTree.GetLength() <= 0)		// 포함된 항목이 없으면 0 리턴
		return 0;

	bool found;							// 검색여부에 따른 결과를 저장할 found
	m_pTree.RetrieveItem(item, found);	// RetrieveItem 함수를 통해서 Tree에서 검색

	if (found == true)					// Tree에 item이 있으면
	{
		m_pTree.DeleteItem(item);		// DeleteItem함수를 통해서 Tree에서 item값에 해당하는 노드를 삭제함
		m_Num--;
		return 1;						// 삭제에 성공했을 경우
	}
	else
		return 0;						// 지우려고 하는 값의 node가 없을 경우
}

// 폴더를 텅 빈 상태로 만든다.
void FolderType::MakeEmpty() {
	FolderType folder;

	this->m_pTree.MakeEmpty();

	if (m_fList.LFirst(&folder)) {			
		folder.deleteFolder(folder);				// 폴더리스트의 첫 번째 폴더 속 모든 사진,폴더 삭제
		while (m_fList.LNext(&folder)) {	
			folder.deleteFolder(folder);			// 폴더리스트의 끝에 도달할 때까지 반복
		}
	}
	this->m_fList.MakeEmptyList();
	m_Num = 0;
	
}

// 현재 폴더의 이름과 포함된 항목 수, 폴더들 그리고 사진들을 이름순으로 화면에 출력한다.
void FolderType::displayFolderByName() {

	DisplayNameOnScreen(); //폴더 이름을 화면에 출력
	DisplayNumOnScreen(); //폴더에 포함된 항목 수를 화면에 출력

	FolderType fItem;
	PhotoType pItem;

	// 현재 Folder내에 포함된 모든 폴더를 화면에 출력
	if (!m_fList.IsEmptyList()) {
		cout << "\n\t------------폴더 목록------------" << endl;
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

	// 현재 Folder내에 포함된 모든 사진들 화면에 출력
	if (!m_pTree.IsEmpty()) {
		cout << "\n\t------------사진 목록------------" << endl;
		m_pTree.PrintTree(cout);
		cout << endl;
	}
}

// Folder Name이 일치하는 list내 폴더를 찾아서 반환한다.
int FolderType::GetSearchByName(FolderType& item) {
	if (m_fList.Get(item)) 
		return 1;								// 검색에 성공했을 경우
	else
		return 0;								// 검색에 실패할 경우
}

// Folder Name이 일치하는 list내 폴더를 찾는다.
FolderType* FolderType::GetAddressByName(FolderType item) {
	return m_fList.GetAddress(item);
}

// 입력한 구간 내에 포함되는 list내 폴더를 찾아서 출력한다.
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

// 전체 범위에서 Folder Name이 일치하는 list내 폴더를 찾아서 반환한다.
void FolderType::GetOverallSearchByName(FolderType& item, bool& found) {
	FolderType fItem;

	if (this->m_fList.Get(item)) {
		cout << "\t위치: " << this->m_Name << endl;		// 현재 폴더에 존재하면 폴더의 위치 출력
		item.DisplayRecordOnScreen();					// 폴더정보 출력
		found = true;
		cout << endl;
	}

	if (m_fList.LFirst(&fItem)) {						// 폴더리스트 전체를 탐색하며 반복 
		fItem.GetOverallSearchByName(item,found);

		while (m_fList.LNext(&fItem)) {
			fItem.GetOverallSearchByName(item,found);
		}
	}
}


// 전체 범위에서 입력한 구간 내에 포함되는 list내 폴더를 찾아서 출력한다.
void FolderType::DisplayOverallFolderInTimeInterval(FolderType& item1, FolderType& item2, bool& found) {
	FolderType fItem;

	if (this->m_fList.LFirst(&fItem)) {			// 현재 폴더에 존재하는 구간 내 폴더의 위치와 정보 출력
		if (fItem.CompareByDate(item1) == GREATERorEQUAL && fItem.CompareByDate(item2) == LESSorEQUAL) {
			cout << "\t위치: " << this->m_Name << endl;		
			fItem.DisplayRecordOnScreen();
			found = true;
			cout << endl;
		}

		while (this->m_fList.LNext(&fItem)) {
			if (fItem.CompareByDate(item1) == GREATERorEQUAL && fItem.CompareByDate(item2) == LESSorEQUAL) {
				cout << "\t위치: " << this->m_Name << endl;		
				fItem.DisplayRecordOnScreen();
				found = true;
				cout << endl;
			}
		}
	}

	if (m_fList.LFirst(&fItem)) {						// 폴더리스트 전체를 탐색하며 반복 
		fItem.DisplayOverallFolderInTimeInterval(item1, item2, found);

		while (m_fList.LNext(&fItem)) {
			fItem.DisplayOverallFolderInTimeInterval(item1, item2, found);
		}
	}

}

// Photo Name이 일치하는 Tree내 사진을 찾아서 반환한다.
int FolderType::GetSearchByName(PhotoType& item) {
	bool found;									// 검색여부를 저장할 found
	m_pTree.RetrieveItem(item, found);			// RetrieveItem 함수를 통해 Tree에서 검색
	if (found == true)						
		return 1;								// 검색에 성공했을 경우
	else 
		return 0;								// 검색에 실패할 경우
}

//Photo Event Name이 일치하는 Tree내 사진을 찾아서 반환한다.
void FolderType::GetSearchByEvent(PhotoType& item, bool& found) {

	for (int i = 0; i < m_pTree.GetLength(); i++) {
		if (m_pTree.CallItem(i)->data.GetEvent() == item.GetEvent()) {
			m_pTree.CallItem(i)->data.DisplayRecordOnScreen();
			cout << endl;
			found = true;
		}
	}

}

// 입력된 사람을 포함하는 Tree내 사진을 찾아서 반환한다.
void FolderType::GetSearchByPeople(PhotoType& item, bool& found) {

	for (int i = 0; i < m_pTree.GetLength(); i++) {									// 사진 Tree의 모든 사진 검색
		for (int j = 0; j < m_pTree.CallItem(i)->data.GetArrLength(); j++)			// 사진 Tree의 각 사진 속 people 배열의 원소 접근
				if (m_pTree.CallItem(i)->data.GetArrN(j) == item.GetPeople()) {		
					m_pTree.CallItem(i)->data.DisplayRecordOnScreen();				// 사진을 찾으면 사진의 정보 출력
					cout << endl;
					found = true;
				}
			}
}

// 입력한 구간 내에 포함되는 Tree내 사진을 찾아서 반환한다.
void FolderType::DisplayPhotoInTimeInterval(PhotoType& item1, PhotoType& item2, bool& found) {

	for (int i = 0; i < m_pTree.GetLength(); i++) {
		if (((m_pTree.CallItem(i)->data).ComparedByDate(item1)==GREATERorEQUAL) && ((m_pTree.CallItem(i)->data).ComparedByDate(item2) == LESSorEQUAL)) {
			m_pTree.CallItem(i)->data.DisplayRecordOnScreen();
			cout << endl;
			found = true;
		}
	}
}


// 전체 범위에서 Photo Name이 일치하는 list내 사진을 찾아서 반환한다.
void FolderType::GetOverallSearchByName(PhotoType& item, bool& found) {
	FolderType fItem;

	this->m_pTree.RetrieveItem(item, found);			// RetrieveItem 함수를 통해 Tree에서 검색

	if (found == true) {
		cout << "\t위치: " << this->m_Name << endl;		// 현재 폴더에 존재하면 사진의 위치 출력
		item.DisplayRecordOnScreen();					// 사진정보 출력
		cout << endl;
	}

	if (m_fList.LFirst(&fItem)) {						// 폴더리스트 전체를 탐색하며 반복 
		fItem.GetOverallSearchByName(item, found);

		while (m_fList.LNext(&fItem)) {
			fItem.GetOverallSearchByName(item, found);
		}
	}
}

// 전체 범위에서 Photo Event Name이 일치하는 Tree내 사진을 찾아서 반환한다.
void FolderType::GetOverallSearchByEvent(PhotoType& item, bool& found){
	FolderType fItem;

	for (int i = 0; i < this-> m_pTree.GetLength(); i++) {						// 현재 폴더에 존재하면 폴더 위치와 사진정보 출력
		if (this->m_pTree.CallItem(i)->data.GetEvent() == item.GetEvent()) {
			cout << "\t위치: " << this->m_Name << endl;
			this->m_pTree.CallItem(i)->data.DisplayRecordOnScreen();
			cout << endl;
			found = true;
		}
	}

	if (m_fList.LFirst(&fItem)) {						// 폴더리스트 전체를 탐색하며 반복 
		fItem.GetOverallSearchByEvent(item, found);

		while (m_fList.LNext(&fItem)) {
			fItem.GetOverallSearchByEvent(item, found);
		}
	}
}

// 전체 범위에서 입력된 사람을 포함하는 Tree내 사진을 찾아서 반환한다.
void FolderType::GetOverallSearchByPeople(PhotoType& item, bool& found){
	FolderType fItem;

	for (int i = 0; i < this->m_pTree.GetLength(); i++) {						// 현재 폴더에 존재하면 폴더 위치와 사진정보 출력
		for (int j = 0; j < this->m_pTree.CallItem(i)->data.GetArrLength(); j++) {
			if (this->m_pTree.CallItem(i)->data.GetArrN(j) == item.GetPeople()) {
				cout << "\t위치: " << this->m_Name << endl;
				m_pTree.CallItem(i)->data.DisplayRecordOnScreen();
				cout << endl;
				found = true;
			}
		}
	}

	if (m_fList.LFirst(&fItem)) {							// 폴더리스트 전체를 탐색하며 반복 
		fItem.GetOverallSearchByPeople(item, found);

		while (m_fList.LNext(&fItem)) {
			fItem.GetOverallSearchByPeople(item, found);
		}
	}
}

// 전체 범위에서 입력한 구간 내에 포함되는 Tree내 사진을 찾아서 반환한다.
void FolderType::DisplayOverallPhotoInTimeInterval(PhotoType& item1, PhotoType& item2, bool& found) {
	FolderType fItem;

	for (int i = 0; i < m_pTree.GetLength(); i++) {				// 현재 폴더에 존재하면 폴더 위치와 사진정보 출력
		if (this->m_pTree.CallItem(i)->data.ComparedByDate(item1) == GREATERorEQUAL && this->m_pTree.CallItem(i)->data.ComparedByDate(item2) == LESSorEQUAL) {
			cout << "\t위치: " << this->m_Name << endl;
			m_pTree.CallItem(i)->data.DisplayRecordOnScreen();
			cout << endl;
			found = true;
		}
	}

	if (m_fList.LFirst(&fItem)) {							// 폴더리스트 전체를 탐색하며 반복 
		fItem.DisplayOverallPhotoInTimeInterval(item1, item2, found);

		while (m_fList.LNext(&fItem)) {
			fItem.DisplayOverallPhotoInTimeInterval(item1, item2, found);
		}
	}

}

//Photo Name이 일치하는 Tree내 사진을 찾아서 즐겨찾기로 지정한다
int FolderType::setFavorites(PhotoType& item) {
	bool found;									// 검색여부를 저장할 found
	m_pTree.RetrieveItem(item, found);			// RetrieveItem 함수를 통해 Tree에서 검색

	PhotoType temp = item;

	if ((found == true) && (item.GetFavorites() == 0)) {				// 사진을 찾고, 즐겨찾기가 아닐 경우 즐겨찾기로 추가
		temp.setF();								// temp를 즐겨찾기로 변경한 뒤 item을 삭제하고 temp를 집어넣음
		deletePhoto(item);
		addPhoto(temp);
		return 1;
	}

	return 0;
}

// Photo Name이 일치하는 Tree내 사진을 찾아서 즐겨찾기에서 삭제한다
int FolderType::deleteFavorites(PhotoType& item) {
	bool found;									// 검색여부를 저장할 found
	m_pTree.RetrieveItem(item, found);			// RetrieveItem 함수를 통해 Tree에서 검색

	PhotoType temp = item;

	if ((found == true) &&(item.GetFavorites() == 1)) {			// 사진을 찾고, 즐겨찾기로 지정되어있는 경우 즐겨찾기에서 삭제
		temp.deleteF();						// temp를 기본으로 변경한 뒤 item을 삭제하고 temp를 집어넣음
		deletePhoto(item);
		addPhoto(temp);
		return 1;
	}

	return 0;
}

// 전체 범위에서 즐겨찾기로 지정된 Tree내 사진을 찾아서 반환한다.
void FolderType::GetOverallFavorites() {
	FolderType fItem;

	for (int i = 0; i < m_pTree.GetLength(); i++) {
		if ((m_pTree.CallItem(i)->data.GetFavorites()) == 1) {
			cout << "\t위치: " << this->m_Name << endl;
			m_pTree.CallItem(i)->data.DisplayRecordOnScreen();
			cout << endl;
		}
	}

	if (m_fList.LFirst(&fItem)) {						// 폴더리스트 전체를 탐색하며 반복 
		fItem.GetOverallFavorites();

		while (m_fList.LNext(&fItem)) {
			fItem.GetOverallFavorites();
		}
	}
}

// 대입연산자 오버로딩
FolderType FolderType::operator =(FolderType& folder) {
	m_Name = folder.m_Name;
	m_Date = folder.m_Date;
	m_Num = folder.m_Num;
	m_fList = folder.m_fList;
	m_pTree = folder.m_pTree;

	return *this;
}