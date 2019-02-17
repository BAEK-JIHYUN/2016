#pragma once
#pragma once
#ifndef _SORTEDLISTTYPE_H
#define _SORTEDLISTTYPE_H

#include <iostream>
#include <fstream>	
#include <string>

using namespace std;

/**
*	@brief ListNode struct.
*/
template <typename T>
struct ListNode
{
	T data;
	ListNode* next;
};

/**
*	@brief		Sorted LinkedList class.
*
*/
template<typename T>
class SortedListType
{
public:
	/**
	*	default constructor.
	*/
	SortedListType()
	{
		m_head = NULL;
		m_CurPointer = NULL;
		m_Length = 0;
	}

	/**
	*	copy constructor.
	*/
	SortedListType(const SortedListType<T>& list);

	/**
	*	destructor.
	*/
	~SortedListType() {
		MakeEmptyList();
	}

	/**
	*	@brief	List를 초기화한다.
	*	@pre	none.
	*	@post	List를 초기화된다.
	*/
	void InitList() {
		m_head = NULL;
		m_CurPointer = NULL;
		m_Length = 0;
	}

	/**
	*	@brief	현재 list 내에 존재하는 records의 수를 get한다.
	*	@pre	m_Length가 set되어있다.
	*	@post	없음.
	*	@return	현재 list 내에 존재하는 records의 수.
	*/
	int GetLength() {
		return m_Length;
	}

	/**
	*	@brief	list의 용량이 비어있는 지 체크한다.
	*	@pre	없음.
	*	@post	없음.
	*	@return	list가 비어있으면 true, 아니면 false를 리턴한다.
	*/
	bool IsEmptyList();

	/**
	*	@brief	list를 빈 상태로 만든다.
	*	@pre	없음.
	*	@post	list의 데이터가 전부 삭제된다.
	*/
	void MakeEmptyList();

	/**
	*	@brief	첫 번째 데이터가 data가 가리키는 메모리에 저장된다.
	*	@pre	List가 initialized 되어 있어야 한다.
	*	@post	첫 번째 데이터가 data가 가리키는 메모리에 저장된다.
	*	@param	data	참조할 데이터.
	*	@return 성공시 1, 실패시 0을 리턴한다.
	*/
	int LFirst(T* data);

	/**
	*	@brief	참조된 데이터의 다음 데이터가 data가 가리키는 메모리에 저장된다.
	*	@pre	List가 initialized 되어 있어야 한다.
	*	@post	참조된 데이터의 다음 데이터가 data가 가리키는 메모리에 저장된다.
	*	@param	data	참조할 데이터.
	*	@return 성공시 1, 실패시 0을 리턴한다.
	*/
	int LNext(T* data);

	/**
	*	@brief	Primary key를 비교하여 새 data를 list내의 알맞은 위치에 추가한다.
	*	@pre	list가 initialized 되어 있어야 한다.
	*	@post	새 record가 list의 알맞은 위치에 추가된다.
	*	@param	data	추가할 데이터.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Add(T data);

	/**
	*	@brief	데이터를 찾아서 해당 데이터를 반환한다.
	*	@pre	인수 data에 있는 Primary key가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 데이터가 data에 입력된다.
	*	@param	data	찾고자 하는 Name이 입력된 ItemType 값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Get(T& data);

	/**
	*	@brief	데이터를 찾아서 해당 데이터의 포인터를 반환한다.
	*	@pre	인수 data에 있는 Primary key가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 데이터의 주소가 리턴된다.
	*	@param	data	찾고자 하는 Name이 입력된 ItemType 값.
	*	@return	발견한 데이터의 주소값.
	*/
	T* GetAddress(T data);

	/**
	*	@brief	Primary key가 일치하는 데이터를 찾아서 해당 데이터를 제거한다.
	*	@pre	인수 data에 있는 Primary key가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 데이터가 제거된다.
	*	@param	data	제거하고자 하는 Name이 입력된 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(T& data);

	/**
	*	@brief	대입연산자 오버로딩
	*/
	SortedListType<T> operator =(const SortedListType<T>& list);


private:
	ListNode<T>* m_head;	// 첫 번째 노드를 가리키는 멤버
	ListNode<T>* m_Before;	// 삭제를 돕는 멤버
	ListNode<T>* m_CurPointer; // 참조 및 삭제를 돕는 포인터
	int m_Length; // 리스트 크기
};

#endif	// _SORTEDLISTTYPE_H



// Class copy constructor
template <typename T>
SortedListType<T>::SortedListType(const SortedListType<T>& list)
{
	ListNode<T> *ptr1;
	ListNode<T> *ptr2;

	if (list.m_head == NULL)	// 노드가 하나도 없을 때 
		m_head = NULL;
	else
	{
		// allocate memory for first node
		ptr2 = new ListNode<T>;
		m_head = ptr2;
		ptr2->data = list.m_head->data;
		ptr1 = list.m_head->next;

		// deep copy other nodes
		while (ptr1 != NULL)
		{
			ptr2->next = new ListNode<T>;
			ptr2 = ptr2->next;
			ptr2->data = ptr1->data;
			ptr1 = ptr1->next;
		}
		ptr2->next = NULL;
	}

	m_Length = list.m_Length;
}


// list가 비어있는 지 체크한다. 
template<typename T>
bool SortedListType<T>::IsEmptyList() {
	if (m_Length == 0)
		return true;
	else
		return false;
}


