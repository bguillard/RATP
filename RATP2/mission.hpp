//
//  mission.hpp
//  RATP2
//
//  Created by Benoît Guillard on 17/05/2017.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

#ifndef mission_hpp
#define mission_hpp

#include <stdio.h>
#include <string>

using namespace std;


class Mission {
public:
    string serverDate;
    string station;
    string direction;
    string missionID;
    string stationDate;
    string terminusDate;
    
    Mission(const string& IserverDate, const string& Istation, const string& Idirection, const string& ImissionID, const string& IstationDate, const string& IterminusDate);
    
    Mission(const string* params);
    
    Mission(const std::vector<std::string>);
};


#endif /* mission_hpp */
