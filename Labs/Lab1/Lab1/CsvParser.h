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

class CsvStateMachine
{
private:
	//the state machine needs to have a record of all possible states 
	CsvState* _default_state = nullptr;			//_default_state is a CsvState
	CsvState* _quote_state = nullptr;			
	CsvState* _double_quote_state = nullptr;	
	CsvState* _end_state = nullptr;				
	//keep track of active state in state machine
	CsvState* _active_state = nullptr;			
	//object form of csv file
	vector<vector<string>> _table;

	//file form  of csv file
	ifstream _csv_stream;
	
	//represents current row in raw form
	string _raw_line;

	//object form of current row being processed
	vector<string> _current_row;

	int _current_row_position; //tracks where we are in the current row being processed

	//represents current cell being operated on, programmatially constructed
	//**** THE IDEL WAY TO WORK ON STRINGS **** ostringstream
	ostringstream _current_cell;

public:
	CsvStateMachine(string file_name)
	{
		//set up states
		_default_state = new DefaultState(this);
		_quote_state = new QuoteState(this);
		_double_quote_state = new DoubleQuoteState(this);
		_end_state = new EndState(this);

		//set inital state
		_active_state = _default_state;

		//set up file stream for processing
		_csv_stream = ifstream{ file_name };
		_current_cell = ostringstream{};
	}
	~CsvStateMachine()
	{
		delete _default_state;
		delete _quote_state;
		delete _double_quote_state;
		delete _end_state;
	}

	//setter
	void setStateToDefault()
	{
		_active_state = _default_state;
	}
	void setStateToQuoteState()
	{
		_active_state = _quote_state;
	}
	void setStateToDoubleQuoteState()
	{
		_active_state = _double_quote_state;
	}
	void setStateToEndState()
	{
		_active_state = _end_state;
	}

	//allows active state to add content to the current cell
	void appendToCurrentCell(char ch)
	{
		_current_cell << ch;
	}

	//allows active state to leanrn about the char it's supposed to process
	char getNextCharToProcess()
	{
		//make sure that there is info to be processed
		if (_raw_line.length() <= _current_row_position)
		{
			return '\0';
		}
		char result = _raw_line[_current_row_position];
		_current_row_position++;
		return result;
	}

	vector<vector<string>> processFile()
	{
		getline(_csv_stream, _raw_line);
		while (_csv_stream.good() == true && _raw_line.length() > 0)
		{
			//are we done processing current line or are we at the end state?
			if (_raw_line.length() == _current_row_position || _active_state == _end_state)
			{
				//current cell is an ostringstream, so we need to convert into raw string using .str()
				_current_row.push_back(_current_cell.str());

				//reset current cell
				_current_cell = ostringstream{};

				//reset state machine
				setStateToDefault();

				//are we done with the line?
				if (_raw_line.length() == _current_row_position)
				{
					//check for dangling comma (empty cell)
					if (_raw_line[_current_row_position - 1] == ',')
					{
						_current_row.push_back("");
					}
					//we are done with the row, so add row to the table, rest row and grab a new line
					_table.push_back(_current_row);
					_current_row = vector<string>{};
					_current_row_position = 0;
					getline(_csv_stream, _raw_line);

					//end file
					if (_csv_stream.good() == false)
					{

					}
				}
			}

			else
			{
				//no new cell or line needed, continue to run state machine
				_active_state->handle();
			}
		}
	}
};

void DefaultState::handle()
{
	char next_char = _machine->getNextCharToProcess();
	if (next_char == ',')
	{
		_machine->setStateToEndState();
	}
	else if (next_char == '"')
	{
		_machine->setStateToQuoteState;
	}
	else
	{
		_machine->appendToCurrentCell(next_char);
	}
}

void QuoteState::handle()
{
	char next_char = _machine->getNextCharToProcess();
	if (next_char == '"')
	{
		_machine->setStateToDoubleQuoteState();
	}
	else
	{
		_machine->appendToCurrentCell(next_char);
	}
}

void DoubleQuoteState::handle()
{
	char next_char = _machine->getNextCharToProcess();
	if (next_char == ',')
	{
		_machine->setStateToEndState();
	}
	else
	{
		_machine->appendToCurrentCell(next_char);


	}
}

void EndState::handle()
{

}

#endif // !CSV_PARSER_H