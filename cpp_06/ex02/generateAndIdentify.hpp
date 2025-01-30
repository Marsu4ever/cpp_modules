
#pragma once

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>  // rand() && srand()
#include <ctime>    // time()

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
