#ifndef TYPE_H
#define TYPE_H

#include <typeinfo>
#include <string>

class Type
{
    std::string _name;

public:
    Type(const char *name) : _name(name) {}
    Type(const type_info &t) : _name(t.name()) {}
    Type(const Type &t) : _name(t.name()) {}

    const char *name() const { return _name.c_str(); }
    bool operator<(const Type &t) const { return this->_name < t.name(); }
};

#endif // TYPE_H
