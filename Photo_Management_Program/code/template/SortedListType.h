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
	*	@brief	List�� �ʱ�ȭ�Ѵ�.
	*	@pre	none.
	*	@post	List�� �ʱ�ȭ�ȴ�.
	*/
	void InitList() {
		m_head = NULL;
		m_CurPointer = NULL;
		m_Length = 0;
	}

	/**
	*	@brief	���� list ���� �����ϴ� records�� ���� get�Ѵ�.
	*	@pre	m_Length�� set�Ǿ��ִ�.
	*	@post	����.
	*	@return	���� list ���� �����ϴ� records�� ��.
	*/
	int GetLength() {
		return m_Length;
	}

	/**
	*	@brief	list�� �뷮�� ����ִ� �� üũ�Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@return	list�� ��������� true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool IsEmptyList();

	/**
	*	@brief	list�� �� ���·� �����.
	*	@pre	����.
	*	@post	list�� �����Ͱ� ���� �����ȴ�.
	*/
	void MakeEmptyList();

	/**
	*	@brief	ù ��° �����Ͱ� data�� ����Ű�� �޸𸮿� ����ȴ�.
	*	@pre	List�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	ù ��° �����Ͱ� data�� ����Ű�� �޸𸮿� ����ȴ�.
	*	@param	data	������ ������.
	*	@return ������ 1, ���н� 0�� �����Ѵ�.
	*/
	int LFirst(T* data);

	/**
	*	@brief	������ �������� ���� �����Ͱ� data�� ����Ű�� �޸𸮿� ����ȴ�.
	*	@pre	List�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	������ �������� ���� �����Ͱ� data�� ����Ű�� �޸𸮿� ����ȴ�.
	*	@param	data	������ ������.
	*	@return ������ 1, ���н� 0�� �����Ѵ�.
	*/
	int LNext(T* data);

	/**
	*	@brief	Primary key�� ���Ͽ� �� data�� list���� �˸��� ��ġ�� �߰��Ѵ�.
	*	@pre	list�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	�� record�� list�� �˸��� ��ġ�� �߰��ȴ�.
	*	@param	data	�߰��� ������.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Add(T data);

	/**
	*	@brief	�����͸� ã�Ƽ� �ش� �����͸� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� Primary key�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� �����Ͱ� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� Name�� �Էµ� ItemType ��.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Get(T& data);

	/**
	*	@brief	�����͸� ã�Ƽ� �ش� �������� �����͸� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� Primary key�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� �������� �ּҰ� ���ϵȴ�.
	*	@param	data	ã���� �ϴ� Name�� �Էµ� ItemType ��.
	*	@return	�߰��� �������� �ּҰ�.
	*/
	T* GetAddress(T data);

	/**
	*	@brief	Primary key�� ��ġ�ϴ� �����͸� ã�Ƽ� �ش� �����͸� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� Primary key�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� �����Ͱ� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� Name�� �Էµ� ItemType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Delete(T& data);

	/**
	*	@brief	���Կ����� �����ε�
	*/
	SortedListType<T> operator =(const SortedListType<T>& list);


private:
	ListNode<T>* m_head;	// ù ��° ��带 ����Ű�� ���
	ListNode<T>* m_Before;	// ������ ���� ���
	ListNode<T>* m_CurPointer; // ���� �� ������ ���� ������
	int m_Length; // ����Ʈ ũ��
};

#endif	// _SORTEDLISTTYPE_H



