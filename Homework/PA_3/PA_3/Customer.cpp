#include "Customer.h"


//
Customer::Customer(int arrive, string name): line_name(name), arrival_time(arrive), service_time(0), departure_time(0), customer_id(0), id_counter(0)
{
}
//
Customer::Customer(int arrive): arrival_time(arrive), service_time(0)
{
}

Customer::Customer()
{
}



Customer::~Customer()
{
}


int Customer::getTotalWaitTime()
{
	return departure_time - arrival_time;
}

int Customer::getCustomerID() const
{
	return customer_id;
}
int Customer::getArrivalTime() const
{
	return arrival_time;
}
int Customer::getService_Time()
{
	return service_time;
}
int Customer::getDeparture_Time() const
{
	return departure_time;
}
int Customer::getID_Counter() const
{
	return id_counter;
}
string Customer::getLineName() const
{
	return line_name;
}
void Customer::setCustomerID(int ID)
{
	customer_id = ID;
}
void Customer::setArrivalTime(int time)
{
	arrival_time = time;
}
void Customer::setServiceTime(int STime)
{
	service_time = STime;
}
void Customer::setDepartureTime(int DTime)
{
	departure_time = DTime;
}
void Customer::setIDCounter(int IDcounter)
{
	id_counter = IDcounter;
}
void Customer::setLineName(string &name)
{
	line_name = name;
}