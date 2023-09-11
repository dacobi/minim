#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>

#include "waypoints.h"

int main(){

	std::ofstream outfile("waypoints1.bin", std::ios::binary );

	std::vector<unsigned char> obuffer;

	obuffer.push_back(points_level1);
	
	for(int wi = 0; wi < points_level1; wi++){
		obuffer.push_back(way_level1[wi][0]);			
		obuffer.push_back(way_level1[wi][1]);	
		obuffer.push_back(way_level1[wi][2]);			
	}
	
	outfile.write((char*)obuffer.data(),obuffer.size());
	outfile.close();

	std::ofstream outfile2("waypoints2.bin", std::ios::binary );

	std::vector<unsigned char> obuffer2;

	obuffer2.push_back(points_level2);
	
	for(int wi = 0; wi < points_level2; wi++){
		obuffer2.push_back(way_level2[wi][0]);			
		obuffer2.push_back(way_level2[wi][1]);	
		obuffer2.push_back(way_level2[wi][2]);			
	}
	
	outfile2.write((char*)obuffer2.data(),obuffer2.size());
	outfile2.close();

	
	
	return 0;
}

