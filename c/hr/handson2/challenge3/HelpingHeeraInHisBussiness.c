#include <stdio.h>
/*
 * Heera has recently started transportation bussiness. He has few buses and he needs to decide whether a given root is proﬁttable or
not. He can not aﬀord full ﬂedged software as it would be expensive. So as his friend write a simple C program to help him. We will
be ignoring other costs (like wear and tear of the bus, insurance cost, driver salary etc.) for simplicity of the program.
*/

int main() {

    /* Enter your code here. */    
	float mileageOfTheBusM;//(kilometers/litre) (may not be whole number).
	float priceOfOneLitreOfDieselP;// (in rupees) (may not be whole number).
	float lengthOfARouteL;//(in kilometers) - L (may not be whole number).
	int numberOfPassangersN;//N (whole number)
	float ticketAmountForOnePassangerT;// (in rupees) (may not be whole number)



	scanf("%f",&mileageOfTheBusM);
	scanf("%f",&priceOfOneLitreOfDieselP);
	scanf("%f",&lengthOfARouteL);
	scanf("%d",&numberOfPassangersN);
	scanf("%f",&ticketAmountForOnePassangerT);

	float earnings;
	float spendings;
	earnings = numberOfPassangersN * ticketAmountForOnePassangerT;
	spendings = lengthOfARouteL * (priceOfOneLitreOfDieselP/mileageOfTheBusM);
	printf("%d",(int)(earnings-spendings));
	return 0;
}
