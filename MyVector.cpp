/*
 * MyVector.cpp
 *
 *  Created on: Nov 29, 2023
 *      Author: jerrbearr
 */

#include "MyVector.hpp"
#include <iostream>
#include <string>
using namespace std;

// TODO: implement functions in this file

template<typename T>
 MyVector<T>::MyVector() {
	bufferSize = 0;
	buffer = new T[bufferSize];

}

template<typename T>
 MyVector<T>::MyVector(int a) {
	bufferSize = a;
	buffer = new T[bufferSize];
}

template<typename T>
 MyVector<T>::MyVector(const MyVector &copyObj) {
	this->buffer = copyObj.buffer;
	this->bufferSize = copyObj.bufferSize;
}

template<typename T>
 MyVector<T>::~MyVector() {
	if (bufferSize > 0) {
		for (unsigned i = 0; i <= bufferSize; i++) {
			delete buffer[i];
		}
	}
	delete[] buffer;
}

template<typename T>
 void MyVector<T>::add(T item) {
	int newBufferSize = bufferSize + 1;
	T* newBuffer = new T[bufferSize];
	for (int i = 0; i < newBufferSize; i++) {
		newBuffer[i] = buffer[i];
		delete buffer[i];
	}
	delete[] buffer;
	newBuffer[newBufferSize - 1] = item;
}

template<typename T>
 T MyVector<T>::back() const {
	try {
		if (bufferSize == 0) {
		throw VectorError("Vector empty!");
		}
		else return buffer[bufferSize - 1];
	}
	catch (VectorError& e) {
		cout << e.what();
	}
	return T();
}

template<typename T>
 int MyVector<T>::find(T item) {
	int index = 0;
	for (int i = 0; i < bufferSize - 1; i++) {
		try {
		if (bufferSize == 0) {
			throw VectorError("ERROR! Vector is EMPTY!");
		}
		else if (item == buffer[i]) {
			index = i;
			break;
		}
		else throw VectorError("Item not found!\n");
		}
		catch (VectorError& e) {
			cout << e.what();
		}
	}
return index;
}

template<typename T>
 T MyVector<T>::front() const {
	try {
		if (bufferSize == 0) {
			throw VectorError("ERROR! Vector is emtpy!!\n");
		}
		else return buffer[0];
	}
	catch (VectorError& e) {
		cout < e.what();
	}
}

template<typename T>
 void MyVector<T>::remove(T item) {
	int newBufferSize = bufferSize - 1;
	T* newBuffer = new T[bufferSize];
	for (int i = 0; i < newBufferSize; i++) {
		newBuffer[i] = buffer[i];
		delete buffer[i];
	}
	delete[] buffer;
	newBuffer[newBufferSize - 1] = item;
}

template<typename T>
 void MyVector<T>::reset() {
	for (int i = 0 ;i < bufferSize;i++) {
		delete buffer[i];
	}
	delete[] buffer;
}

template<typename T>
 int MyVector<T>::size() const {
	return bufferSize;
}

template<typename T>
 MyVector<T>& MyVector<T>::operator =(const MyVector &otherObj) {
	delete[] buffer;
	buffer = new T[bufferSize];
	bufferSize = otherObj.bufferSize;
	for (int i = 0; i < bufferSize; i++) {
		buffer[i] = otherObj.buffer[i];
	}
}


template<typename T>
 T& MyVector<T>::operator [](int index) const {
	try {
		if (buffer == 0) {
			throw VectorError("Error! Vector is empty!\n");
		}
		if (index >= bufferSize) {
			throw VectorError("Out of bounds error!\n");
		}
	}
	catch (VectorError& e){
		cout << e.what();
	}
	return buffer[index];
}

template<typename T>
 string MyVector<T>::VectorError::what() const {
	return e;
}

