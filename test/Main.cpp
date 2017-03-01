/*
 * Main.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: andrea
 */

#include <GtComparator.h>

int main(int argc, char **argv) {

	if (argc < 2) {
		std::cerr << std::endl
				<< "Usage: ./reconstructionEvaluator path_to_settings"
				<< std::endl;
		return 1;
	}

	reconstructorEvaluator::GtComparator comparator(argv[1]);
	comparator.run();

}

