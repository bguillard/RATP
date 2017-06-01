//
//  hour.hpp
//  RATP2
//
//  Created by Benoît Guillard on 01/06/2017.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

#ifndef hour_hpp
#define hour_hpp

#include <stdio.h>
#include <string>
class Hour {
public:
    int heures;
    int minutes;
    
    Hour(const std::string date);
    
    void print(std::ostream &flux) const;
};

bool operator==(Hour const& a, Hour const& b);

bool operator<=(Hour const& a, Hour const& b);
bool operator>=(Hour const& a, Hour const& b);
bool operator<(Hour const& a, Hour const& b);
bool operator>(Hour const& a, Hour const& b);

Hour operator+(Hour const& a, Hour const& b);
Hour operator-(Hour const& a, Hour const& b);

std::ostream& operator<<( std::ostream &flux, Hour const& h );

#endif /* hour_hpp */
