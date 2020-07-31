#pragma once
#include<string>
#include<vector>
using namespace std;
struct Sales_data;//6666666
istream& read(istream& is, Sales_data& item);//������ǰ����Sales_data
class Sales_data {
	friend istream& read(istream& is, Sales_data& item);
	friend ostream& print(ostream& os, const Sales_data& item);
public:
	Sales_data() = default;
	Sales_data(const string& s) : bookNo(s) {}
	Sales_data(const string& s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p* n) {}
	Sales_data(istream& is) { read(is, *this); };
	string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
private:
	double avg_price() const;
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

double Sales_data::avg_price()const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& read(istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream& print(ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}



