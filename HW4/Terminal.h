#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <sstream>
#include <vector>
#include "Airplane.h"

#define A "A"
#define D "D"
#define PRINT "PRINT"
#define NOT_FOUND -1

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
    /* function gets a new terminal and controls all functions. */
    void beginSession();
    /* function controls airplanes that wants to arrive at the terminal. */
    bool addPlane( Airplane<T>* newAirplane );
    /* function controls airplanes that wants to depart from the terminal. */
    bool delPlane( Airplane<T>* newAirplane );
    /* function checks if theres a plane with this name in the terminal. */
    bool hasPlane( const string& name ) const;
    /* function checks if the limit of the terminal load is exceeded. */
    bool isLimitExceeded(T load);
    /* function checks if the terminal has enough load for an airplane to depart with. */
    bool hasLoad(T load);
    /* function checks if a plane exists in the terminal and returns his location
     * in the vector.
     */
    int isPlaneExist(const string& name) const;
    /* function prints all available airplanes in the terminal. */
    void print() const;
};


    //*********************************************************************
    //********************** YOUR CODE STARTS HERE ************************
    //*********************************************************************
/* default constructor */
template<typename T>
Terminal<T>::Terminal(const string& termnType, T maxTermnLoad ): _termnType(termnType),
_maxTermnLoad(maxTermnLoad), _terminalLoad(0){}
template<typename T> Terminal<T>::Terminal(const Terminal& otherTerminal){
    _termnType = otherTerminal._termnType;
    _maxTermnLoad = otherTerminal._maxTermnLoad;
    _terminalLoad = otherTerminal._terminalLoad;
    typename vector<Airplane<T>*>::iterator it;
    for(it = otherTerminal._vecAirplanes.begin(); it != otherTerminal._vecAirplanes.end();
        it++){
        Airplane<T> *new_airplane = new Airplane<T>((*it)->getName(), (*it)->getLoad());
        _vecAirplanes.push_back(new_airplane);
    }
}
/* destructor */
template <typename T>
Terminal<T>::~Terminal<T>(){
    typename vector<Airplane<T>*>::iterator iter;
    for(iter = _vecAirplanes.begin(); iter != _vecAirplanes.end(); iter++){
        delete *iter;
        _vecAirplanes.erase(iter);
    }
}
/* function that starts the parser and controls all functions
 * then gets an order from the user.
 * the function then gets the name of the airplane and the amount of cargo it is
 * carrying for arrival and departure orders and sends them to the respective functions
 * after creating a new airplane with the parameters that were recieved by the user.
 * for a PRINT order the function calls a function that prints all airplanes available
 * in the terminal.
 */
template <typename T>
void Terminal<T>::beginSession(){
    
    string planeName, command, line;
    T cargo_size;
    
    while(getline(cin, line)){
        std::istringstream cut(line);
        cut >> command;
        
        if(command == A){
            cut >> planeName;
            cut >> cargo_size;
            Airplane<T>* new_airplane = new Airplane<T>(planeName, cargo_size);
            addPlane(new_airplane);
        }
        if(command == D){
            cut >> planeName;
            cut >> cargo_size;
            if(hasPlane(planeName)){
                int planeIndex = isPlaneExist(planeName);
                _vecAirplanes[planeIndex]->setLoad(cargo_size);
                delPlane(_vecAirplanes[planeIndex]);
            } else {
                cout << "The plane was not registered: " + planeName << endl;
            }
        }
        if(command == PRINT){
            print();
        }
    }
}
/* function that adds a plane to the terminal when he arrives.
 * checks if the terminal has enough space to store the load the plane arrived with.
 * if it has available space then the plane "lands" and the load is added to the
 * terminal load. if the plane has too much load then a message will appear saying
 * that theres not enough room in the terminal for the airplane's load.
 * if the plane is already in the terminal a message will appear saying that the
 * airplane is already registered in the terminal.
 * @param newAirplane - an airplane that wants to land in the terminal.
 */
template <typename T>
bool Terminal<T>::addPlane(Airplane<T>* newAirplane){
    if(!hasPlane(newAirplane->getName())){
        if(!isLimitExceeded(newAirplane->getLoad() + _terminalLoad)){
            _vecAirplanes.push_back(newAirplane);
            _terminalLoad += newAirplane->getLoad();
        } else {
            cout << "Not enough free space for: " + newAirplane->getName() << endl;
        }
    } else {
        cout << "The plane is already registered: " + newAirplane->getName() << endl;
    }
    return false;
}
/* function that removes a plane from the terminal when he departs.
 * checks if the terminal has enough load for the plane to depart with.
 * if theres enough load then the airplane departs with the load and the load he took
 * is decreased from the terminal load. if theres not enough load then a message will
 * appear saying that theres not enough objects allocated for the plane.
 * @param newAirplane - an airplane that wants to depart from the terminal.
 */
template<typename T>
bool Terminal<T>::delPlane(Airplane<T>* newAirplane){
    int planeIndex = isPlaneExist(newAirplane->getName());
    if(hasPlane(newAirplane->getName())){
        if(hasLoad(newAirplane->getLoad())){
            _vecAirplanes.erase(_vecAirplanes.begin() + planeIndex);
            _terminalLoad -= newAirplane->getLoad();
        } else {
            cout << "Not enough allocated objects for: " + newAirplane->getName() << endl;
        }
            //return true;
    }
    return false;
}
/* checks if a plane is in the terminal.
 * @param name - a name of an airplane to check if exists.
 */
template <typename T>
bool Terminal<T>::hasPlane(const string& name) const{
    return (isPlaneExist(name) != -1) ? true : false;
}
/* function checks if a plane exists. if it does, the function returns
 * the airplanes location in the vector. if it doesnt exist returns NOT_FOUND.
 * @param name - a name of an airplane to check if exists.
 */
template <typename T>
int Terminal<T>::isPlaneExist(const string& name) const{
    int index = 0;
    typename vector<Airplane<T>*>::const_iterator iter_find;
    iter_find = _vecAirplanes.begin();
    while (iter_find != _vecAirplanes.end()){
        if((*iter_find)->isEqual(name)){
            return index;
        }
        index++;
        iter_find++;
    }
    return NOT_FOUND;
}
/*function prints all planes in the terminal. */
template<typename T>
void Terminal<T>::print() const{
    typename vector<Airplane<T>*>::const_iterator iter_find;
    iter_find = _vecAirplanes.begin();
    if(!_vecAirplanes.empty()){
        while (iter_find != _vecAirplanes.end()){
            cout << (*iter_find)->getName() << endl;
            iter_find++;
        }
    } else cout << "There are no airplanes in the terminal." << endl;
}
/* checks if the cargo/passenger limit in the terminal is exceeded.
 * @param load - the load that an airplane is carrying.
 */
template<typename T>
bool Terminal<T>::isLimitExceeded(T load){
    if(load > _maxTermnLoad){
        return true;
    }
    return false;
}
/* checks if the terminal has enough load for a plane to depart with.
 * @param load - the load that an airplane is carrying.
 */
template<typename T>
bool Terminal<T>::hasLoad(T load){
    if(_terminalLoad >= load){
        return true;
    }
    return false;
}

#endif
