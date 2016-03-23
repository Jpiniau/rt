NAME = rtv1

FLAGS = -Wall -Werror -Wextra

INCLUDES = libft/includes

INCLUDES2 = minilibx_macos

LIBX = -L minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

SRC_PATH = ./src/

SRC_NAME = main.c\
		   get_info.c\
		   init_env.c\
		   init_cont.c\
		   gnlv.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = ./obj/

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all : lib $(NAME)

lib :
	@echo "creation de la libft"
	@make -C libft

$(NAME) : $(OBJ)
	@gcc $(FLAGS) -o $@ $^ -L libft/ -lft $(LIBX) -lm 
	@echo "creation de rt"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) -o $@ -c $< -I $(INCLUDES) -I $(INCLUDES2) -I include/.

clean :
	rm -fr $(OBJ_PATH)

fclean : clean
	rm -fr $(NAME)

re : fclean all
