# ft_containers Tests

## How this test works.
The tests behaviour depends on the result of a static variable `ft::Tester::kind`.

This variable is set by a MACRO defined on compile or according to the number of arguments (argc).

./ft_containers is compiled with `ft::Tester::kind = KIND_FT`
./std_containers is compiled with `ft::Tester::kind = KIND_STD`
Both binaries have `ft::Tester::kind` overriden to `KIND_COMPARE` if first argument is "compare": `./ft_containers compare`.

Some tester class functions will behave differently according to this kind:
`tester.printClock()` will do nothing unless `kind == KIND_COMPARE`.
`ft::Tester::Return()` will print the output of the return (it's argument) only if `kind != KIND_COMPARE`.

`tester.run()` will run the appropriate functions, depending wether `kind == KIND_COMPARE | KIND_FT | KIND_STD`.

## Running this test.
> Run `make`

> 

## Creating a Test.

### Regular Test
> A test consists of two functions: a caller function and one function for each individual test.
> As each individual test are usually a templated function, they should be implemented in the header file.
> In order to use this general test format, the individual test function must be of the following format:
`std::string function_name(void)`

#### Example of caller function:
vector_constructors.cpp
```c++
void test_vector_copy_constructor(void)
{
	ft::Tester tester;

	tester.printName("Copy Constructor");
	tester.add(
		vector_copy_constructor1< ft::vector<int> >,
		vector_copy_constructor1< std::vector<int> >
	);
	tester.add(
		vector_copy_constructor1< ft::vector<float> >,
		vector_copy_constructor1< std::vector<float> >
	);
	tester.run();
}
```

#### Example of individual test:
vector_constructors.hpp
```c++
template <typename T>
std::string vector_copy_constructor1(void)
{
	T rng(10, 100);
	T v(rng);
	std::string s = vector_attributes<T>(v);
	
	return (ft::Tester::Return(s));
}
```

### Special test functions.
> In case the individual test functions have a non standard declaration, ie: must have arguments,
> the tests cannot be done by using the tester.run() function. In that case, it will have to be
> implemented manually:

> The main function to call a test must have 4 parts:
> 1. The title. `tester.printName("Default Constructor");
> 2. The comparison functions `tester.compare`, which will call the templated
> tester function for ft:: as first argument and, as second argument,
> for std:: or bool (in case the
> tested function does not exist on std:: or is c++11.);
> 3. The same functions called in compare, but for ft:: only.
> 4. The same functions called in compare, but for std:: only.
> * Parts three and four should not be added if function does not exist on std:: in c++98.

#### Example of special caller function:

```c++
void 	test_vector_nonmemberswap(void)
{
	ft::Tester tester;

	//1. The title.
	tester.printName("swap");

	//2. Comparison functions. Will only be executed if ft::tester::kind = KIND_COMPARE.
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_swap< ft::vector<int> >(ft::swap),
			vector_swap< std::vector<int> >(std::swap)
		);
	}
	std::cout << std::endl;
	
	//3. ft:: tests.
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_swap< ft::vector<int> >(ft::swap);
		tester.printClock("[ft ]");
	}
	
	//4. ft:: tests.
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_swap< std::vector<int> >(std::swap);
		tester.printClock("[std]");
	}
}
```

#### Example of Individual test function.

```c++
template <typename T>
std::string vector_swap(void (*swap)(T&, T&))
{
	T v1;
	T v2;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v1.push_back(i);
	for(int i = 5; i >= 0; i--)
		v2.push_back(i);
	swap(v1, v2);
	s = "v1: " + vector_attributes<T>(v1) + "\n";
	s += "v2: " + vector_attributes<T>(v2);
	return (ft::Tester::Return(s));
}
```
