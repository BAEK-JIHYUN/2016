#pragma once
#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <fstream>	
#include <string>

#define MAX_ITEMS 10
/**
*	@brief	Exception class thrown by Push when stack is full.
*/
class FullStack
{
public:
	/**
	*	@brief	Display a message for full stack on screen.
	*/
	void print()
	{
		cout << "FullStack exception thrown." << endl;
	}
};

/**
*	@brief	Exception class thrown by Pop and Top when stack is empty.
*/
class EmptyStack
{
public:
	/**
	*	@brief	Display a message for full stack on screen.
	*/
	void print()
	{
		cout << "EmtpyStack exception thrown." << endl;
	}
};

/**
*	@brief		Stack class.
*	@details	This class processes as Last In, First Out (LIFO).
*
*/
template<typename T>
class StackType {
public:
	/**
	*	default constructor.
	*/
	StackType() {
		m_top = -1;
	}

	/**
	*	destructor.
	*/
	~StackType() {
		delete[] m_items;
		MakeEmptyStack();
	}

	/**
	*	@brief	Stack�� �ʱ�ȭ�Ѵ�.
	*	@pre	none.
	*	@post	Stack�� �ʱ�ȭ�ȴ�.
	*/
	void InitStack()
	{
		m_items = new T[MAX_ITEMS];
		m_top = -1;
	}

	/**
	*	@brief	Stack�� ����� �� ������ �����Ѵ�.
	*	@pre	m_num�� set �Ǿ��ִ�.
	*	@post	����.
	*	@return	m_num.
	*/
	int getNum() const {
		return m_top + 1;
	}

	/**
	*	@brief	Stack�� �뷮�� ����ִ� �� üũ�Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@return	Stack�� ��������� true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool IsEmptyStack() const;

	/**
	*	@brief	Stack�� �뷮�� ���� á�� �� üũ�Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@return	Stack�� ���� �� ������ true, �ƴϸ� false�� �����Ѵ�.
	*/
	bool IsFullStack() const;

	/**
	*	@brief	Stack�� �� ���·� �����.
	*	@pre	����.
	*	@post	Stack�� �����Ͱ� ���� �����ȴ�.
	*/
	void MakeEmptyStack();

	/**
	*	@brief	Primary key�� ���Ͽ� �� data�� Stack���� �˸��� ��ġ�� �߰��Ѵ�.
	*	@pre	Stack�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	�� record�� Stack�� �˸��� ��ġ�� �߰��ȴ�.
	*	@param	data	�߰��� ������.
	*/
	void Push(T data);

	/**
	*	@brief	���� �ֱٿ� push�� data�� �����Ѵ�.
	*	@pre	Stack�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	list ���� �ش� data�� ���ŵȴ�.
	*	@return	data	���ŵ� data.
	*/
	T Pop();

	/**
	*	@brief	���� data�� �����Ѵ�.
	*	@pre	Stack�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	���� data.
	*/
	T Peek();

	/**
	*	@brief	n��° data�� �����Ѵ�.
	*	@pre	Stack�� initialized �Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	n��° data.
	*	@param	n	������ data�� ���� 
	*/
	T PeekN(int n);


private:
	int m_top;
	T* m_items;
};
#endif


template<typename T>
bool StackType<T>::IsEmptyStack() const {
	return (m_top == -1);
}


template<typename T>
bool StackType<T>::IsFullStack() const {
	return (m_top == (MAX_ITEMS - 1));
}


// Stack�� �� ���·� �����.
template<typename T>
void StackType<T>::MakeEmptyStack() {
	m_top = -1;
}


template<typename T>
void StackType<T>::Push(T data) {
	if (IsFullStack())				// ������ ���� �������� ����ó��
		throw FullStack();
	m_top++;
	m_items[m_top] = data;
}


template<typename T>
T StackType<T>::Pop() {
	if (IsEmptyStack())				// ������ ��������� ����ó��
		throw EmptyStack();
	T data = m_items[m_top];			// ���� ���� �����͸� ���� 
	m_top--;

	return data;
}


template<typename T>
T StackType<T>::Peek() {
	if (IsEmptyStack())
		exit(-1);
	return m_items[m_top];			//head�� ����Ű�� ��忡 ����� ������ ��ȯ
}

template<typename T>
T StackType<T>::PeekN(int n) {
	if (IsEmptyStack())
		exit(-1);
	return m_items[n];				//n��° ��忡 ����� ������ ��ȯ
}