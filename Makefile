SRCS_FILES =		push_swap \
					merge	\
					create_stack \
					find_duplicate	\
					error \
					exit_program \
					ft_atoi_edited \
					solve_big	\
					rotate	\
					reverse_rotate	\
					push	\
					swap	\
					move	\
					move2	\
					cost	\
					init	\
					push_back	\
					sort_three	\
					is_sorted	\
					value	\
					target	\
					print	\
					print2	\
					sort_small	\

BONUS_FILES =		checker_bonus \
					checker_utils	\
					checker_utils2	\
					is_solution_valid	\
					merge	\
					create_stack \
					find_duplicate	\
					error \
					exit_program \
					ft_atoi_edited \
					solve_big	\
					rotate	\
					reverse_rotate	\
					push	\
					swap	\
					move	\
					move2	\
					cost	\
					init	\
					push_back	\
					sort_three	\
					is_sorted	\
					value	\
					target	\
					print	\
					print2	\
					sort_small	\

INCLUDES_FILES =	push_swap \

SOURCE_DIR =	./SOURCES/
INCLUDES_DIR =	./INCLUDES/
OBJS_DIR =		./OBJECTS/
LIBFT_DIR =		./SOURCES/libft/

SOURCES =	$(addprefix $(SOURCE_DIR), $(addsuffix .c, $(SRCS_FILES)))
SOURCES_B =	$(addprefix $(SOURCE_DIR), $(addsuffix .c, $(BONUS_FILES)))

INCLUDES =	$(addprefix $(INCLUDES_DIR), $(addsuffix .h, $(INCLUDES_FILES)))

OBJS_B =	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_FILES)))
OBJS =		$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))

NAME = push_swap

CC = cc

CC_FLAGS = -Wall -Wextra -Werror -g

$(OBJS_DIR)%.o : $(SOURCE_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@clang $(CC_FLAGS) -c $< -o $@

all: $(NAME)

lib :
		make -C $(LIBFT_DIR)

$(NAME) : lib $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft
	@echo "Push_swap compiled!"

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

bonus : lib $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o checker -L$(LIBFT_DIR) -lft

.PHONY: all lib clean fclean re
