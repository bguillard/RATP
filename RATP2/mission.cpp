//
//  mission.cpp
//  RATP2
//
//  Created by Benoît Guillard on 17/05/2017.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

/*
 Structure d'une ligne de donnée :
 The time of request, the name of station, the mission code of the train, the estimated arrival time (just like the estimated arrival time that we see on the information screen at station), if the train will stop at this station, the message, the code of the next theoretical mission, the theoretical arrival time of the next theoretical mission at this station, the theoretical arrival time of the next theoretical mission at the end of the line
 */

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
    nextMissionTerminusDate = vec[8].substr(0,12);
}
