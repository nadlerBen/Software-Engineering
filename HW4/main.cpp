#include <cstdio>
#include <iostream>
#include "Terminal.h"

typedef enum { PASS=0, CARGO } eTerminalType;
const string sTerminalType[] = {"PASSENGER TERMINAL", "CARGO TERMINAL"};

const unsigned	maxPassLoad(  2000 );
const double	maxCargoLoad( 50.0 );



int main()
{
	std::string  firstLine;
	
	getline(cin, firstLine);
	while(firstLine.compare("")== 0) {
		getline(cin, firstLine);
	}

	if( firstLine == sTerminalType[PASS] )
	{
		Terminal< unsigned > myTerminal( sTerminalType[PASS], maxPassLoad );
		myTerminal.beginSession();
	}

	if( firstLine == sTerminalType[CARGO] )
	{
		Terminal< double > myTerminal( sTerminalType[CARGO], maxCargoLoad );
		myTerminal.beginSession();
	}

//	system("PAUSE");
	return 0;
}
