#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>

#include "loadscreen.h"

int main(){

	std::ofstream outfile("load.bin", std::ios::binary );

	std::vector<unsigned char> obuffer;

	obuffer.push_back(42);
	obuffer.push_back(16);
	
	for(int wi = 0; wi < (32*32); wi++){
		obuffer.push_back(loadscreen[wi]);
		if(loadscreen[wi] == 0){
			obuffer.push_back(0x0);
		} else {
			obuffer.push_back(0xff);		
		}
		/*
		obuffer.push_back(loadscreen[wi]);
		if(loadscreen[wi] == 0){
			obuffer.push_back(0x11);
		} else {
			obuffer.push_back(0x22);		
		}*/

	}
	
	for(int wi = 0; wi < 8; wi++){
		obuffer.push_back(0x0);
	}
	
	for(int wi = 0; wi < 8; wi++){
		obuffer.push_back(0xff);
	}
	
	outfile.write((char*)obuffer.data(),obuffer.size());
	outfile.close();
	
	std::cout << "load.bin has been written" << std::endl;
	
	return 0;
}

