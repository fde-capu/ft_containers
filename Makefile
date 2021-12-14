# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 11:41:00 by fde-capu          #+#    #+#              #
#    Updated: 2021/12/14 11:25:29 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_containers
NAMESTL	=	stl_containers
SEED	=	42
check	=	'_EQ_LEXICO_'

SRCS	=	\
			src/ft_tree.cpp main.cpp \
			unit/unit_main.cpp \
			unit/Chronometer.cpp unit/ft_main.cpp

HEAD	=	Makefile \
			stack.hpp \
			vector.hpp \
			map.hpp \
			set.hpp \
			bits/ft_pair.h \
			bits/ft_tree.h \
			bits/ft_iterator_base_types.h \
			bits/type_traits.h \
			bits/ft_utility.h \
			bits/ft_iterator_base_funcs.h \
			bits/ft_iterator.h \
			bits/ft_algobase.h \
			unit/check_vector.h unit/check_iterator.h \
			unit/check_pair.h unit/check_is_integral.h \
			unit/check_enable_if.h unit/check_helpers.h \
			unit/check_stack.h unit/check_map.h \
			unit/check_set.h unit/check_eq_lexico.h \
			unit/unit_main.h unit/Chronometer.hpp

SHELL	=	/bin/sh
CCFLAGS	=	-Wall -Werror -Wextra -g
CC98	=	clang++ $(CCFLAGS) -std=c++98 -DSECTION=$(check)
CC11	=	clang++ $(CCFLAGS) -DSECTION=$(check)
OBJS	=	$(SRCS:.cpp=.o)
OBJSSTL	=	$(SRCS:.cpp=.o_stl)
VAL		=	valgrind
VALFLAG	=	--tool=memcheck \
			--leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--show-reachable=yes
DIFFWID =	200
LINE	=	@echo "\n\n***************************************************\n\n";

all:		$(NAME) $(NAMESTL)

ft:			$(NAME)
$(NAME):	$(OBJS)
	$(LINE)
	$(CC98) $(OBJS) -o $(NAME)
$(OBJS):	%.o : %.cpp $(HEAD)
	$(LINE)
	$(CC98) -o $@ -c $<

stl:		$(NAMESTL)
$(NAMESTL):	$(OBJSSTL)
	$(LINE)
	$(CC11) $(OBJSSTL) -o $(NAMESTL)
$(OBJSSTL):	%.o_stl : %.cpp $(HEAD)
	$(LINE)
	$(CC11) -o $@ -c $<

clean:
	-rm -f $(OBJS)
	-rm -f $(OBJSSTL)
	-rm -f timings_*
	-rm -f *.o
fclean:		clean
	-rm -f $(NAME)
	-rm -f $(NAMESTL)
re:			fclean all

ftt:		ft
	@echo "\n::::::";
	@echo "::::::::::::: FT";
	@echo ":::::::::::::::::::::::::::::::::::::::::::";
	./$(NAME) $(SEED)
ftv:		ft
	$(VAL) ./$(NAME) $(SEED)
ftvf:		ft
	$(VAL) $(VALFLAG) ./$(NAME) $(SEED)

stlt:		stl
	@echo "\n::::::";
	@echo "::::::::::::: STL";
	@echo ":::::::::::::::::::::::::::::::::::::::::::";
	./$(NAMESTL) $(SEED)
stlv:		stl
	$(VAL) ./$(NAMESTL) $(SEED)
stlvf:		stl
	$(VAL) $(VALFLAG) ./$(NAMESTL) $(SEED)

t:			stl ft stlt ftt
rt:			re t

diff:		all
	@-rm -f timings_*
	@./$(NAMESTL) $(SEED) >> timings_stl.txt
	@./$(NAME) $(SEED) >> timings_ft.txt
	@-diff -y --suppress-common-lines -W $(DIFFWID) timings_stl.txt timings_ft.txt
	@echo "(diff is supposed to return error in case of difference)";
d:			diff
