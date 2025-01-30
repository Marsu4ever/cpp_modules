
#include "generateAndIdentify.hpp"

int main(void)
{
	Base*	ptr;

	ptr = generate();
	Base& 	ref = *ptr;

	identify(ptr);
	identify(ref);

	delete ptr;
	return (0);
}
