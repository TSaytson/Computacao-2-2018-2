
#include "aula0201.h"


ull
CalcularMaximoDivisorComum(ull numero1, ull numero2)
{	ull resto = 0;
	
	if (numero1 == 0 && numero2 ==0)
		return 0;
	if	(numero1 == 0)
		return numero2;
	if (numero2 == 0)
		return numero1;
	if (numero1%numero2 != 0)
		do
		{
			resto = numero1%numero2;
			numero1 = numero2;
			numero2 = resto;
		}	
		while (numero1%numero2 != 0);
	return numero2;


}


