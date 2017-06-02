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
#include "train.hpp"

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
    
    /*
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
    
    set<Hour> horaires;
    
    for(int i = 0; i < missionsLozere.size(); i++)
    {
        horaires.insert(Hour(missionsLozere[i]->stationDate));
    }
    cout << horaires.size() << " missions differentes." << endl;
    
    for(auto m : horaires)
    {
        cout << m << endl;
    }
    
    return 0;
     
    */
    vector<Train_theorique *> trains_theoriques;
    
    for(int i = 0; i < missions.size(); i++)
    {
        std::string station = missions[i]->station;
        Hour next_entry = Hour(missions[i]->nextMissionStationDate);
        Hour terminus = Hour(missions[i]->nextMissionTerminusDate);
        std::string missionsId = missions[i]->nextMission;
        
        bool already_a_train = false;
        
        for(std::vector<Train_theorique*>::iterator it = trains_theoriques.begin() ; it < trains_theoriques.end() ; it++){
            // We suppose here that all trains are different
            if((*it)->terminus == terminus && (*it)->missionID == missionsId){ // We found a line corresponding to an already existing train
                (*it)->route.insert(std::pair<Hour,std::string>(next_entry, station));
                already_a_train = true;
            }
        }
        
        if(!already_a_train){
            std::map<Hour, std::string> new_route;
            new_route.insert(std::pair<Hour,std::string>(next_entry, station));
            Train_theorique* new_train = new Train_theorique(new_route,missionsId,terminus);
            trains_theoriques.push_back(new_train);
        }
    }
    
    
    // pour parcourir toutes les paires de la map
    for(std::vector<Train_theorique*>::iterator it=trains_theoriques.begin() ; it!=trains_theoriques.end() ; ++it)
    {
        std::cout<<"Voici les stations visitées par le train "<<(*it)->missionID<<" arrivant à son terminus à "<<(*it)->terminus<<":"<<std::endl;;
        
        
        std::map<Hour, std::string> route_empruntee = (*it)->route;
        
        for(std::map<Hour, std::string>::iterator itos = route_empruntee.begin() ; itos!=route_empruntee.end() ; ++itos){
            std::cout<<itos->second<<" à "<<itos->first<<std::endl;
        }
        
    }
    
    return 0;
}
