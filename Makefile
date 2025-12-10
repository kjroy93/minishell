###########################################
#             VARIABLES                   #
###########################################

NAME	= minishell

SRC_DIR			= src
OBJ_DIR			= obj
LIBFT_DIR		= libft
PIPES_DIR		= pipes
INCLUDE_DIR		= include

LIBFT_INCLUDE	= $(LIBFT_DIR)/include
PIPES_INCLUDE	= $(PIPES_DIR)/include
LDFLAGS = -lreadline

SRC		= src/fsm/states/state_dquote.c	\
		src/fsm/states/state_end.c		\
		src/fsm/states/state_error.c	\
		src/fsm/states/state_pipe.c		\
		src/fsm/states/state_redirect.c	\
		src/fsm/states/state_squote.c	\
		src/fsm/states/state_start.c	\
		src/fsm/states/state_word.c 	\
		src/fsm/utils/fsm_utils.c		\
		src/fsm/utils/token_utils.c		\
		src/fsm/fsm.c					\
		main.c							
OBJ		= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3 -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE) -I$(PIPES_INCLUDE)

LIBFT	= $(LIBFT_DIR)/libft.a
PIPES	= $(PIPES_DIR)/pipes

###########################################
#                RULES
###########################################

all: $(LIBFT) $(PIPES) $(NAME)

$(LIBFT):
	@echo "⚙️ 📘 Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

$(PIPES):
	@echo "(|) 42: Compiling pipes..."
	@$(MAKE) -C $(PIPES_DIR) > /dev/null 2>&1

$(NAME): $(OBJ)
	@echo "🔧 Building minishell..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

###########################################
#               CLEANING
###########################################

clean:
	@echo "🧹 Removing object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@$(MAKE) -C $(PIPES_DIR) clean > /dev/null 2>&1

fclean: clean
	@echo "🧹 Removing executables..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@$(MAKE) -C $(PIPES_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re pipes
