
NAME	= rt
CXX 	= c++ --std=c++17
OBJ		= main.o
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -Llibs/mlx -lmlx  -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.cpp
	$(CXX) -Wall -Wextra -Werror -I libs/mlx -I incs -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re