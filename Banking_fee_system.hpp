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

//5.简单工厂和策略模式的组合
class Context
{
public:
	//工厂
	Context(double total = 0, int chioce = -1)
		:_total(total)
		,_choice(chioce)
	{
		switch (_choice)
		{
		case 1:
			std::cout << "normal" << std::endl;
			_cs = new CashNormal(_total);
			break;
		case 2:
			std::cout << "rebate" << std::endl;
			_cs = new CashRebate(_total, 0.1);
			break;
		case 3:
			std::cout << "return" << std::endl;
			_cs = new CashReturn(_total, 300, 200);
			break;
		default:
			std::cout << "Invalid Choice!" << std::endl;
			_cs = nullptr;
			exit(EXIT_FAILURE);
		}
	}

	//策略
	double GetResult()
	{
		return _cs->acceptcash();
	}
private:
	double _total;
	int _choice;
	CashSuper* _cs;
};