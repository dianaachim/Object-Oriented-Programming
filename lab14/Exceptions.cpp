#include "Exceptions.h"



Exceptions::Exceptions() : exception{}, message{""}
{
}

Exceptions::Exceptions(const std::string& msg) : message{ msg }
{
}

const char * Exceptions::what()
{
	return this->message.c_str();
}

FileException::FileException(const std::string& msg) : message(msg)
{ 
}

const char * FileException::what()
{
	return message.c_str();
}