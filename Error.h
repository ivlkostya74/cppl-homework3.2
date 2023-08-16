#pragma once
#include <stdexcept>

class ArrayException : public std::domain_error
{
public:
	ArrayException(std::string const& err);
};