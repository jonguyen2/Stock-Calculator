#include <iostream>
#include <string>
#include "Stocklist.h"
#include <iomanip>
#include <fstream>

using namespace std;

ofstream out;

int main()
{
	out.open("Porfolio.txt");

	Stocklist stocks;
	string name, date; //stock name and (todays) date 

	int num_of_stocks;
	double stockPrice_initial, stockPrice_monthly, stock_invested;

	vector<string> month; //to contain month names
	vector<double> annual_prices;
	int choice;


	out << "*********************PORTFOLIO**********************\n";
	cout << "*********************PORTFOLIO**********************\n";

	cout << "0. - Quit\n1. - Calculate monthly stock profit (includes multiple stocks)\n2. - Calculate annual stock profit (single stock)\n";
	cin >> choice;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (choice == 0)
		exit(EXIT_FAILURE);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (choice == 1)
	{
		cout << "Enter the month:\n";
		cin.ignore();
		getline(cin, date);
		out << endl;
		out << date << endl;
		cout << endl;

		cout << "How many different stocks do you have?\n";
		out << "\nNumber of different stocks you own: "; //out to output to text doc

		cin >> num_of_stocks;
		out << num_of_stocks << endl;

		cout << endl;

		for (int index = 0; index < num_of_stocks; index++) //loop to ask company name, price of stock (day1), price of stock(end)
		{
			cout << "Enter the company name:\n";
			cin >> name;
			stocks.set_stock_name(name);

			out << "Company name: " << name << endl;

			cout << endl;

			cout << "Enter the price of the stock when you purchased it:\n";
			cin >> stockPrice_initial;

			out << "Initial Price: $" << stockPrice_initial << endl;

			cout << "\nEnter the price of the stock by the end of the month: \n";
			cin >> stockPrice_monthly;
			stocks.set_price(stockPrice_initial, stockPrice_monthly);

			out << "Stock at the end of the month: $" << stockPrice_monthly << endl;

			cout << "\nHow much money did you invest in this stock?\n";
			cin >> stock_invested;

			out << "Amount you have invested: $" << stock_invested << endl;

			cout << "\nThe percent change for " << name << " this month is: \n";
			cout << stocks.get_percent_change();

			out << "The percent change is: " << stocks.get_percent_change() << "%" << endl;

			cout << "%\n\n";

			cout << setprecision(2) << fixed << showpoint;
			cout << "The profit earned for " << name << " is:\n";
			cout << stocks.get_invididualProfit(stock_invested);

			double profit = stocks.get_invididualProfit(stock_invested);

			stocks.set_totalProfit(profit);


			cout << "$\n";
			cout << "**************************************************\n";

			out << setprecision(2) << showpoint << fixed;
			out << "The profit you have earned for this month is: $" << stocks.get_invididualProfit(stock_invested) << endl;
			out << endl;
		}

		cout << "The total amount you have earned for " << date << " is:\n"; //cout total profit
		cout << stocks.get_totalProfit(num_of_stocks);

		out << "The profit you made for this month is: " << stocks.get_totalProfit(num_of_stocks) << endl;

		cout << "$\n";
		cout << "**************************************************\n";
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else if (choice == 2)
	{
		cout << "Enter the year:\n";
		cin.ignore();
		getline(cin, date);
		out << endl;
		out << date << endl;
		cout << endl;

		cout << "Enter the company name:\n"; // ask user for company name
		cin >> name;
		stocks.set_stock_name(name);
		out << "Company name: " << name << endl;

		month = stocks.insertMonthes(); //calls to vector of monthes in order to cout them
		for (int i = 0; i < 12; i++)
		{
			cout << "Enter the price of the stock for " << month[i] << ":\n";
			cin >> stockPrice_initial;
			stocks.set_totalProfit(stockPrice_initial);
			out << month[i] << "'s stock price was: $" << stockPrice_initial << endl;
		}

		cout << "How much money did you invest in this stock?\n";
		cin >> stock_invested;
		cout << "*****************************************************\n";
		out << "Amount you have invested: $" << stock_invested << endl << endl;

		annual_prices = stocks.get_annualPrices();

		for (int i = 0; i < 12; i = i + 2)
		{
			stocks.set_price(annual_prices[i], annual_prices[i + 1]);
			cout << setprecision(2) << fixed << showpoint;
			cout << "The percent change from " << month[i] << " to " << month[i + 1] << " is " << stocks.get_percent_change() << "%" << endl; //functions to display month and percent change 
			out << "The percent change from " << month[i] << " to " << month[i + 1] << " is " << stocks.get_percent_change() << "%" << endl;

			if (i == 0 || i == 2 || i == 4 || i == 6 || i == 8)
			{
				stocks.set_price(annual_prices[i + 1], annual_prices[i + 2]);
				cout << "The percent change from " << month[i + 1] << " to " << month[i + 2] << " is " << stocks.get_percent_change() << "%" << endl; //functions to display month and percent change 
				out << "The percent change from " << month[i + 1] << " to " << month[i + 2] << " is " << stocks.get_percent_change() << "%" << endl;
			}
		}

		stocks.set_price(annual_prices[0], annual_prices[11]); //sets values for total profit made comparing first month to last month
		stocks.get_percent_change();
		stocks.get_invididualProfit(stock_invested);

		cout << "\nThe total profit made this year was: \n";
		cout << "$" << stocks.get_invididualProfit(stock_invested) << "\n\n";

		out << setprecision(2) << showpoint << fixed;
		out << "\nThe profit you made for this year is: $" << stocks.get_invididualProfit(stock_invested) << endl;

	}
	else
		exit(EXIT_FAILURE);
	out.close();
	system("pause");
	return 0;
}

