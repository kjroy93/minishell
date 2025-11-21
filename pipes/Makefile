###########################################
#             VARIABLES                   #
###########################################

NAME        = pipes

SRC_DIR         = src
SRC_BONUS_DIR   = src_bonus
OBJ_DIR         = obj

SRC =	$(SRC_DIR)/parse/get_argv.c 			\
		$(SRC_DIR)/parse/ft_new_split.c 		\
		$(SRC_DIR)/parse/stack.c 				\
		$(SRC_DIR)/utils/error_free.c 			\
		$(SRC_DIR)/execute/pater_son.c 			\
		$(SRC_DIR)/execute/redirect_functions.c \
		$(SRC_DIR)/execute/utils.c 				\
		$(SRC_BONUS_DIR)/childs_bonus.c 		\
		$(SRC_BONUS_DIR)/pater_son_bonus.c 		\
		$(SRC_BONUS_DIR)/status_bonus.c			\
		$(SRC_BONUS_DIR)/here_doc_bonus.c 		\
		pipex.c									\
		pipex_bonus.c							\
		main.c

OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g3 -Iinclude -I../libft/include

LIBFT   = ../libft/libft.a

###########################################
#                RULES                   
###########################################

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C ../libft

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