// list를 빈 상태로 만든다.
template<typename T>
void SortedListType<T>::MakeEmptyList() {
	ListNode<T>* temp;
	while (m_head != NULL) // 링크드리스트의 head가 리스트의 끝까지 갈때 까지
	{
		temp = m_head;
		m_head = m_head->next;
		delete temp; // 포인터 delete 중
	}
	m_Length = 0;
}


template<typename T>
int SortedListType<T>::LFirst(T* data) {
	if (m_head == NULL)						// 리스트가 비어있으면 0 이턴 
		return 0;

	m_Before = NULL;
	m_CurPointer = m_head;

	*data = m_CurPointer->data;				// data를 list의 제일 첫 node로 지정 
	return 1;
}

template<typename T>
int SortedListType<T>::LNext(T* data) {
	if (m_CurPointer->next == NULL)			// 마지막 노드이면 0리턴 
		return 0;	

	m_Before = m_CurPointer;
	m_CurPointer = m_CurPointer->next;		// data를 하나 뒤의 노드로 지정

	*data = m_CurPointer->data;
	return 1;
}


// Primary key를 비교하여 새 data를 list내의 알맞은 위치에 추가한다. 
template<typename T>
int SortedListType<T>::Add(T inData)
{
	ListNode<T>* newNode = new ListNode<T>;	// 새 노드 생성 
	newNode->data = inData;
	newNode->next = NULL;

	if (m_Length == 0)	//리스트에 아무 항목이 없으면 비교할 필요 없이 추가해준다.
	{
		m_head = newNode;
		m_Length++;

		return 1;	//항목을 추가했으므로 1을 리턴해준다.
	}

	m_CurPointer = m_head;
	m_Before = NULL;

	while (m_CurPointer != NULL) {			

		if (m_CurPointer->data < inData) {				//기존의 항목이 더 작을때(신규 항목이 더 클때)
			if (m_CurPointer->next == NULL) {
				newNode->next = NULL;
				m_CurPointer->next = newNode;
				m_Length++;
				return 1;
			}
		}

		else if(m_CurPointer->data > inData) {			//기존의 항목이 더 클때(신규 항목이 더 작을때)
			newNode->next = m_CurPointer;
			if (m_Before == NULL)			// 첫 번째 노드로 추가할 때
			{
				m_head = newNode;
				m_Before = newNode;
			}
			else							// 첫 번째 이후의 노드로 추가할 때
			{
				m_Before->next = newNode;
				newNode = m_Before;
			}
			m_Length++;
			return 1;
		}
		else {										//기존의 항목과 같을 때
			cout << "\t중복되는 데이터입니다." << endl;
			return 0;
			break;
		}

		m_Before = m_CurPointer;
		m_CurPointer = m_CurPointer->next;
	}
}


// 데이터를 찾아서 해당 데이터를 반환한다.
template<typename T>
int  SortedListType<T> ::Get(T& data) {

	T rdata;

	if (LFirst(&rdata)) {		// 첫 번째 노드일 경우
		if (m_CurPointer->data == data) {
			data = m_CurPointer->data;
			return 1;
		}

		while (LNext(&rdata)) {		// 첫 번째 노드가 아닐 경우 
			if (m_CurPointer->data == data) {
				data = m_CurPointer->data;
				return 1;
			}
		}
	}

	return 0;
}


// 데이터를 찾아서 해당 데이터의 포인터를 반환한다.
template <typename T>
T* SortedListType<T>::GetAddress(T data)
{
	T rdata;

	if (LFirst(&rdata)) {		// 첫 번째 노드일 경우
		if (m_CurPointer->data == data) {
			return &(m_CurPointer->data);
		}

		while (LNext(&rdata)) {		// 첫 번째 노드가 아닐 경우 
			if (m_CurPointer->data == data) {
				return &(m_CurPointer->data);
			}
		}
	}

	return NULL;
}


// Primary key가 일치하는 데이터를 찾아서 해당 데이터를 제거한다.
template <typename T>
int  SortedListType<T> ::Delete(T& data) {
	if (Get(data)) {
		if (m_Before == NULL)	// 첫 번째 노드를 삭제할 때
		{
			m_head = m_CurPointer->next;
			delete m_CurPointer;
			m_CurPointer = m_head;
		}
		else	// 첫 번째 이후 노드를 삭제할 때 
		{
			m_Before->next = m_CurPointer->next;
			delete m_CurPointer;
			m_CurPointer = m_Before->next;
		}
		m_Length--;

		return 1;
	}
	return 0;
}


// 대입연산자 오버로딩
template<typename T>
SortedListType<T> SortedListType<T>::operator =(const SortedListType<T>& list) {

	// 메모리 누수 방지를 위해 동적할당 해제
	this->MakeEmptyList();

	ListNode<T> *ptr1;
	ListNode<T> *ptr2;

	if (list.m_head == NULL)
		m_head = NULL;
	else
	{
		// allocate memory for first node
		ptr2 = new ListNode<T>;
		m_head = ptr2;
		ptr2->data = list.m_head->data;
		ptr1 = list.m_head->next;

		// deep copy other nodes
		while (ptr1 != NULL)
		{
			ptr2->next = new ListNode<T>;
			ptr2 = ptr2->next;
			ptr2->data = ptr1->data;
			ptr1 = ptr1->next;
		}
		ptr2->next = NULL;
	}

	m_Length = list.m_Length;

	return *this;
}
