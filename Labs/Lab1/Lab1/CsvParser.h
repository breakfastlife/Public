#pragma once
#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class CsvStateMachine;	//this HAS states
class CsvState;			//This IS a state
class DefaultState;		//This IS a state
class QuoteState;		//This IS a state
class DoubleQuoteState;	//This IS a state
class EndState;			//This IS a state

class CsvState
{
protected:
	CsvStateMachine* _machine = nullptr;
public:
	virtual ~CsvState(){};
	virtual void handle() = 0;	//a pure virtual function, and provides 2 things:
								//1. means we cannot create an instance of this class directly because this class is now marked as abstract.
								//2. Ensures taht every complete instance of CsvState MUST implement this function
	CsvState(CsvStateMachine* machine) {
		_machine = machine;
	}
};

class DefaultState : public CsvState
{
public:
	DefaultState(CsvStateMachine* machine): CsvState(machine)
	{}
	virtual void handle();
};

class QuoteState : public CsvState
{
public:
	QuoteState(CsvStateMachine* machine) : CsvState(machine)
	{}
	virtual void handle();
};

class DoubleQuoteState : public CsvState
{
public:
	DoubleQuoteState(CsvStateMachine* machine) : CsvState(machine)
	{}
	virtual void handle();
};

class EndState : public CsvState
{
public:
	EndState(CsvStateMachine* machine) : CsvState(machine)
	{}
	virtual void handle();
};

void DefaultState::handle()
{

}

void QuoteState::handle()
{


}

void DoubleQuoteState::handle()
{

}

void EndState::handle()
{

}

#endif // !CSV_PARSER_H