SRCS_FILES =		push_swap \
					create_stack \
					error \
					exit_program \
					ft_atoi_edited \

INCLUDES_FILES =	push_swap \

SOURCE_DIR =	./SOURCES/
INCLUDES_DIR =	./INCLUDES/
OBJS_DIR =		./OBJECTS/
LIBFT_DIR =		./SOURCES/libft/

SOURCES =	$(addprefix $(SOURCE_DIR), $(addsuffix .c, $(SRCS_FILES)))
INCLUDES =	$(addprefix $(INCLUDES_DIR), $(addsuffix .h, $(INCLUDES_FILES)))
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
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all lib clean fclean re
