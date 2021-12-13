#Usage:

make [check='option + option...'] [command]

options:

_GENERAL_ | Less extensive check of everything to fit memory.
_SIMPLE_  | = _FT_ + _GENERAL_ <- default

_FT_          \
_PAIR_        |
_IS_INTEGRAL_ | All these together:
_ENABLE_IF_   | _EXTRAS_
_ITERATOR_    |
_EQ_LEXICO_   /

_VECTOR_ \ These two together:
_STACK_  / _VECSTACK_

_MAP_A_ \
_MAP_B_ | Can be run individually
_MAP_C_ | (due to memory limitation).
_MAP_D_ | Or _MAP_ for all.
_MAP_E_ /

_SET_ 

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
