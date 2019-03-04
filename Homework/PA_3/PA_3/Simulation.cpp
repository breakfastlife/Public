#include "Customer.h"
#include "CheckoutLine.h"
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>

using namespace std;


void simulation()
{
	cout << "How many checkout lines would you like to simulate: ";
	int stands, int_stands(0), Open_mins(720), prob_count(0), customer_count(0);
	cin >> stands;
	vector<CheckoutLine> CheckoutStands = {};
	
	
	CheckoutStands.resize(stands);
	CheckoutLine* temp_stand = CheckoutStands.data();
	for(int_stands; int_stands < stands; int_stands++)
		*temp_stand = CheckoutLine(to_string(int_stands));

	srand(time(NULL));
	for (int time_passed = 0; time_passed < Open_mins; time_passed++)
	{
		//cout << time_passed << endl;
		//Determining if a new customer will join the checkout lines
		int random_1 = rand() % 5;
		if (random_1 > prob_count) //no new customer
		{
			prob_count++;
		}
		if (random_1 <= prob_count) //new customer
		{
			prob_count = 0;
			int arrival = time_passed;
			string line_name = to_string(customer_count);
			//Customer* customer = NULL;
			Customer temp = Customer(arrival, line_name);
			temp.setCustomerID(customer_count);
			customer_count++;
			//customer->setServiceTime(rand() % 4 + 1); //setting the service time needed for the customer
			temp.setServiceTime(rand() % 4 + 1);
			int insert_count(1); //if ==1 then customer has not been set to a checkoutline
			//for (int i = 0; i < stands; i++)
			//{
			//	if(insert_count == 1)
			//	if (CheckoutStands[i].isEmpty()) //if any checkout stand is empty, then add new customer to checkout stand
			//	{
			//		CheckoutStands[i].addCustomers(customer);
			//		cout << "stand: " << i << " " << CheckoutStands[i].checkSize() << endl;
			//		insert_count--; //makes insert_count 0, indicating the customer was added to a lane
			//	}
			//}
			for (int i = 0; i < stands; i++)
			{
				if(insert_count == 1)
				if (CheckoutStands[i].isEmpty()) //if any checkout stand is empty, then add new customer to checkout stand
				{
					CheckoutStands[i].addCustomers(temp);
					CheckoutStands[i].setLineName(to_string(i));
					insert_count--; //makes insert_count 0, indicating the customer was added to a lane
				}
			}
			//if (insert_count == 1) //if no empty lanes, add to a random_1 lane
			//{
			//	int p = rand() % stands;
			//	CheckoutStands[p].addCustomers(customer);
			//	cout << p << " " << CheckoutStands[p].checkSize() << endl;
			//	insert_count--;
			//}
			if (insert_count == 1) //if no empty lanes, add to a random_1 lane
			{
				int p = rand() % stands;
				CheckoutStands[p].addCustomers(temp);
				CheckoutStands[p].setLineName(to_string(p));
				insert_count--;
			}
			/*for (auto g : CheckoutStands)
			{
				if (g.isEmpty() == false)
				{
					if (g.getCustomerDepartureTime() == 0)
					{
						cout << "but: ";
						int dt = time_passed + g.getCustomerServiceTime();
						cout << dt << " " << g.getLineName() << " \n";
						g.setCustomerDepartureTime(dt);
					}
				}
			}
			for (auto p : CheckoutStands)
			{
				if (p.isEmpty() == false)
					if (time_passed >= p.getCustomerDepartureTime())
					{
						cout << "why tho\n";
						p.setServicedCustomers();
					}
			}*/
			
			for (int j = 0; j < stands; j++)
			{
				if (CheckoutStands[j].isEmpty() == false)
				{
					
					if (CheckoutStands[j].getCustomerDepartureTime() == 0)
					{
						
						int dt = time_passed + CheckoutStands[j].getCustomerServiceTime();
						
						CheckoutStands[j].setCustomerDepartureTime(dt);
					}
					if (time_passed >= CheckoutStands[j].getCustomerDepartureTime())
					{
						
						CheckoutStands[j].setServicedCustomers();
						//checkoutstands[j].checksize();
					}
				}
			}
		}

	}
	
	ofstream file("Jacks_mart_out.csv");
	file << "Customer ID" << "," << "Arrival Time" << "," << "Time to Check out";
	file << "," << "Departure Time" << "," << "Total Wait" << "," << "Line Number" << endl;
	
	for (int r = 0; r < stands; r++)
		CheckoutStands[r].getServed_Customers(file);


}

/*
	


*/