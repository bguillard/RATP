//
//  main.cpp
//  RATP2
//
//  Created by Benoît Guillard on 17/05/2017.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

#include <iostream>
#include <vector>
#include "mission.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<Mission*> missions;
    
    for(int i = 0; i<10; i++)
    {
        missions.push_back(new Mission("a","b","c","d","e","f"));
    }
    
    for(int i = 0; i<10; i++)
    {
        cout << missions[i]->station << endl;
    }
     // coucou luc
    return 0;
}
