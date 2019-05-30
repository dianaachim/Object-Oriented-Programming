#include "GownValidator.h"

using namespace std;

GownException::GownException(std::vector<std::string> _errors): errors{_errors}
{
}

std::vector<std::string> GownException::getErrors() const
{
	return this->errors;
}

void GownValidator::validate(Gowns& g)
{
	vector<string> errors;
	size_t posWww = g.getPhoto().find("www");
	size_t posHttp = g.getPhoto().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The photo source must start with http or www");
	if (g.getPrice() <= 0)
		errors.push_back("The price must be a positive nonzero number!");

	if (errors.size() > 0)
		throw GownException(errors);
}
