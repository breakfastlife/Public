#include "CheckoutLine.h"
#include <fstream>
using namespace std;

CheckoutLine::CheckoutLine() : line_name(""), tick_count(0)
{
}

CheckoutLine::CheckoutLine(string name) : line_name(name), tick_count(0)
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
bool CheckoutLine::isEmpty()
{
	return line.size() == 0;
}
void CheckoutLine::addCustomers(Customer* some_customer)
{
	line.push(some_customer);
	cout << line.size() << endl;
	cout << "Customer has been added\n";
}
vector<Customer*>& CheckoutLine::getServicedCustomers()
{
	return served_customers;
}
void CheckoutLine::setCustomerDepartureTime(int DT)
{
	line.front()->setDepartureTime(DT);
}
int CheckoutLine::getCustomerDepartureTime()
{
	return line.front()->getDeparture_Time();
}
void CheckoutLine::setServicedCustomers()
{
	Customer* temp1 = line.front();
	served_customers.push_back(temp1);
	line.pop();
	cout << "Line size now: " << line.size() << endl;
}
int CheckoutLine::getCustomerServiceTime()
{
	return line.front()->getService_Time();
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
	for (int t = 0; t < served_customers.size() - 1; t++)
	{
		//cout << served_customers.size();
		file << served_customers[t]->getCustomerID() << " " << served_customers[t]->getArrivalTime() << " " << served_customers[t]->getService_Time();
		file << " " << served_customers[t]->getDeparture_Time() << " " << served_customers[t]->getTotalWaitTime() << " ";
		file << served_customers[t]->getLineName() << endl;
	}
}