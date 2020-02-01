#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <sstream>
#include <vector>
#include "Airplane.h"

#define A "A"
#define D "D"
#define PRINT "PRINT"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;


template<typename T>
class Terminal
{
private:
	string					_termnType;
	const T					_maxTermnLoad;
	vector< Airplane<T>* >	_vecAirplanes;
	T						_terminalLoad;

public:
	Terminal(const string& termnType, T maxTermnLoad );
	Terminal(const Terminal& otherTerminal);

	~Terminal();

	void beginSession();

	bool addPlane( Airplane<T>* newAirplane );
	bool delPlane( Airplane<T>* newAirplane );
	bool hasPlane( const string& name ) const;
	
	void print() const;
};


//*********************************************************************
//********************** YOUR CODE STARTS HERE ************************
//*********************************************************************

	
#endif
