#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "colors.hpp"
#include "Data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &);
public:
	~Serializer();
	Serializer &operator=(const Serializer &rhs);

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
