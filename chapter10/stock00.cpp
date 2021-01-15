#include <iostream>
#include "stock00.h"

void Stock::acquire(const std::string & co, long n, double pr)
{
	company = co;
	if (n < 0) {
		shares = 0;
	} else
		shares = n;
	share_val = pr;
	set_tot();
}
void Stock::buy(long num, double price)
{
	if (num > 0) {
		shares += num;
		share_val = price;
		set_tot();
	}
}
