

Well the function value_type() is not really a function with that name. Indeed, the definition of integral_constant looks like this:

template <class T, T v>
struct integral_constant {
    // ...
    typedef T value_type;
    constexpr operator value_type() const noexcept { return value; }
};
Notice that value_type is actually a typedef for the template parameter T (int, in OP's example). In addition there's a conversion operator that converts from integral_constant<T, v> to T. It's implicitly called like this

int i = one_o; // same as int i = 1;
To call it explicitly you need to use the operator keyword and the right type like this:

one_o.operator int();
which, thanks to the typedef member, is also equivalent to

one_o.operator one_t::value_type();
