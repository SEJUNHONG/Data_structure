// HW1_2015706035_全技霖

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include "MyDoubleVector.h"
using namespace std;

void Vector(MyDoubleVector v) 
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << "\n" << endl;
}

int main(void)
{
	MyDoubleVector v1, v2;  // Constructor
	cout << " MyDoubleVector v1, v2 积己磊\n" << endl;

	cout << "v1 capacity " << v1.capacity() << endl; // capacity
	cout << "v2 capacity " << v2.capacity() << endl;

	v1.push_back(1.0);
	v1.push_back(2.0);
	Vector(v1);
	
	v2.push_back(3.0);
	v2.push_back(4.0);
	Vector(v2);

	MyDoubleVector v11(v1);  // Copy Constructor
	MyDoubleVector v12(v1);
	cout << " MyDoubleVector v11, v12 汗荤 积己磊" << endl;

	Vector(v11);
	Vector(v12);

	v2 = v1;  // Operator =
	cout << "v2=v1" << endl;
	Vector(v2);

	v1 += v2;  // Operator +=
	cout << "v1+=v2" << endl;
	Vector(v1);

	cout << "v1[0]=" << v1[0] << endl;  // Operator []
	cout << "v1[1]=" << v1[1] << endl;  
	cout << "v1[2]=" << v1[2] << endl;  
	cout << "v1[3]=" << v1[3] << endl;  
	
	Vector(v11 + v12);  // (binary) Operator +
	Vector(v11 - v12);  // (binary) Operator -
	
	cout << "v11*v12=" << v11 * v12 << endl;  // (binary) Operator *

	Vector(-v1); // (unary) Operator -

	cout << "v11==v12 " << ((v11 == v12) ? "true" : "false") << endl;  // Operator ==

	Vector(v2(10));  // (unary) Operator ()

	v1.pop_back();  // pop_back
	Vector(v1);

	v1.push_back(3.0);  // push_back
	v1.push_back(4.0);
	Vector(v1);

	cout << "v1 capacity " << v1.capacity() << endl; // capacity
	cout << "v2 capacity " << v2.capacity() << endl; 
	cout << "v1 size " << v1.size() << endl;  // size
	cout << "v2 size " << v2.size() << endl;

	v11.reserve(v11.capacity() + 10); // reserve
	cout << "v11 capacity " << v11.capacity() << endl;

	cout << "v11.empty " << ((v11.empty()) ? "true" : "false") << endl; // empty

	v11.clear(); // clear
	cout << "v11.empty " << ((v11.empty()) ? "true" : "false") << endl;
	

	return 0;
}
