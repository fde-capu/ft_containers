#Usage:

make [check='option + option...'] command

options:
_FT_
_PAIR_
_IS_INTEGRAL_
_ENABLE_IF_
_ITERATOR_
_EQ_LEXICO_
_VECTOR_
_STACK_
_MAP_A_
_MAP_B_
_MAP_C_
_MAP_D_
_MAP_E_
_SET_
_GENERAL_
_SIMPLE_ (= _FT_ + _GENERAL_) <- default

* When changing the option between trials, make fclean is needed. *

commands:
ft - compile
stl - compile
ftt - compiles and run
stlt - compile and run
diff - compile both, run, get diff (timings)
