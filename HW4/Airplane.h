#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>

using std::string;

template<typename T> class Airplane
{
	private:
		const string _name;
		T			 _load;

	public:
    Airplane( const string& name, const T& load );
		Airplane( const Airplane& otherAirplane );

		~Airplane();
    
    /* function checks if an airplane's name is equal to another. */
		bool	isEqual( const string& name ) const;
    /* function checks if an airplane is equal to another airplane. */
		bool	isEqual( const Airplane& otherAirplane ) const;
    /* function gets the name of a plane. */
		string	getName() const;
    /* function gets the load of a plane. */
		T		getLoad() const;
    /* function sets a load to a plane. */
        void setLoad(T load);
		
};


//*********************************************************************
//********************** YOUR CODE STARTS HERE ************************
//*********************************************************************
/* default constructor */
template<typename T> Airplane<T>::Airplane(const string& name, const T& load): _name(name), _load(load){}
/* default deconstructor */
template<typename T>
Airplane<T>::~Airplane<T>(){}
/* function returns a planes name. */
template<typename T>
string Airplane<T>::getName() const{
    return _name;
}
/* function returns a planes load. */
template<typename T>
T Airplane<T>::getLoad() const{
    return _load;
}
/* function sets the amount of load for a plane. 
 * @param load - the load of a plane.
 */
template<typename T>
void Airplane<T>::setLoad(T load){
    _load = load;
}
/* function checks if a plane has the same name. 
 * @param name - name of a plane.
 */
template<typename T>
bool Airplane<T>::isEqual(const string& name) const{
    if (_name == name){
        return true;
    }
    return false;
}
/* function checks if two planes are identical. 
 * @param otherAirplane - airplane object to check if is equal to another.
 */
template<typename T>
bool Airplane<T>::isEqual(const Airplane<T>& otherAirplane) const{
    if(_name == otherAirplane._name && _load == otherAirplane._load){
        return true;
    }
    return false;
}

#endif
