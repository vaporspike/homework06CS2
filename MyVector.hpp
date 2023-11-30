/*
 * MyVector.hpp
 *
 *  Created on: Nov 29, 2023
 *      Author: jerrbearr
 */

#ifndef MYVECTOR_HPP_
#define MYVECTOR_HPP_
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

class VectorError : MyVector<T>{
private:
	string e;
public:
	string VectorError = "";
	string what() const;
};

};

#endif /* MYVECTOR_HPP_ */
