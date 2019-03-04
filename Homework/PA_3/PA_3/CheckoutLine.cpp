#include "CheckoutLine.h"
#include <fstream>
using namespace std;

CheckoutLine::CheckoutLine() : line_name(" "), tick_count(0)
{
}

CheckoutLine::CheckoutLine(string name) : line_name(name), tick_count(0), line()
{
	cout << "CheckoutLine: " << name << " successfully created\n";
}


CheckoutLine::~CheckoutLine()
{
}

string CheckoutLine::getLineName()
{
	return line_name;
}
void CheckoutLine::setLineName(string name)
{
	line_name = name;
	line.front().setLineName(name);
}
bool CheckoutLine::isEmpty()
{
	return line.size() == 0;
}
void CheckoutLine::addCustomers(Customer some_customer)
{
	line.push(some_customer);
	//cout << line.size() << endl;
	//cout << "Customer has been added to: " << line_name << "\n";
}
vector<Customer> CheckoutLine::getServicedCustomers()
{
	return served_customers;
}
void CheckoutLine::setCustomerDepartureTime(int DT)
{
	line.front().setDepartureTime(DT);
}
int CheckoutLine::getCustomerDepartureTime()
{
	return line.front().getDeparture_Time();
}
void CheckoutLine::setServicedCustomers()
{
	Customer temp1 = line.front();
	served_customers.push_back(temp1);
	line.pop();
}
int CheckoutLine::getCustomerServiceTime()
{
	return line.front().getService_Time();
}
void CheckoutLine::tick()
{
	tick_count++;
}
int CheckoutLine::checkSize()
{
	return line.size();
}

void CheckoutLine::getServed_Customers(ofstream& file)
{
	for (auto t: served_customers)
	{
		//cout << served_customers.size();
		file << t.getCustomerID() << "," << t.getArrivalTime() << "," << t.getService_Time();
		file << "," << t.getDeparture_Time() << "," << t.getTotalWaitTime() << ",";
		file << t.getLineName() << endl;
	}
}