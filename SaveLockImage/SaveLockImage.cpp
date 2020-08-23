#include <iostream>
#include <memory>
#include "headers/Init.h"

int main()
{
	auto init = std::make_unique<Init>();
	init->scan();
}