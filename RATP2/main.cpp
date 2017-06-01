//
//  main.cpp
//  RATP2
//
//  Created by Benoît Guillard on 17/05/2017.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include "mission.hpp"
#include "hour.hpp"

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
    ifstream file("/Users/benoitguillard/Documents/X/INF442/PI/log_20170520044135_RB-A.txt");
    std::string lines;

    
    
    if(file.fail())
        cout << "Opening file failed!" << endl;
    else{
        while(getline(file, lines))
        {
            std::stringstream ss(lines);
            vector<string> result;
            
            while( ss.good() )
            {
                string substr;
                getline( ss, substr, ',' );
                result.push_back( substr );
            }
            
            if(result.size() == 9)
                missions.push_back(new Mission::Mission(result));
        }
    }
    
    cout << "Fichier lu :" << endl;
    cout << missions.size() << " missions chargees." << endl;
    
    cout << "Tri concernant les arrêts de lozère :" << endl;
    vector<Mission*> missionsLozere;

    
    for(int i = 0; i < missions.size(); i++)
    {
        if(missions[i]->station == "Lozere")
        {
            missionsLozere.push_back(missions[i]);
        }
    }
    cout << missionsLozere.size() << " missions passant par Lozere trouvees." << endl;
    
    set<string> horaires;
    
    for(int i = 0; i < missionsLozere.size(); i++)
    {
        horaires.insert(missionsLozere[i]->stationDate);
    }
    cout << horaires.size() << " missions differentes." << endl;
    
    for(auto m : horaires)
    {
        Hour h(m);
        cout << h << endl;
    }
    
    return 0;
}
