#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

struct mWaypoint{
	unsigned char mBytes[3];
};

int main(int argc, char* argv[]){
	
	if((argc != 2) || !(fs::exists(fs::status(std::string(argv[1]))))){
		std::cout << "Usage: " << std::string(argv[0]) << " <waypoint file>" << std::endl;
		return 1;
	}
	
	std::string mWayPath = std::string(argv[1]);
	
	std::ifstream input( mWayPath, std::ios::in );
	
	std::vector<mWaypoint> mWaypoints;
	unsigned char mWayNum = 0;
	
	std::string nline;
    	std::string ntmp1;    
	std::string ntmp2;
		    
	int mx, my, mc;
    
    	while(!input.eof()){
		std::getline(input, nline);

		if(input.eof()){
			break;
		}
		
		mWayNum++;

		ntmp2 = nline;

		std::stringstream conwc(ntmp2); 

		int wordc = 0;
		
		bool bError = false;
		
		std::string cCom;

		while(conwc >> ntmp1){
			wordc++;
			if(wordc == 4){
				cCom = ntmp1;
			}			
		}       	
    		
    		if(wordc < 3){
    		
    			bError = true;
    			
    		} else if(wordc > 3){
    		
    			if(cCom.at(0) != '#'){
    				bError = true;
    			}
    		}
    		
		if(bError){
			std::cout << "Error in file: \"" <<  mWayPath << "\"\n" << "At line: " << (int)mWayNum << std::endl;		
			return 1;
		}

		std::stringstream convert(nline); 

		convert >> mx >> my >> mc;
		
		mWaypoint cWaypoint;
		
		mWaypoints.push_back(cWaypoint);

		mWaypoints[mWaypoints.size()-1].mBytes[0] = (unsigned char)mx;
		mWaypoints[mWaypoints.size()-1].mBytes[1] = (unsigned char)my;
		mWaypoints[mWaypoints.size()-1].mBytes[2] = (unsigned char)mc;				
	}    
            	
    	

	std::ofstream outfile(std::string(mWayPath + ".bin"), std::ios::binary );

	std::vector<unsigned char> obuffer;

	obuffer.push_back(mWayNum);
	
	for(int wi = 0; wi < mWayNum; wi++){
		obuffer.push_back(mWaypoints[wi].mBytes[0]);			
		obuffer.push_back(mWaypoints[wi].mBytes[1]);	
		obuffer.push_back(mWaypoints[wi].mBytes[2]);			
	}
	
	outfile.write((char*)obuffer.data(),obuffer.size());
	outfile.close();
		
	std::cout << "\"" <<  std::string(mWayPath + ".bin") << "\" has been written" << std::endl;		
		
	return 0;
}

