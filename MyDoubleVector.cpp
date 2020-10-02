// HW1_2015706035_홍세준

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>

#include "MyDoubleVector.h"
using namespace std;


	MyDoubleVector::MyDoubleVector(double init_capacity)
	{
		data = new double[cap];
		cap = init_capacity;
		used = 0;
	}
	// Precondition : x
	// Postcondition : capacity=100 초기화

	MyDoubleVector::MyDoubleVector(const MyDoubleVector& v)
	{
		data = new double[v.cap];
		cap = v.cap;
		used = v.used;
		copy(v.data, v.data + used, data);
	}
	// Precondition : const MyDoubleVector& v
	// Postcondition : deep copy

	MyDoubleVector::~MyDoubleVector()
	{
		delete[]data;
	}
	// Precondition : x
	// Postcondition : data 삭제

	MyDoubleVector& MyDoubleVector::operator=(const MyDoubleVector& source)
	{
		if (this == &source)
			return *this;
		if (cap != source.cap)
		{
			delete[]data;
			data = new double[source.cap];
			cap = source.cap;
		}
		used = source.used;
		copy(source.data, source.data + used, data);
	}
	// Precondition : const MyDoubleVector& source
	// Postcondition : deep copy, new data를 초기화

	void MyDoubleVector:: operator +=(const MyDoubleVector&addend)
	{
		if (used + addend.used > cap)
			reserve(used + addend.used);
		copy(addend.data, addend.data + addend.used, data + used);
		used += addend.used;
	}
	// Precondition : const MyDoubleVector& addend
	// Postcondition : RHS 데이터를 LHS 데이터에 추가

	double& MyDoubleVector:: operator[](const int index) const
	{
		assert(index >= 0 && index < used);

		return data[index];
	}
	// Precondition : index>=0, index<used
	// Postcondition : & 반환

	MyDoubleVector MyDoubleVector::operator+(const MyDoubleVector& v)
	{
		MyDoubleVector result= *this;
		assert(result.size() == v.size());
		for (int i = 0; i < result.size(); i++)
		{
			result[i] += v[i];
		}
		return result;
	}
	// Precondition : const MyDoubleVector& v
	// Postcondition : 벡터의 덧셈
	
	MyDoubleVector MyDoubleVector::operator-(const MyDoubleVector&v)
	{
		MyDoubleVector result = *this;
		assert(result.size() == v.size());
		for (int i = 0; i < result.size(); i++)
		{
			result[i] -= v[i];
		}
		return result;
	}
	// Precondition : const MyDoubleVector& v
	// Postcondition : 벡터의 뺄셈

	double MyDoubleVector::operator*(const MyDoubleVector&v)
	{
		MyDoubleVector v1= *this;
		double result = 0;
		assert(v1.size() == v.size());
		for (int i = 0; i < v1.size(); i++)
		{
			result += (v1[i] * v[i]);
		}
		return result;
	}
	// Precondition : const MyDoubleVector& v
	// Postcondition : 벡터의 내적

	MyDoubleVector MyDoubleVector::operator-()
	{
		MyDoubleVector result = *this;
		for (int i = 0; i < result.size(); i++)
		{
			result[i] *= -1;
		}
		return result;
	}
	// Precondition : x
	// Postcondition : -1 곱셈

	bool MyDoubleVector::operator==(const MyDoubleVector& v)
	{
		assert(used == v.size());
		for(int i=0; i<used; i++)
		{ 
			for (int j = 0; v[j] != data[i]; j++)
			{
				if (j == v.size())
				{
					return false;
				}
			}
		}
		return true;
	}
	// Precondition : const MyDoubleVector& v
	// Postcondition : 두 객체가 크기가 같고 값도 같으면 true, 아니면 false 반환

	MyDoubleVector MyDoubleVector::operator()(double x)
	{
		MyDoubleVector result = *this;
		for (size_t i = 0; i < used; i++) 
		{
			result[i] = x;
		}
		return result;
	}
	// Precondition : double x
	// Postcondition : 모든 값을 double x로 변경

	double MyDoubleVector::pop_back()
	{
		return data[--used];
	}
	// Precondition : x
	// Postcondition : 배열의 마지막 값을 반환하고 마지막 배열을 제거

	void MyDoubleVector::push_back(double x)
	{
		data[used] = x;
		used++;
	}
	// Precondition : double x
	// Postcondition : 벡터 끝에 새 배열 추가 
	
	size_t MyDoubleVector::capacity() const 
	{
		return this->cap;
	}
	// Precondition : x
	// Postcondition : 현재 용량 반환

	size_t MyDoubleVector::size() const
	{
		return this->used;
	}
	// Precondition : x
	// Postcondition : 현재 사이즈 반환
	
	void MyDoubleVector::reserve(size_t new_capacity)
	{
		double *larger_array;
		if (new_capacity == cap)
			return;
		if (new_capacity < used)
			new_capacity = used;

		larger_array = new double[new_capacity];
		copy(data, data + used, larger_array);
		delete[]data;
		data = larger_array;
		cap = new_capacity;
	}
	// Precondition : size_t new_capacity
	// Postcondition : 더 큰 배열 저장공간 할당 후 copy


	
	bool MyDoubleVector::empty() const
	{
		bool result = false;
		if (used == 0)
		{
			result = true;
		}
		return result;
	}
	// Precondition : x
	// Postcondition : 배열이 비어있으면 true 반환, 그렇지 않으면 false 반환

	void MyDoubleVector::clear()
	{
		used = 0;
		delete[] data;
		data = new double[cap];
	}
	// Precondition : x
	// Postcondition : 배열의 크기와 데이터 초기화