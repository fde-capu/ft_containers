#Usage:

make [check='option + option...'] [command]

options:

_GENERAL_ | Less extensive check of everything to fit memory.
_SIMPLE_  | = _FT_ + _GENERAL_

_PAIR_        \
_IS_INTEGRAL_ | All these together:
_ENABLE_IF_   | _EXTRAS_
_ITERATOR_    |
_EQ_LEXICO_   /

_VECTOR_ \ These two together:
_STACK_  / _VECSTACK_

_MAP_A_ \ Can be run individually
_MAP_B_ | (due to memory limitation).
_MAP_C_ / Or _MAP_ for all.

_SET_ 

_STRESS_ | Routine for timings. Do not run with Valgrind or -fsanitize.
_LEAKS_  | Executes complex tasks with -fsanitize on. Do not run on valgrind.

_ALL_ | Intended to run all at once, VM kills clang++ error 317 (out of memory).

* When changing the option between trials, make fclean is needed. *

commands:

all - default, builds ft_containers and stl_containers. 
ft
stl
ftt - compile and run.
stlt - compile and run.
t - compile and run both.
diff - compile both, run, get diff (timings).
