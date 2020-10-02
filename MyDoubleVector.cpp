// HW1_2015706035_ȫ����

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
	// Postcondition : capacity=100 �ʱ�ȭ

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
	// Postcondition : data ����

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
	// Postcondition : deep copy, new data�� �ʱ�ȭ

	void MyDoubleVector:: operator +=(const MyDoubleVector&addend)
	{
		if (used + addend.used > cap)
			reserve(used + addend.used);
		copy(addend.data, addend.data + addend.used, data + used);
		used += addend.used;
	}
	// Precondition : const MyDoubleVector& addend
	// Postcondition : RHS �����͸� LHS �����Ϳ� �߰�

	double& MyDoubleVector:: operator[](const int index) const
	{
		assert(index >= 0 && index < used);

		return data[index];
	}
	// Precondition : index>=0, index<used
	// Postcondition : & ��ȯ

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
	// Postcondition : ������ ����
	
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
	// Postcondition : ������ ����

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
	// Postcondition : ������ ����

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
	// Postcondition : -1 ����

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
	// Postcondition : �� ��ü�� ũ�Ⱑ ���� ���� ������ true, �ƴϸ� false ��ȯ

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
	// Postcondition : ��� ���� double x�� ����

	double MyDoubleVector::pop_back()
	{
		return data[--used];
	}
	// Precondition : x
	// Postcondition : �迭�� ������ ���� ��ȯ�ϰ� ������ �迭�� ����

	void MyDoubleVector::push_back(double x)
	{
		data[used] = x;
		used++;
	}
	// Precondition : double x
	// Postcondition : ���� ���� �� �迭 �߰� 
	
	size_t MyDoubleVector::capacity() const 
	{
		return this->cap;
	}
	// Precondition : x
	// Postcondition : ���� �뷮 ��ȯ

	size_t MyDoubleVector::size() const
	{
		return this->used;
	}
	// Precondition : x
	// Postcondition : ���� ������ ��ȯ
	
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
	// Postcondition : �� ū �迭 ������� �Ҵ� �� copy


	
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
	// Postcondition : �迭�� ��������� true ��ȯ, �׷��� ������ false ��ȯ

	void MyDoubleVector::clear()
	{
		used = 0;
		delete[] data;
		data = new double[cap];
	}
	// Precondition : x
	// Postcondition : �迭�� ũ��� ������ �ʱ�ȭ