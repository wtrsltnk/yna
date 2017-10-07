#ifndef TYPE_H
#define TYPE_H

#include <typeinfo>

class Type : public std::type_info
{
public:
    template <class T>
    Type() : type_info(typeid(T).name()) { }
    Type(const char* name) : type_info(name) { }
    Type(const type_info& t) : type_info(t.name()) { }
    Type(const Type& t) : type_info(t.name()) { }

    bool operator < (const type_info& t) const { return  this->hash_code() < t.hash_code(); }
};

#endif // TYPE_H
