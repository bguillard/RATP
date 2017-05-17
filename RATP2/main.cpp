//
//  main.cpp
//  RATP2
//
//  Created by Benoît Guillard on 17/05/2017.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "mission.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<Mission*> missions;
    
    /*
    for(int i = 0; i<10; i++)
    {
        string* param = new string[7];
        param[0] = "a";
        param[1] = "b";
        param[2] = "c";
        param[3] = "d";
        param[4] = "e";
        param[5] = "f";
        param[6] = "g";
        
        missions.push_back(new Mission(param));
    }
    
    for(int i = 0; i<10; i++)
    {
        cout << missions[i]->station << endl;
    }
     */
    
    // use full path instead and check manully whether the file is there or not
    // to do it : drag the text file into a terminal window for example : full path will appear
    ifstream file("/Users/benoitguillard/Documents/X/INF442/PI/rer-b-sample.data");
    string* lines = new string[7];
    int compt = 0;
   
    if(file.fail())
        cout << "Opening file failed!" << endl;
    else{
        while(getline(file, lines[compt]))
        {
            compt ++;
            if(compt > 6)
            {
                missions.push_back(new Mission(lines));
                compt = 0;
            }
        }
    }
    
    cout << "Fichier lu" << endl;
    
    for(int i = 0; i < missions.size(); i++)
    {
        cout << missions[i]->station << endl;
    }
    return 0;
}
