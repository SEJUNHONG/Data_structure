#pragma once
#ifndef __MYDOUBLEVECTOR_H_
#define __MYDOUBLEVECTOR_H_

// HW1_2015706035_È«¼¼ÁØ
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>

using namespace std;

class MyDoubleVector
{
public:
	MyDoubleVector(double init_capacity = 100);

	MyDoubleVector(const MyDoubleVector& v);

	~MyDoubleVector();

	MyDoubleVector& operator=(const MyDoubleVector& source);

	void operator +=(const MyDoubleVector&addend);

	double& operator[](const int index) const;
	
	MyDoubleVector operator+(const MyDoubleVector& v);

	MyDoubleVector operator-(const MyDoubleVector& v);

	double operator*(const MyDoubleVector& v);

	MyDoubleVector operator-();

	bool operator==(const MyDoubleVector& v);

	MyDoubleVector operator()(double x);

	double pop_back();

	void push_back(double x);

	size_t capacity() const;
	
	size_t size() const;
	
	void reserve(size_t new_capacity);

	bool empty() const;

	void clear();

private:
	double *data;
	int used;
	int cap;
};
#endif