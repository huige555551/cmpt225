/*
 * filename: word.h/word.cpp
 *
 * Description: A word object that stores a pair of strings
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#include <iostream> //for cout
#include "word2.h"

/*private:
string src; //lookup word
string dest; //translation of the word
*/

//preconditions: none
//postconditions: creates a word object with empty fields for src and dest
//description: default constructor
word2::word2()
{
	//nothing to do
//	cout << "Word created, Source: " << src << " Destination: " << dest << endl; //for debugging
}

//preconditions: none
//postconditions: creates a shell word object for searching
//description: constructor that fills in the class
word2::word2(string inputSrc):
		src(inputSrc)
{
	//nothing to do
//	cout << "Word created, Source: " << src << " Destination: " << dest << endl; //for debugging
}

//preconditions: none
//postconditions: creates a word object
//description: constructor that fills in the class
word2::word2(string inputSrc, string inputDest):
		src(inputSrc),
		dest(inputDest)
{
	//nothing to do
//	cout << "Word created, Source: " << src << " Destination: " << dest << endl; //for debugging
}

//preconditions: none
//postconditions: none
//description: default destructor
word2::~word2()
{
	//nothing to do
	//cout << "Word destructor, Source: " << src << " Destination: " << dest << endl; //for debugging
}

//preconditions: src is a non empty string
//postconditions: 0 if src is set correctly, 1 if there is an error
//description: sets the source word
uint8_t word2::setSrc(string inputSrc)
{
	if(inputSrc.length() == 0) //check if input is empty
	{
		return 1; //return error, can't be empty
	}
	
	src = inputSrc;
	return 0; //all good
}

//preconditions: dest is a non empty string
//postconditions: 0 if dest is set correctly, 1 if there is an error
//description: sets the destination word
uint8_t word2::setDest(string inputDest)
{
	if(inputDest.length() == 0) //check if input is empty
	{
		return 1; //return error, can't be empty
	}
	
	dest = inputDest;
	return 0; //all good
}

//preconditions: none
//postconditions: src is returned
//description: gets the value of src
string word2::getSrc(void) const
{
	return src;
}

//preconditions: none
//postconditions: dest is returned
//description: gets the value of dest
string word2::getDest(void) const
{
	return dest;
}

//preconditions: none
//postconditions: returns 0 if src and dest are empty, returns 1 if dest is empty, and returns 2 if both are not empty
//description: gets the value of dest
uint8_t word2::size(void) const
{
	//cout << "Src: " << src << "=" << src.length() << " Dest: " << dest << "=" <<  dest.length() << endl;
	if(src.length() != 0 && dest.length() != 0)
	{
		return 2; //both are filled
	}
	
	if(src.length() != 0)
	{
		return 1; //only src is empty
	}
	
	return 0; //both are empty
}

//preconditions: inputWord is not null
//postconditions: 0 if inputWord is greater than "this", 1 if less than "this"
//description: less than overloaded operator
bool word2::operator<(word2& inputWord) const
{
	if(src.compare(inputWord.getSrc()) < 0) //check if source less than inputWord
	{
		return true;
	}
	return false;
}

//preconditions: inputWord is not null
//postconditions: 1 if src == inputWord.getSrc(), 0 otherwise
//description: equality overloaded operator
bool word2::operator==(word2& inputWord) const
{
	if(src.compare(inputWord.getSrc()) == 0) //check if src is the same as inputWord's src
	{
		return true;
	}
	return false;
}

/*
//preconditions: inputWord is not null
//postconditions: 1 if src != inputWord.getSrc(), 0 otherwise
//description: equality overloaded operator
bool word2::operator!=(word& inputWord) const
{
	if(src.compare(inputWord.getSrc()) != 0) //check if src is the same as inputWord's src
	{
		return true;
	}
	return false;
}*/

/*
//preconditions: none
//postconditions: overloads cout to print out the word object
//description: cout overloaded operator
ostream& word2::operator<<(ostream& os)
{
	return os << this->getSrc() << ":" << this->getDest();
}
*/

//preconditions: none
//postconditions: prints out the word object
//description: cout overloaded operator
void word2::print(void) const
{
	cout << getSrc() << ":" << getDest() << endl;
}