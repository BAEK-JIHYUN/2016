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
	*	@brief	Stack을 초기화한다.
	*	@pre	none.
	*	@post	Stack이 초기화된다.
	*/
	void InitStack()
	{
		m_items = new T[MAX_ITEMS];
		m_top = -1;
	}

	/**
	*	@brief	Stack에 저장된 총 개수를 리턴한다.
	*	@pre	m_num이 set 되어있다.
	*	@post	없음.
	*	@return	m_num.
	*/
	int getNum() const {
		return m_top + 1;
	}

	/**
	*	@brief	Stack의 용량이 비어있는 지 체크한다.
	*	@pre	없음.
	*	@post	없음.
	*	@return	Stack이 비어있으면 true, 아니면 false를 리턴한다.
	*/
	bool IsEmptyStack() const;

	/**
	*	@brief	Stack의 용량이 가득 찼는 지 체크한다.
	*	@pre	없음.
	*	@post	없음.
	*	@return	Stack이 가득 차 있으면 true, 아니면 false를 리턴한다.
	*/
	bool IsFullStack() const;

	/**
	*	@brief	Stack을 빈 상태로 만든다.
	*	@pre	없음.
	*	@post	Stack의 데이터가 전부 삭제된다.
	*/
	void MakeEmptyStack();

	/**
	*	@brief	Primary key를 비교하여 새 data를 Stack내의 알맞은 위치에 추가한다.
	*	@pre	Stack이 initialized 되어 있어야 한다.
	*	@post	새 record가 Stack의 알맞은 위치에 추가된다.
	*	@param	data	추가할 데이터.
	*/
	void Push(T data);

	/**
	*	@brief	가장 최근에 push된 data를 제거한다.
	*	@pre	Stack이 initialized 되어 있어야 한다.
	*	@post	list 내에 해당 data가 제거된다.
	*	@return	data	제거된 data.
	*/
	T Pop();

	/**
	*	@brief	현재 data를 리턴한다.
	*	@pre	Stack이 initialized 되어 있어야 한다.
	*	@post	없음.
	*	@return	현재 data.
	*/
	T Peek();

	/**
	*	@brief	n번째 data를 리턴한다.
	*	@pre	Stack이 initialized 되어 있어야 한다.
	*	@post	없음.
	*	@return	n번째 data.
	*	@param	n	리턴할 data의 순서 
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


// Stack을 빈 상태로 만든다.
template<typename T>
void StackType<T>::MakeEmptyStack() {
	m_top = -1;
}


template<typename T>
void StackType<T>::Push(T data) {
	if (IsFullStack())				// 스택이 가득 차있으면 예외처리
		throw FullStack();
	m_top++;
	m_items[m_top] = data;
}


template<typename T>
T StackType<T>::Pop() {
	if (IsEmptyStack())				// 스택이 비어있으면 예외처리
		throw EmptyStack();
	T data = m_items[m_top];			// 제일 위의 데이터를 꺼냄 
	m_top--;

	return data;
}


template<typename T>
T StackType<T>::Peek() {
	if (IsEmptyStack())
		exit(-1);
	return m_items[m_top];			//head가 가리키는 노드에 저장된 데이터 반환
}

template<typename T>
T StackType<T>::PeekN(int n) {
	if (IsEmptyStack())
		exit(-1);
	return m_items[n];				//n번째 노드에 저장된 데이터 반환
}