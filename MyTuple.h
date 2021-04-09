#pragma once
template<typename... Ts> class MyTuple; // forward declaration do MyTuple


/* SAMPLE FROM WREIN
template <std::size_t Index, typename... Elements>
struct MyTupleImpl;

template <std::size_t Index, typename Head, typename... Rest>
struct MyTupleImpl<Index, Head, Rest...> : MyTupleImpl<Index + 1, Rest...> {
  // just constructors
};

template <std::size_t Index, typename T>
struct MyTupleImpl<Index, T> {
  // just constructors
};

template <typename... Ts>
struct MyTuple : MyTupleImpl<0, Ts...> { ... }
*/

/*
nope
I mean, you could, but there's no reason to
the Index is not "size" or anything, it's just a number so that you can actually implement the member funcs in MyTuple
MyTuple<int, char> is derived from MyTupleImpl<0, int, char> is derived from MyTupleImpl<1, char> is derived from MyTupleImpl<2>
and then get<0>(MyTuple<int, char>{}) returns an int, and get<1>(MyTuple<int, char>{}) returns a char
My lazy outline did have a mistake, since I assumed you always wanted non-empty tuples, but you can just change the base case from struct MyTupleImpl<Index, T> to struct MyTupleImpl<Index>, same deal
Any, as I mentioned before, I much prefer an implementation that uses variadic bases
wreien28/12/2020
// probably specialised for EBO but w/e
template <std::size_t Index, typename T>
struct leaf {
  T value;
  // etc.
};

template <typename Indexes, typename... Ts>
struct tuple_impl;

template <std::size_t... Indexes, typename... Ts>
struct tuple_impl<std::index_sequence<Indexes...>, Ts...> : leaf<Indexes, Ts>... {
  // constructors etc.
};

template <typename... Ts>
class tuple : tuple_impl<std::index_sequence_for<Ts...>, Ts...> {
public:
  // constructors, member functions, etc.
};
  as a super quick-and-nasty example
  https://discord.com/channels/331718482485837825/331718580070645760/792914219095818240

*/



template<> class MyTuple<>  // MyTuple<> a; vai para aqui
{
public:

	//static constexpr int size = 0;
};
template<typename T, typename... Ts> // definição recursiva
class MyTuple<T, Ts...> : public MyTuple<Ts...>
{
public:
	T value;
};





/*
	Para obter o valor do T em qualquer nivel de profundidade
	preciso de definir um método que mo obtenha
*/

//struct auxiliar
template<std::size_t index, typename Tuple> // index = nível de profundidade ; Tuple = Tuple que recebemos
struct AUXMyTuple;


template<typename T, typename... Ts>
struct AUXMyTuple<0, MyTuple<T, Ts...> >
{
	using type_t = T; // o valor do nível de profundidade
	using TupleType_t = MyTuple<T, Ts... >;
};

template<std::size_t index, typename T, typename... Ts>
struct AUXMyTuple<index, MyTuple<T, Ts...> > : public AUXMyTuple<index - 1, MyTuple<Ts...>>
{
	// chama AUXMyTuple<0> para o nivel de profundidade expecificado por index
};


// metodo que obtem uma referencia para o valor, num nivel de profundidade [index]
template<std::size_t index, typename... Ts>
typename AUXMyTuple<index, MyTuple<Ts...> >::type_t&
get(MyTuple<Ts...>& arg)
{
	using TupleType_t = typename AUXMyTuple<index, MyTuple<Ts...>>::TupleType_t;
	return static_cast<TupleType_t&>(arg).value;
}