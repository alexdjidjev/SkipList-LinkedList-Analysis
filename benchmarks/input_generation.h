#ifndef INPUT_GENERATION_H
#define INPUT_GENERATION_H


#include <iostream>
#include <fstream>
#include <string>


const int S_FILE_INPUT_SIZE = 71;
const int M_FILE_INPUT_SIZE = 143;
const int L_FILE_INPUT_SIZE = 719;

const int S_FILE_NUM_RANGE = 20;
const int M_FILE_NUM_RANGE = 10;
const int L_FILE_NUM_RANGE = 2;


// Desc: Writes randomly generated timestamps (for events) to 'inputFile'.  
void populateInputFile(std::ofstream& inputFile, const char& sizeChar, const char& sortOrder);


#endif