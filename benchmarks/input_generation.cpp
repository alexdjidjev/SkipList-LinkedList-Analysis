#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "input_generation.h"
//#include "../src/event.h"


int main() {
	srand(13);

	/*
	// ------ 3 Size Options ------ //
		- small (71 elements) 	('S')
		- medium (143 elements) ('M')
		- large (719 elements) 	('L')

	// ------ 3 Sortedness Options ------ //
		- sorted ascending 	('A')
		- random 			('R')
		- sorted descending ('D')
	*/

	// -------------- Clear All Previous Data -------------- //
	std::ofstream s_ascend_file("small_inputs/s_ascend.txt", std::ios::trunc);
	std::ofstream s_random_file("small_inputs/s_random.txt", std::ios::trunc);
	std::ofstream s_descend_file("small_inputs/s_descend.txt", std::ios::trunc);

	std::ofstream m_ascend_file("medium_inputs/m_ascend.txt", std::ios::trunc);
	std::ofstream m_random_file("medium_inputs/m_random.txt", std::ios::trunc);
	std::ofstream m_descend_file("medium_inputs/m_descend.txt", std::ios::trunc);

	std::ofstream l_ascend_file("large_inputs/l_ascend.txt", std::ios::trunc);
	std::ofstream l_random_file("large_inputs/l_random.txt", std::ios::trunc);
	std::ofstream l_descend_file("large_inputs/l_descend.txt", std::ios::trunc);


	// -------------- Opening Files in Append Mode -------------- //
	s_ascend_file = std::ofstream("small_inputs/s_ascend.txt", std::ios::app);
	s_random_file = std::ofstream("small_inputs/s_random.txt", std::ios::app);
	s_descend_file = std::ofstream("small_inputs/s_descend.txt", std::ios::app);

	m_ascend_file = std::ofstream("medium_inputs/m_ascend.txt", std::ios::app);
	m_random_file = std::ofstream("medium_inputs/m_random.txt", std::ios::app);
	m_descend_file = std::ofstream("medium_inputs/m_descend.txt", std::ios::app);

	l_ascend_file = std::ofstream("large_inputs/l_ascend.txt", std::ios::app);
	l_random_file = std::ofstream("large_inputs/l_random.txt", std::ios::app);
	l_descend_file = std::ofstream("large_inputs/l_descend.txt", std::ios::app);


	// -------------- Populating Files -------------- //	
	populateInputFile(s_ascend_file, 'S', 'A');
	populateInputFile(s_descend_file, 'S', 'D');
	populateInputFile(s_random_file, 'S', 'R');

	populateInputFile(m_ascend_file, 'M', 'A');
	populateInputFile(m_descend_file, 'M', 'D');
	populateInputFile(m_random_file, 'M', 'R');

	populateInputFile(l_ascend_file, 'L', 'A');
	populateInputFile(l_descend_file, 'L', 'D');
	populateInputFile(l_random_file, 'L', 'R');


	// Closing output file stream objects.
	s_ascend_file.close();
	s_random_file.close();
	s_descend_file.close();

	m_ascend_file.close();
	m_random_file.close();
	m_descend_file.close();
	
	l_ascend_file.close();
	l_random_file.close();
	l_descend_file.close();
}


void populateInputFile(std::ofstream& inputFile, const char& sizeChar, const char& sortOrder) {

	int randTimeStamp;
	int fileInputSize;
	int fileNumRange;
	int max;
	int min;

	// Determining which size input file to populate.
	switch (sizeChar) 
	{
		case 'S':
			fileInputSize = S_FILE_INPUT_SIZE;
			fileNumRange = S_FILE_NUM_RANGE;

			break;

		case 'M':
			fileInputSize = M_FILE_INPUT_SIZE;
			fileNumRange = M_FILE_NUM_RANGE;

			break;

		case 'L':
			fileInputSize = L_FILE_INPUT_SIZE;
			fileNumRange = L_FILE_NUM_RANGE;

			break;	
	}

	// Determining the sortOrder.
	switch (sortOrder)
	{
		case 'A':
			max = fileNumRange;
			min = 0;
			break;

		case 'D':
			max = fileInputSize*fileNumRange;
			min = max-fileNumRange;
			fileNumRange *= -1;
			break;

		case 'R':
			max = fileInputSize*fileNumRange;
			min = 0;
			fileNumRange = 0;
			break;
	}

	// Populating Inputs
	for (int i = 0; i < fileInputSize; i++) {
		randTimeStamp = rand() % (max - min + 1) + min;

		//std::cout << randTimeStamp << " ---- " << "(" << min << " - " << max << ")" << std::endl;

		inputFile << "TEST_" << sizeChar << "_" << sortOrder << "_" << i << ", " << randTimeStamp << "\n";

		max += fileNumRange;
		min += fileNumRange;
	}
}