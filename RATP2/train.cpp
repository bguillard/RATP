//
//  train.cpp
//  RATP2
//
//  Created by Benoît Guillard on 01/06/2017.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

#include "train.hpp"

Train_theorique::Train_theorique(std::map<Hour,std::string> n_route, std::string n_missionID, Hour n_terminus){
    route = n_route;
    missionID = n_missionID;
    terminus = n_terminus;
}

bool compare_train(Train_theorique t1, Train_theorique t2){
    if (t1.missionID == t2.missionID && t1.terminus == t2.terminus){return true;}
    else{return false;}
}
