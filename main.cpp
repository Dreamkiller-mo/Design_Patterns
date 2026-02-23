#include <iostream>
#include <cstdio>
#include "Banking_fee_system.hpp"

using namespace std;

double GetFinalPrice(CashSuper* cs)
{
	return cs->acceptcash();
}
int main()
{
	cout << "please input your total price:" << endl;
	double price = 0.0;
	cin >> price;
	int choice = 0;
	printf("1.normal\n2.rebate\n3.return\n");
	cin >> choice;
	Factory f(choice,price);
	double res = GetFinalPrice(f.creatcashaccept());
	cout << res << endl;
	return 0;
}