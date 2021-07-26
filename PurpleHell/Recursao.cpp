#include "Recursao.h"



Recursao::Recursao()
{


}

Recursao::Recursao(std::string name, int n)
{
	if (n > 0) {
		std::cout << name[n - 1];
		Recursao(name, n - 1);
	}
}


Recursao::~Recursao()
{
}
