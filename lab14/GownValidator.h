#pragma once
#include <string>
#include <vector>
#include "Gowns.h"

class GownValidator
{
public:
	GownValidator() {};
	static void validate(Gowns& g);
};

class GownException
{
private:
	std::vector<std::string> errors;

public:
	GownException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;
};
