#ifndef CUSTOMEXCEPTIONS_H
#define CUSTOMEXCEPTIONS_H

#include <exception>
using namespace std;

class ErrorIgual: public exception{
    public:
    const char* what() const throw();
};

class NoPermiso: public exception{
public:
    const char* what() const throw();
};

#endif // CUSTOMEXCEPTIONS_H
