#include<iostream>
#include<vector>

int addOverload(int var1, int var2)
{
	return var1 + var2;
}

float addOverload(float var1, float var2)
{
	return var1 + var2;
}

double addOverload(double var1, double var2)
{
	return var1 + var2;
}

short addOverload(short var1, short var2)
{
	return var1 + var2;
}

template <typename T>
T addOverloadTemplate(T var1, T var2)
{
	return var1 + var2;
}

template <typename FirstType, typename SecondType>
auto add(FirstType a, SecondType b) -> decltype(a + b) {
	return a + b;
}

template <typename T>
auto variadicAdd(T a, T b)
{
	return a + b;
}

template <typename T>
auto variadicAdd(T a)
{
	return a;
}

template <typename T, typename ...Args>
auto variadicAdd(T a, T b, Args... args)
{
	return a + b + variadicFooAdd(args...);
}

template<typename ...Args> auto sum(Args ...args) 
{
	return (args + ...);
}

template<typename ...T> 
auto avg(T ...args)
{
	return ((args + ...)/sizeof...(args));
}

template <int64_t N> struct Factorial
{
	enum { val = Factorial<N - 1>::val * N };
};

template<>
struct Factorial<0>
{
	enum { val = 1 };
};

auto f = []<typename T>(std::vector<T> vec) { for (auto i : vec)	std::cout << ' ' << i << ' '; };

void foobar()
{

	std::tuple var{ 1,2 };
	std::tuple var2{ "A","B" };
	std::vector Vector{ 1,2,3,4,5,6,7 };//c++ 17

	//sum(1, 2, 3);
	std::cout << "\n" << sum(1, 2, 3, 4);
	std::cout << "\nAvg : " << avg(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	std::cout << "\nFactorial : " << Factorial<15>::val << "\n";


}

int main()
{
	foobar();
	return 0;
}

