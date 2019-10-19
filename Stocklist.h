#ifndef STOCKLIST_H
#define STOCKLIST_H

#include <string>
#include <vector>
using namespace std;

class Stocklist
{
private:

	string stock_name;
	double initialPrice,
		finalPrice,
		percentChange;
	vector<double> totalProfit;

public:
	// mutator functions
	void set_stock_name(string& name);
	void set_price(double& p, double& p2);
	void set_totalProfit(double& p);
	// accessor functions
	double get_percent_change();
	double get_invididualProfit(double);
	double get_totalProfit(int);
	vector<double> get_annualPrices();
	vector<string> insertMonthes();
};

void Stocklist::set_stock_name(string& name)
{
	stock_name = name;
}

void Stocklist::set_price(double& p, double& p2)
{
	initialPrice = p;
	finalPrice = p2;
}

void Stocklist::set_totalProfit(double& p)
{
	totalProfit.push_back(p);
}

double Stocklist::get_percent_change()
{
	percentChange = ((finalPrice - initialPrice) / initialPrice) * 100.00;
	return percentChange;
}

double Stocklist::get_invididualProfit(double amount_invested)
{
	double profit_earned;
	profit_earned = ((percentChange / 100.00) * amount_invested);
	return profit_earned;

}

double Stocklist::get_totalProfit(int num_of_stocks)
{
	double total = 0;
	for (int index = 0; index < num_of_stocks; index++)
	{
		total += totalProfit[index];
	}
	return total;
}

vector<string> Stocklist::insertMonthes()
{
	vector<string> monthes;
	monthes.push_back("January");
	monthes.push_back("February");
	monthes.push_back("March");
	monthes.push_back("April");
	monthes.push_back("May");
	monthes.push_back("June");
	monthes.push_back("July");
	monthes.push_back("August");
	monthes.push_back("September");
	monthes.push_back("October");
	monthes.push_back("November");
	monthes.push_back("December");
	return monthes;
}

vector<double> Stocklist::get_annualPrices()
{
	return totalProfit;
}
#endif