// Class copy constructor
template <typename T>
SortedListType<T>::SortedListType(const SortedListType<T>& list)
{
	ListNode<T> *ptr1;
	ListNode<T> *ptr2;

	if (list.m_head == NULL)	// ��尡 �ϳ��� ���� �� 
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


// list�� ����ִ� �� üũ�Ѵ�. 
template<typename T>
bool SortedListType<T>::IsEmptyList() {
	if (m_Length == 0)
		return true;
	else
		return false;
}


// list�� �� ���·� �����.
template<typename T>
void SortedListType<T>::MakeEmptyList() {
	ListNode<T>* temp;
	while (m_head != NULL) // ��ũ�帮��Ʈ�� head�� ����Ʈ�� ������ ���� ����
	{
		temp = m_head;
		m_head = m_head->next;
		delete temp; // ������ delete ��
	}
	m_Length = 0;
}


template<typename T>
int SortedListType<T>::LFirst(T* data) {
	if (m_head == NULL)						// ����Ʈ�� ��������� 0 ���� 
		return 0;

	m_Before = NULL;
	m_CurPointer = m_head;

	*data = m_CurPointer->data;				// data�� list�� ���� ù node�� ���� 
	return 1;
}

template<typename T>
int SortedListType<T>::LNext(T* data) {
	if (m_CurPointer->next == NULL)			// ������ ����̸� 0���� 
		return 0;	

	m_Before = m_CurPointer;
	m_CurPointer = m_CurPointer->next;		// data�� �ϳ� ���� ���� ����

	*data = m_CurPointer->data;
	return 1;
}


// Primary key�� ���Ͽ� �� data�� list���� �˸��� ��ġ�� �߰��Ѵ�. 
template<typename T>
int SortedListType<T>::Add(T inData)
{
	ListNode<T>* newNode = new ListNode<T>;	// �� ��� ���� 
	newNode->data = inData;
	newNode->next = NULL;

	if (m_Length == 0)	//����Ʈ�� �ƹ� �׸��� ������ ���� �ʿ� ���� �߰����ش�.
	{
		m_head = newNode;
		m_Length++;

		return 1;	//�׸��� �߰������Ƿ� 1�� �������ش�.
	}

	m_CurPointer = m_head;
	m_Before = NULL;

	while (m_CurPointer != NULL) {			

		if (m_CurPointer->data < inData) {				//������ �׸��� �� ������(�ű� �׸��� �� Ŭ��)
			if (m_CurPointer->next == NULL) {
				newNode->next = NULL;
				m_CurPointer->next = newNode;
				m_Length++;
				return 1;
			}
		}

		else if(m_CurPointer->data > inData) {			//������ �׸��� �� Ŭ��(�ű� �׸��� �� ������)
			newNode->next = m_CurPointer;
			if (m_Before == NULL)			// ù ��° ���� �߰��� ��
			{
				m_head = newNode;
				m_Before = newNode;
			}
			else							// ù ��° ������ ���� �߰��� ��
			{
				m_Before->next = newNode;
				newNode = m_Before;
			}
			m_Length++;
			return 1;
		}
		else {										//������ �׸�� ���� ��
			cout << "\t�ߺ��Ǵ� �������Դϴ�." << endl;
			return 0;
			break;
		}

		m_Before = m_CurPointer;
		m_CurPointer = m_CurPointer->next;
	}
}


// �����͸� ã�Ƽ� �ش� �����͸� ��ȯ�Ѵ�.
template<typename T>
int  SortedListType<T> ::Get(T& data) {

	T rdata;

	if (LFirst(&rdata)) {		// ù ��° ����� ���
		if (m_CurPointer->data == data) {
			data = m_CurPointer->data;
			return 1;
		}

		while (LNext(&rdata)) {		// ù ��° ��尡 �ƴ� ��� 
			if (m_CurPointer->data == data) {
				data = m_CurPointer->data;
				return 1;
			}
		}
	}

	return 0;
}


// �����͸� ã�Ƽ� �ش� �������� �����͸� ��ȯ�Ѵ�.
template <typename T>
T* SortedListType<T>::GetAddress(T data)
{
	T rdata;

	if (LFirst(&rdata)) {		// ù ��° ����� ���
		if (m_CurPointer->data == data) {
			return &(m_CurPointer->data);
		}

		while (LNext(&rdata)) {		// ù ��° ��尡 �ƴ� ��� 
			if (m_CurPointer->data == data) {
				return &(m_CurPointer->data);
			}
		}
	}

	return NULL;
}


// Primary key�� ��ġ�ϴ� �����͸� ã�Ƽ� �ش� �����͸� �����Ѵ�.
template <typename T>
int  SortedListType<T> ::Delete(T& data) {
	if (Get(data)) {
		if (m_Before == NULL)	// ù ��° ��带 ������ ��
		{
			m_head = m_CurPointer->next;
			delete m_CurPointer;
			m_CurPointer = m_head;
		}
		else	// ù ��° ���� ��带 ������ �� 
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


// ���Կ����� �����ε�
template<typename T>
SortedListType<T> SortedListType<T>::operator =(const SortedListType<T>& list) {

	// �޸� ���� ������ ���� �����Ҵ� ����
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
