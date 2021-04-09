#pragma once

template<size_t n>
struct fibonacci;


template<size_t n>
struct fibonacci
{
	static constexpr int value = fibonacci<n - 1>::value + fibonacci<n - 2>::value;
};

//template<> constexpr int fibonacci<0>::result = 1;
//template<> constexpr int fibonacci<1>::result = 1;

template<>
struct fibonacci<0>
{
	static constexpr int value = 0;
};
template<>
struct fibonacci<1>
{
	static constexpr int value = 1;
};