/*
 * MyVector.hpp
 *
 *  Created on: Nov 29, 2023
 *      Author: jerrbearr
 */

#ifndef MYVECTOR_HPP_
#define MYVECTOR_HPP_
#include <iostream>
#include <string>
using namespace std;

// I ususally leave the names of the variables in the definition until
// it is time to turn it in, and clean everything up at the end
// If you dont like the look of it in the mean time, feel free to get rid of the names
// and only leave the types.

template <typename T> class MyVector {
private:
	T* buffer;
	int bufferSize;

public:
	MyVector();
	MyVector(int a);
	MyVector(const MyVector& copyObj);
	virtual ~MyVector();
	void add(T item);
	T back() const;
	int find(T item);
	T front() const;
	void remove(T item);
	void reset();
	int size() const;

	MyVector<T>& operator=(const MyVector& otherObj);
	T& operator[](int index) const;

	class VectorError {
		private:
			string e;
		public:
			VectorError() : e("") { };
			VectorError(string s) : e(s) { };
			string what() const;
	};

};

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
    bufferSize = copyObj.bufferSize;
    buffer = new T[bufferSize];
    for (int i = 0; i < bufferSize; ++i) {
        buffer[i] = copyObj.buffer[i];
    }
}

template<typename T>
 MyVector<T>::~MyVector() {
//	delete[] buffer;
}

template<typename T>
void MyVector<T>::add(T item) {
    int newBufferSize = bufferSize + 1;
    T* newBuffer = new T[newBufferSize];
    for (int i = 0; i < bufferSize; i++) {
        newBuffer[i] = buffer[i];
    }
    delete[] buffer;
    newBuffer[newBufferSize - 1] = item;
    buffer = newBuffer;
    bufferSize = newBufferSize;
}

template<typename T>
 T MyVector<T>::back() const {
	try {
		if (bufferSize == 0) {
		throw VectorError("Vector is empty! Cannot call back() method!\n");
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
			throw VectorError("ERROR! Vector is EMPTY! Cannot call find() method!\n");
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
			throw VectorError("ERROR! Vector is empty! Cannot call front() method!\n");
			return T();
		}
	}
	catch (VectorError& e) {
		cout << e.what();
	}
	return buffer[0];
}

template<typename T>
 void MyVector<T>::remove(T item) {
	try {
		if (bufferSize == 0 || buffer == nullptr) {
			throw VectorError("Error! Vector is empty! Cannot call remove() method!\n");
		}
		else {
			int newBufferSize = bufferSize - 1;
			T* newBuffer = new T[bufferSize];
			for (int i = 0; i < newBufferSize; i++) {
				newBuffer[i] = buffer[i];
			}
		//	delete[] buffer;
			newBuffer[newBufferSize - 1] = item;
		}
	}
	catch (VectorError e) {

	}
}

template<typename T>
 void MyVector<T>::reset() {
	delete[] buffer;
	bufferSize = 0;
}

template<typename T>
 int MyVector<T>::size() const {
	return bufferSize;
}

template<typename T>
MyVector<T>& MyVector<T>::operator =(const MyVector &otherObj) {
    if (this != &otherObj) {
        delete[] buffer;
        bufferSize = otherObj.bufferSize;
        buffer = new T[bufferSize];
        for (int i = 0; i < bufferSize; ++i) {
            buffer[i] = otherObj.buffer[i];
        }
    }
    return *this;
}


template<typename T>
 T& MyVector<T>::operator [](int index) const {
	try {
		if (buffer == 0 || buffer == nullptr) {
			throw VectorError("Error! Vector is empty! Cannot use [] operator!\n");
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


#endif /* MYVECTOR_HPP_ */
