//
//  hour.cpp
//  RATP2
//
//  Created by Benoît Guillard on 01/06/2017.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

#include "hour.hpp"
#include <iostream>

Hour::Hour(const std::string date){
    if(date.size() == 12)
    {
        heures = stoi(date.substr(8,2));
        minutes = stoi(date.substr(10,2));
    }
    else
        std::cerr << "Format de date non supporte" << std::endl;
}

std::ostream &operator<<( std::ostream &flux, Hour const& a)
{
    a.print(flux) ;
    return flux;
}

void Hour::print(std::ostream &flux) const
{
    if(heures < 10)
        flux << "0";
    flux << heures << "h";
    if(minutes < 10)
        flux << "0";
    flux<< minutes << "m";
}

bool Hour::egal(Hour const& b) const
{
    return (heures == b.heures && minutes == b.minutes);
}

bool operator==(Hour const& a, Hour const& b)
{
    return a.egal(b);
}

bool operator!=(Hour const& a, Hour const& b)
{
    return !(a.egal(b));
}

