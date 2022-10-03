#pragma once
#include <string>

#define StringNumericCheck(x) static_assert(std::is_same<x, std::string>::value || std::is_same<x, double>::value || std::is_same<x, int>::value, "Only text and numeric property columns can be created" );

// can be either text or numeric so I'm going to make this a template class but to restrict to string/int/double for now with possible expansion to other data types
template<typename T>
class PropertyColumnBase
{

public:
	PropertyColumnBase<T>() {
		// check that the type for the property column is correct.
		StringNumericCheck(T);
	};
	virtual ~PropertyColumnBase();

private:
	template T

};

