//
//  mission.cpp
//  RATP2
//
//  Created by Benoît Guillard on 17/05/2017.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

#include "mission.hpp"

Mission::Mission(vector<string> vec){
    serverDate = vec[0];
    station = vec[1];
    missionID = vec[2];
    stationDate = vec[3];
    stop = vec[4];
    stationMessage = vec[5];
    nextMission = vec[6];
    nextMissionStationDate = vec[7];
    nextMissionTerminusDate = vec[8];
}
