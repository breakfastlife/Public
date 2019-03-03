#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer
{
private:
	int customer_id;
	int arrival_time;
	int service_time;
	int departure_time;
	int id_counter;
	string line_name;
public:
	Customer(int arrive, string name);
	Customer(string name);
	Customer();
	~Customer();
	int getTotalWaitTime();
	int getCustomerID() const;
	int getArrivalTime() const;
	int getService_Time();
	int getDeparture_Time() const;
	int getID_Counter() const;
	string getLineName() const;
	void setCustomerID(int ID);
	void setArrivalTime(int time);
	void setServiceTime(int STime);
	void setDepartureTime(int DTime);
	void setIDCounter(int IDcounter);
	void setLineName(string &name);
};

