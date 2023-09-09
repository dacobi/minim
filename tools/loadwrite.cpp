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
	
	obuffer.push_back(0b00000001);
	obuffer.push_back(0b00000011);		
	obuffer.push_back(0b00000111);		
	obuffer.push_back(0b00001111);							
	obuffer.push_back(0b00011111);
	obuffer.push_back(0b00111111);		
	obuffer.push_back(0b01111111);		
	obuffer.push_back(0b11111111);							

	obuffer.push_back(0b10000000);
	obuffer.push_back(0b11000000);		
	obuffer.push_back(0b11100000);		
	obuffer.push_back(0b11110000);							
	obuffer.push_back(0b11111000);
	obuffer.push_back(0b11111100);		
	obuffer.push_back(0b11111110);		
	obuffer.push_back(0b11111111);							

	obuffer.push_back(0b11111111);
	obuffer.push_back(0b01111111);		
	obuffer.push_back(0b00111111);		
	obuffer.push_back(0b00011111);							
	obuffer.push_back(0b00001111);
	obuffer.push_back(0b00000111);		
	obuffer.push_back(0b00000011);		
	obuffer.push_back(0b00000001);							

	obuffer.push_back(0b11111111);
	obuffer.push_back(0b11111110);		
	obuffer.push_back(0b11111100);		
	obuffer.push_back(0b11111000);							
	obuffer.push_back(0b11110000);
	obuffer.push_back(0b11100000);		
	obuffer.push_back(0b11000000);		
	obuffer.push_back(0b10000000);							



	
	outfile.write((char*)obuffer.data(),obuffer.size());
	outfile.close();
	
	std::cout << "load.bin has been written" << std::endl;
	
	return 0;
}

