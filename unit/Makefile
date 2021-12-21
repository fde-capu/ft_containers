# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 12:00:02 by fde-capu          #+#    #+#              #
#    Updated: 2021/12/21 20:51:36 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This file is not being used on the project, but was kept in an attempt to
# have a stand-alone tester.

USER_OUT = ft_containers
USER_STL = stl_containers

SRCS	=	Chronometer.cpp

all:	unit
unit:
	@cp ../Makefile ../unit_Makefile
	@sed -i -e "s/[[:alnum:]|\/|_]*main.cp*/unit\/unit_main.cpp unit\/Chronometer.cpp unit\/check_stress.cpp/g" ../unit_Makefile
	@cd .. && \
		make -f ./unit_Makefile && \
		make -f ./unit_Makefile stl && \
		./$(USER_OUT) 42 && \
		./$(USER_STL) 42
clean:
	@cd .. && make -f ./unit_Makefile clean
fclean:
	@cd .. && make -f ./unit_Makefile fclean
	@-rm -f ../unit_Makefile
re:
	@cd .. && make -f ./unit_Makefile re
my:
	@cd .. && \
	make && make stl && \
	echo "\n\n::::::::::::: STL Test ::::\n" && \
	./$(USER_STL) 42 && \
	echo "\n\n::::::::::::: FT Test :::::\n" && \
	./$(USER_OUT) 42 && \
	echo "Thanks!"
