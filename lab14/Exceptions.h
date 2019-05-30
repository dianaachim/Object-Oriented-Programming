#pragma once
#include <string>
#include <exception>

class Exceptions : public std :: exception
{
protected:
	std::string message;

public:
	Exceptions();
	Exceptions(const std::string& msg);
	virtual ~Exceptions() {};
	virtual const char* what();
};

class FileException : public std::exception
{
protected:
	std::string message;

public:
	FileException(const std::string& msg);
	virtual const char* what();
};