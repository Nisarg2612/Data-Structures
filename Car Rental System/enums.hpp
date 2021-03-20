#ifndef enums_hpp
#define enums_hpp

#include <iostream>
#include <string>
using namespace std;

enum class Relation{
    LT,
    EQ,
    GT,
};

enum vehicleType{
    sedan,
    suv,
    exotic
};

inline istream& operator>> ( istream& in, vehicleType& t )
{
    int val;
    if ( in >> val ) {
        t = static_cast<vehicleType>(val);
    }
    return in;
}

#endif /* enums_hpp */