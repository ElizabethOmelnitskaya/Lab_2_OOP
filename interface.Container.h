#pragma once

class Container {
public:
	virtual int Size() const = 0;
	virtual bool isEmpty() const = 0;
	virtual char* toString() const = 0;
	virtual ~Container() = 0;
};