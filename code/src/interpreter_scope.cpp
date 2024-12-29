#include "interpreter_scope.hpp"

#include <stdexcept>
#include <string.h>

func_container InterpreterScope::funcs = {};

intpr::Value::Value(int64_t _i) { as.i = _i; }
intpr::Value::Value(uint64_t _ui) { as.ui = _ui; }
intpr::Value::Value(double _d) { as.d = _d; }
intpr::Value::Value(char* _s, unsigned int length)
{
	if (_s)
	{
		as.s = (char*)malloc((length + 1) * sizeof(char));
		if (!as.s)
			throw std::bad_alloc();

		strncpy(as.s, _s, length);
		as.s[length] = '\0';

		is_str_alloc = 1;
	}
	else
	{
		as.s = nullptr;
		is_str_alloc = 0;
	}
}

intpr::Value::Value(Array _a)
{
	as.a = _a;
	is_arr_alloc = 1;
}

intpr::Value::Value(Value const& _v)
{
	as.i = _v.as.i;
	as.ui = _v.as.ui;
	as.d = _v.as.d;
	as.s = _v.as.s;
	as.a = _v.as.a;
}

intpr::Value::~Value()
{
	
};