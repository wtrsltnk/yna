
#ifndef PROPERTY_H
#define PROPERTY_H

#include <ostream>

template<class TProperty>
class property
{
    TProperty _value;
public:
    property() { }
    property(TProperty v) : _value(v) { }
    property(property<TProperty> const & other) : _value(other._value) { }

    property<TProperty> & operator = (property<TProperty> const& other)
    {
        _value = other._value;
        return *this;
    }

    operator TProperty () { return _value; }
    TProperty const& operator -> () { return _value; }

    TProperty const& get() const { return _value; }
};

template<class T>
std::ostream& operator << (std::ostream& os, const property<T>& f)
{
    os << f.get();
    return os;
}

template<class TProperty>
class get_property
{
    TProperty const & _value;
public:
    get_property(TProperty const& v) : _value(v) { }

    operator TProperty const & () { return _value; }

    TProperty const& get() const { return _value; }
};

#include <functional>

template<class TProperty>
class getref_property
{
    std::function<TProperty const&()> _get;
public:
    getref_property(std::function<TProperty const&()> get) : _get(get) { }

    operator TProperty const & () { return get(); }

    TProperty const& get() const { return get(); }
};

template<class TProperty>
class getcopy_property
{
    std::function<TProperty()> _get;
public:
    getcopy_property(std::function<TProperty()> get) : _get(get) { }

    operator TProperty () { return get(); }

    TProperty get() const { return get(); }
};

#endif // PROPERTY_H
