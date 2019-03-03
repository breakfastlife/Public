#pragma once
#include "Customer.h"
#include <queue>
#include <iostream>

using namespace std;

class CheckoutLine
{
private:
	string line_name;
	int tick_count;
	queue<Customer*> line;
	vector<Customer*> served_customers;
public:
	CheckoutLine();
	CheckoutLine(string name);
	~CheckoutLine();
	string getLineName();
	int getCustomerServiceTime();
	int getCustomerDepartureTime();
	bool isEmpty();
	void addCustomers(Customer* some_customer);
	vector<Customer*>& getServicedCustomers();
	void setCustomerDepartureTime(int DT);
	void setServicedCustomers();
	void tick();
	void getServed_Customers(ofstream& file);
	int checkSize();
};

