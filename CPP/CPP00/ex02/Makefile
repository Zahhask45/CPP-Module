_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m


_GREY		=	\e[1;30m
_RED		=	\e[1;31m
_GREEN		=	\e[1;32m
_YELLOW		=	\e[1;33m
_BLUE		=	\e[1;34m
_PURPLE		=	\e[1;35m
_CYAN		=	\e[1;36m
_WHITE		=	\e[1;37m



CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++98 -g -fsanitize=address

INCLUDE	=	-I ./inc/
			

SRC		=	tests.cpp \
			Account.cpp


OBJ_DIR	= ./obj/
OBJS	= $(SRC:.cpp=.o)
OBJ		= $(addprefix $(OBJ_DIR), $(OBJS))
NAME	= account

all: $(NAME)

$(NAME): $(OBJ)
	printf "\033[2K\r$(_GREEN) All files compiled into '$(OBJ_DIR)'. $(_END)\n"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(INCLUDE)
	printf "\033[2K\r$(_GREEN) Executable '$(NAME)' created. $(_END)\n"

$(OBJ):		| $(OBJ_DIR)


$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
				printf "\033[2K\r $(_YELLOW)Compiling $< $(_END) "
				$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	printf "\033[2K\r$(_RED) '"$(OBJ_DIR)"' has been deleted. $(_END)\n"

fclean: clean
	rm -rf $(NAME)
	printf "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)\n"

re: fclean all

.SILENT: