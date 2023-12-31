#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>
#include <fstream>

#define LOAD_map 0x1F000
#define VRAM_offset 0xA800
#define CARS_size 5632
#define BOOM_size 4096
#define JUMP_size 20480
#define TRTXT_size 5632

int main(int argc, char *argv[]){


	if( (argc < 2) || (argc > 10) ){
	
		std::cout << "Usage: " << std::string(argv[0]) << " <tiles size track1> [ <tiles size track2> ... <tiles size track9> ]" << std::endl;
		std::cout << "Where <tiles size #> is the size of the main track tiles file in bytes in decimal, including the 2 byte header" << 	std::endl;
		return 0;
	
	}


	std::ofstream outfile("game.bin", std::ios::binary );

	std::vector<unsigned char> obuffer;
		
	char mLevels = (argc - 1);

	obuffer.push_back(mLevels);
	
	std::cout <<  std::hex << std::endl;
	
	for(int ti = 0; ti < mLevels; ti++){
	
		std::stringstream conv;

		conv << std::string(argv[ti+1]) << std::endl;

		unsigned int tSize;

		conv >> tSize;
		tSize -= 2;
		
		if((VRAM_offset + tSize + CARS_size + BOOM_size + JUMP_size + TRTXT_size) >= LOAD_map){
			std::cout << "Error: VRAM Overflow in Track" << (ti+1) << std::endl;
			return 1;
		}

		if((tSize + VRAM_offset) < 0x10000){
			tSize = 0x10000 - VRAM_offset;
			std::cout << "Tiles Size Track" << (ti+1) << " Padded for min Sprite address of 0x10000" << std::endl << std::endl;
		} else {
			std::cout << "Tiles Size Track" << (ti+1) << " Is : " << tSize << std::endl << std::endl;
		}

		//Jump Sprite	
		
		unsigned int mJumpAddr = VRAM_offset + tSize;
		
		unsigned char mJumpLo,mJumpHi;
		
		std::cout << "Jump Addr: " << mJumpAddr << std::endl;
		
		mJumpLo = (unsigned char)(mJumpAddr & 0x00ff);
		mJumpHi = (unsigned char)((mJumpAddr >> 8) & 0x00ff);
	
		std::cout << "Jump Addr Hi: " << (int)(mJumpHi) << std::endl;
		std::cout << "Jump Addr Lo: " << (int)(mJumpLo) << std::endl;		

	
		obuffer.push_back(mJumpHi);
		obuffer.push_back(mJumpLo);		
		
		mJumpAddr = mJumpAddr >> 5;
		
		mJumpLo = (unsigned char)(mJumpAddr & 0x00ff);
		mJumpHi = (unsigned char)((mJumpAddr >> 8) & 0x00ff);
		
		std::cout << "Jump Short Hi: " << (int)(mJumpHi) << std::endl;
		std::cout << "Jump Short Lo: " << (int)(mJumpLo) << std::endl << std::endl;		

	
		obuffer.push_back(mJumpHi);
		obuffer.push_back(mJumpLo);		
		
		

		//Car Sprite		
		unsigned int mCarsAddr = VRAM_offset + tSize + JUMP_size;

		std::cout << "Car Addr: " << mCarsAddr << std::endl;
		
		unsigned char mCarLo,mCarHi;
		
		mCarLo = (unsigned char)(mCarsAddr & 0x00ff);
		mCarHi = (unsigned char)((mCarsAddr >> 8) & 0x00ff);
	
		std::cout << "Car Addr Hi: " << (int)(mCarHi) << std::endl;
		std::cout << "Car Addr Lo: " << (int)(mCarLo) << std::endl;		
	
		obuffer.push_back(mCarHi);
		obuffer.push_back(mCarLo);		
		
		mCarsAddr = mCarsAddr >> 5;
		
		mCarLo = (unsigned char)(mCarsAddr & 0x00ff);
		mCarHi = (unsigned char)((mCarsAddr >> 8) & 0x00ff);

		std::cout << "Car Short Hi: " << (int)(mCarHi) << std::endl;
		std::cout << "Car Short Lo: " << (int)(mCarLo) << std::endl << std::endl;		

	
		obuffer.push_back(mCarHi);
		obuffer.push_back(mCarLo);		

		//Boom Sprite		
		unsigned int mBoomAddr = VRAM_offset + tSize + CARS_size + JUMP_size;

		std::cout << "Boom Addr: " << mBoomAddr << std::endl;
		
		unsigned char mBoomLo,mBoomHi;
		
		mBoomLo = (unsigned char)(mBoomAddr & 0x00ff);
		mBoomHi = (unsigned char)((mBoomAddr >> 8) & 0x00ff);
	
		std::cout << "Boom Addr Hi: " << (int)(mBoomHi) << std::endl;
		std::cout << "Boom Addr Lo: " << (int)(mBoomLo) << std::endl;		
	
		obuffer.push_back(mBoomHi);
		obuffer.push_back(mBoomLo);		
		
		mBoomAddr = mBoomAddr >> 5;
		
		mBoomLo = (unsigned char)(mBoomAddr & 0x00ff);
		mBoomHi = (unsigned char)((mBoomAddr >> 8) & 0x00ff);

		std::cout << "Boom Short Hi: " << (int)(mBoomHi) << std::endl;
		std::cout << "Boom Short Lo: " << (int)(mBoomLo) << std::endl << std::endl;		

	
		obuffer.push_back(mBoomHi);
		obuffer.push_back(mBoomLo);		
				

		//LAPS TXT Sprite	
		unsigned int mLPAddr = VRAM_offset + tSize + CARS_size + BOOM_size + JUMP_size;
		
		std::cout << "TXT Laps Addr: " << mLPAddr << std::endl;
		
		unsigned char mLPLo,mLPHi;
		
		mLPLo = (unsigned char)(mLPAddr & 0x00ff);
		mLPHi = (unsigned char)((mLPAddr >> 8) & 0x00ff);
		
		std::cout << "TXT Laps Addr Hi: " << (int)(mLPHi) << std::endl;
		std::cout << "TXT Laps Addr Lo: " << (int)(mLPLo) << std::endl;		

	
		obuffer.push_back(mLPHi);
		obuffer.push_back(mLPLo);		
		
		mLPAddr = mLPAddr >> 5;
		
		mLPLo = (unsigned char)(mLPAddr & 0x00ff);
		mLPHi = (unsigned char)((mLPAddr >> 8) & 0x00ff);
		
		std::cout << "TXT Laps Short Hi: " << (int)(mLPHi) << std::endl;
		std::cout << "TXT Laps Short Lo: " << (int)(mLPLo) << std::endl << std::endl;		

	
		obuffer.push_back(mLPHi);
		obuffer.push_back(mLPLo);		
	
	}
		
	outfile.write((char*)obuffer.data(),obuffer.size());
	outfile.close();
	
	std::cout << "\"game.bin\" has been written" << std::endl;
		
	return 0;
}

