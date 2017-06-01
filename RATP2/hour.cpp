//
//  hour.cpp
//  RATP2
//
//  Created by Benoît Guillard on 01/06/2017.
//  Copyright © 2017 Benoît Guillard. All rights reserved.
//

#include "hour.hpp"
#include <iostream>

Hour::Hour(const std::string date)
{
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

void Hour::operator+=(const Hour &a)
{
    minutes += a.minutes;
    heures += minutes / 60;
    minutes %= 60;
    heures += a.heures%24;
}

Hour operator+(Hour const& a, Hour const& b)
{
    Hour ans(a);
    ans += b;
    return ans;
}

bool Hour::strictInf(Hour const& b) const
{
    return heures<b.heures || (heures==b.heures && minutes<b.minutes);
}

bool operator<(Hour const& a, Hour const& b)
{
    return a.strictInf(b);
}

bool operator>(Hour const& a, Hour const& b)
{
    return b<a;
}

bool operator<=(Hour const& a, Hour const& b)
{
    return a<b || a==b;
}

bool operator>=(Hour const& a, Hour const& b)
{
    return a>b || a==b;
}

void Hour::operator-=(const Hour &a)
{
    int ecartTotal = abs(minutes-a.minutes + 60*(heures-a.heures));
    minutes = ecartTotal%60;
    heures = ecartTotal/60;
}

Hour operator-(Hour const& a, Hour const& b)
{
    Hour ans(a);
    ans -= b;
    return ans;
}

