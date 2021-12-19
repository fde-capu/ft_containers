# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 18:57:33 by fde-capu          #+#    #+#              #
#    Updated: 2021/12/19 18:57:36 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers
NAME_STD = std_containers

CC = clang++
CCFLAGS = -Wall -Werror -Wextra -g -std=c++98 -pedantic -fsanitize=address

SRC_DIR = ./tests
OBJ_DIR = ./build
FT_OBJ_DIR = ${OBJ_DIR}/ft
STD_OBJ_DIR = ${OBJ_DIR}/std

INC_DIR = ./bits

INCLUDES = ${INC_DIR}/ft_algobase.h \
			${INC_DIR}/ft_iterator_base_funcs.h \
			${INC_DIR}/ft_iterator_base_types.h \
			${INC_DIR}/ft_iterator.h \
			${INC_DIR}/ft_pair.h \
			${INC_DIR}/ft_tree.h \
			${INC_DIR}/ft_utility.h \
			${INC_DIR}/type_traits.h \
			map.hpp \
			stack.hpp \
			vector.hpp \
			set.hpp

SRCS = ${SRC_DIR}/main.cpp \
			${SRC_DIR}/ft_tree.cpp \
			${SRC_DIR}/Tester.cpp \
			${SRC_DIR}/utilities/test_utilities.cpp \
			${SRC_DIR}/utilities/test_reverseiterator.cpp \
			${SRC_DIR}/vector/vector_constructors.cpp \
			${SRC_DIR}/vector/vector_capacity.cpp \
			${SRC_DIR}/vector/vector_iterators.cpp \
			${SRC_DIR}/vector/vector_elementaccess.cpp \
			${SRC_DIR}/vector/vector_modifiers.cpp \
			${SRC_DIR}/vector/vector_overloads.cpp \
			${SRC_DIR}/vector/vector_tests.cpp \
			${SRC_DIR}/vector/vector_largetests.cpp \
			${SRC_DIR}/map/map_tests.cpp \
			${SRC_DIR}/map/map_constructors.cpp \
			${SRC_DIR}/map/map_iterators.cpp \
			${SRC_DIR}/map/map_modifiers.cpp \
			${SRC_DIR}/map/map_capacity.cpp \
			${SRC_DIR}/map/map_overloads.cpp \
			${SRC_DIR}/map/map_operations.cpp \
			${SRC_DIR}/map/map_observers.cpp \
			${SRC_DIR}/map/map_elementaccess.cpp \
			${SRC_DIR}/map/map_largetests.cpp \
			${SRC_DIR}/set/set_tests.cpp \
			${SRC_DIR}/set/set_constructors.cpp \
			${SRC_DIR}/set/set_iterators.cpp \
			${SRC_DIR}/set/set_modifiers.cpp \
			${SRC_DIR}/set/set_capacity.cpp \
			${SRC_DIR}/set/set_overloads.cpp \
			${SRC_DIR}/set/set_operations.cpp \
			${SRC_DIR}/set/set_observers.cpp \
			${SRC_DIR}/set/set_largetests.cpp \
			${SRC_DIR}/stack/stack_tests.cpp \
			${SRC_DIR}/stack/stack_functions.cpp \
			${SRC_DIR}/stack/stack_modifiers.cpp \
			${SRC_DIR}/stack/stack_overloads.cpp


FT_OBJS = $(patsubst ${SRC_DIR}/%.cpp, ${FT_OBJ_DIR}/%.o, ${SRCS})
FT_DEPENDS = $(patsubst %.o, %.d, ${FT_OBJS})
STD_OBJS = $(patsubst ${SRC_DIR}/%.cpp, ${STD_OBJ_DIR}/%.o, ${SRCS})
STD_DEPENDS = $(patsubst %.o, %.d, ${STD_OBJS})


all: title ${NAME} ${NAME_STD}

${NAME}: ${FT_OBJS} ${INCLUDES}
	@${CC} ${CCFLAGS} ${FT_OBJS} -DORIGINAL_STD=0 -I. -I ${INC_DIR} -o ${NAME}
	@echo "\033[92m./ft_containers is built. \033[0m"

${NAME_STD}: ${STD_OBJS} ${INCLUDES}
	@${CC} ${CCFLAGS} ${STD_OBJS} -DORIGINAL_STD=1 -I. -I ${INC_DIR} -o ${NAME_STD}
	@echo "\033[92m./std_containers is built. \033[0m"

${FT_OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp ${INC_DIR} ${INCLUDES}
	@mkdir -p $(dir $@)
	@echo -n "."
	@${CC} ${CCFLAGS} -MMD -c  $< -DORIGINAL_STD=0 -I. -I ${INC_DIR} -o $@

${STD_OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp ${INC_DIR} ${INCLUDES}
	@mkdir -p $(dir $@)
	@echo -n "."
	@${CC}  ${CCFLAGS} -MMD -c $< -DORIGINAL_STD=1 -I. -I ${INC_DIR} -o $@

clean:
	@rm -rf ${OBJ_DIR}

fclean: clean
	@rm -rf ./${NAME}
	@rm -rf ./${NAME_STD}

re: fclean all

test: compare diff time

LARGE_TESTS = 1000000

compare: all
	./ft_containers compare all ${LARGE_TESTS}

diff: all
	@echo "\033[92mDifference between std:: and ft:: tests: \033[0m"
	@/bin/bash -c "diff <(./ft_containers) <(./std_containers)" || true

FORMAT = "%e elapsed. %U user. %S system. %P CPU."
time: all
	@echo "\033[92mTime difference between std:: and ft:: tests: \033[0m"
	@echo "\033[93m./ft_containers \033[0m"
	@time -f ${FORMAT} ./ft_containers all ${LARGE_TESTS} > /dev/null
	@echo "\033[93m./std_containers \033[0m"
	@time -f ${FORMAT} ./std_containers all ${LARGE_TESTS} > /dev/null

time_mac: all
	@echo "\033[92mTime difference between std:: and ft:: tests: \033[0m"
	@echo "\033[93m./ft_containers \033[0m"
	@/bin/bash -c "time ./ft_containers all ${LARGE_TESTS} > /dev/null"
	@echo "\033[93m./std_containers \033[0m"
	@/bin/bash -c "time ./std_containers all ${LARGE_TESTS} > /dev/null"
	
title:
	@echo "\033[0m\033[38;2;123;145;255m _         _  _  _"
	@echo "\033[38;2;87;115;255m<_> _ _ _ <_>| || | ___ ._ _  ___"
	@echo "\033[38;2;207;59;255m| || | | || || || |/ ._>| ' |<_-<"
	@echo "\033[38;2;255;135;255m|_||__/_/ |_||_||_|\___.|_|_|/__/\033[0m\n"
	@echo "\033[37;1m    * * * ft_containers * * *\033[0m\n"

-include $(STD_DEPENDS) $(FT_DEPENDS)
