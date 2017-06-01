//
//  train.hpp
//  RATP2
//
//  Created by Benoît Guillard on 01/06/2017.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

#ifndef train_hpp
#define train_hpp

#include <map>
#include <iostream>
#include "hour.cpp"

#include <stdio.h>

class Train_theorique{
    
    public :
    std::map<Hour, std::string> route;
    std::string missionID;
    Hour terminus;
    
    Train_theorique(std::map<Hour, std::string> route,std::string missionID,Hour terminus);
    
    bool compare_train(Train_theorique t1,Train_theorique t2);
};

#endif /* train_hpp */
