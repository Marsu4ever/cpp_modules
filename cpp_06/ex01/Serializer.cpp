
#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer&	Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}


uintptr_t	Serializer::serialize(Data* ptr)
{
	// uintptr_t guarantees to be large enough to hold pointer address value

	uintptr_t pointer_value = reinterpret_cast<uintptr_t>(ptr);

	return (pointer_value);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	Data	*ptr_address = reinterpret_cast<Data *>(raw);

	return (ptr_address);
}
