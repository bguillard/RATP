//
//  mission.cpp
//  RATP2
//
//  Created by Benoît Guillard on 17/05/2017.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

#include "mission.hpp"

Mission::Mission(const string& IserverDate, const string& Istation, const string& Idirection, const string& ImissionID, const string& IstationDate, const string& IterminusDate)
{
    serverDate = IserverDate;
    station = Istation;
    direction = Idirection;
    missionID = ImissionID;
    stationDate = IstationDate;
    terminusDate = IterminusDate;
}

Mission::Mission(const string* params)
{
    serverDate = params[1];
    station = params[2];
    direction = params[3];
    missionID = params[4];
    stationDate = params[5];
    terminusDate = params[6];
}
