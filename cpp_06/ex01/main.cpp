

#include "Serializer.hpp"

int main(void)
{
	Data*		ptr_address1 = new Data;
	Data*		ptr_address2;
	uintptr_t	ptr_value;

	std::cout << "Address 1:		" << ptr_address1 << std::endl;
	// std::cout << "message:		" << ptr_address1 ->message <<  std::endl;

	ptr_value = Serializer::serialize(ptr_address1);

	std::cout << "Value: 			" << ptr_value << std::endl;

	// std::cout << std::showbase << std::hex << "Value (in hexadecimal):	" << ptr_value << std::endl;

	ptr_address2 = Serializer::deserialize(ptr_value);

	std::cout << "Address 2:		" << ptr_address2 << std::endl;

	delete ptr_address1;
	return (0);
}
