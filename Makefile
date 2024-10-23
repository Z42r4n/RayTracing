
NAME	= rt
CXX 	= c++ --std=c++17
OBJ		= main.o
RM		= rm -rf

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -Lmlx -lmlx  -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.cpp
	$(CXX) -Wall -Wextra -Werror -I mlx -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clear
	$(RM) $(NAME)