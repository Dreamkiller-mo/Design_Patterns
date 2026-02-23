#pragma once
#include <iostream>

//1.基类
class CashSuper
{
public:
	CashSuper(double cash = 0)
		:_cash(cash)
	{ }
	virtual double acceptcash() { return _cash; }
private:
	double _cash;
};

//2.普通类
class CashNormal :public CashSuper
{
public:
	CashNormal(double cash = 0)
		:CashSuper(cash)
	{ }
	virtual double acceptcash()
	{
		return CashSuper::acceptcash();
	}
};

//3.打折类
class CashRebate :public CashSuper
{
public:
	CashRebate(double cash = 0, double d=0)
		:CashSuper(cash)
		,_d(d)
	{ }
	virtual double acceptcash() { return CashSuper::acceptcash() * _d; }
private:
	double _d;
};

//4.返还类
class CashReturn :public CashSuper
{
public:
	CashReturn(double cash = 0, double money_condition=0, double money_return=0)
		:CashSuper(cash)
		,_money_condition(money_condition)
		,_money_return(money_return)
	{ }
	virtual double acceptcash()
	{
		if (CashSuper::acceptcash() >= _money_condition) return CashSuper::acceptcash() - _money_return;
	}
private:
	double _money_condition;
	double _money_return;
};

//5.简单工厂
class Factory
{
public:
	Factory(int choice = 0, double total=0.0)
		:_choice(choice)
		,_total(total)
	{ }
	CashSuper* creatcashaccept()
	{
		if (_choice == 0)
		{
			std::cout << "no choice , will exit..." << std::endl;
			exit(EXIT_FAILURE);
		}
		CashSuper* cs = nullptr;
		switch (_choice)
		{
		case 1:
			std::cout << "normal price:" << std::endl;
			cs = new CashNormal(_total);
			break;
		case 2:
			std::cout << "rebate price:" << std::endl;
			cs = new CashRebate(_total, 0.1);
			break;
		case 3:
			std::cout << "return price:" << std::endl;
			cs = new CashReturn(_total, 300, 200);
			break;
		default:
			std::cout << "invalid choice " << std::endl;
			break;
		}
		return cs;
	}

private:
	int _choice;
	double _total;
};