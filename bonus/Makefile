CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -Ift_printf

OBJDIR = build

NAME = push_swap
NAME_BONUS = checker

SRCS := parsing/bench.c \
	algo/disorder.c \
	main.c \
	opps/opps_push.c \
	opps/opps_rev.c \
	opps/opps_rot.c \
	opps/opps_swap.c \
	parsing/parser.c \
	parsing/parsing_index.c \
 	algo/push_swap.c \
 	algo/simple_sort.c \
 	utils/split.c \
 	utils/utils_algo.c \
 	utils/utils_flags.c \
 	utils/utils_init_data.c \
 	utils/utils_node.c \
 	utils/utils_parsing.c \
 	utils/utils_parsing2.c \
 	utils/utils_str.c \
 	ft_printf/ft_printf.c \
 	ft_printf/ft_types.c

# This is the list of files used by both normal and bonus builds
COMMON_SRCS := parsing/bench.c \
	algo/disorder.c \
 	parsing/parser.c \
 	algo/push_swap.c \
 	algo/simple_sort.c \
 	utils/split.c \
 	utils/utils_algo.c \
 	utils/utils_flags.c \
 	utils/utils_init_data.c \
 	utils/utils_node.c \
 	utils/utils_parsing.c \
 	utils/utils_parsing2.c \
 	utils/utils_str.c \
 	ft_printf/ft_printf.c \
 	ft_printf/ft_types.c

BONUS_ONLY := bonus/checker.c \
	bonus/parsing_index.c \
	bonus/data_init.c \
	bonus/parse_input_bonus.c \
	bonus/opps/opps_bonus0.c \
	bonus/opps/opps_bonus1.c \
	bonus/opps/opps_bonus2.c \
	bonus/GNL/get_next_line.c \
	bonus/GNL/get_next_line_utils.c \


SRCS_MAIN := $(SRCS)
SRCS_BONUS := $(COMMON_SRCS) $(BONUS_ONLY)

OBJ := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS_MAIN))
OBJ_BONUS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS_BONUS))

DEP := $(OBJ:.o=.d)
DEP_BONUS := $(OBJ_BONUS:.o=.d)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	rm -f *.o *.d utils/*.o utils/*.d

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEP)
-include $(DEP_BONUS)
