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
LIBFT_DBLST =	./SOURCES/double_chain_list/

SOURCES =	$(addprefix $(SOURCE_DIR), $(addsuffix .c, $(SRCS_FILES)))
INCLUDES =	$(addprefix $(INCLUDES_DIR), $(addsuffix .h, $(INCLUDES_FILES)))
OBJS =		$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))

NAME = push_swap

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : $(SOURCE_DIR)%.c
	mkdir -p $(OBJS_DIR)
	@clang $(CC_FLAGS) -c $< -o $@

all: $(NAME)

lib :
		make -C $(LIBFT_DIR)
		make -C $(LIBFT_DBLST)

$(NAME) : lib $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(LIBFT_DBLST) -lft_dblst
	@echo "Push_swap compiled!"

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBFT_DBLST)
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBFT_DBLST)

re: fclean all

.PHONY: all lib clean fclean re
