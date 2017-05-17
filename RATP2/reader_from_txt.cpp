//
//  reader_from_txt.cpp
//  RATP2
//
//  Created by luc leflem on 5/17/17.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

#include "reader_from_txt.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int Text_to_Vector_of_str(string file_name) {
    // use full path instead and check manully whether the file is there or not
    // to do it : drag the text file into a terminal window for example : full path will appear
    
    std::ifstream file(file_name);
    std::string line;
    
    if(file.fail())
        cout << "Opening file failed!" << endl;
    else{
        while(std::getline(file, line))
        {
            cout << line;
        }
    }
}
