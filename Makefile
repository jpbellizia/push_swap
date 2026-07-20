NAME        := push_swap

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
MAKEFLAGS   += --no-print-directory

# ---------------------------------------------------------------------------- #
#   Paths                                                                      #
# ---------------------------------------------------------------------------- #

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

INC_DIR     := includes
SRC_DIR     := srcs
OBJ_DIR     := obj

INCLUDES    := -I $(INC_DIR) -I $(LIBFT_DIR)

# ---------------------------------------------------------------------------- #
#   Sources (mandatory)                                                        #
# ---------------------------------------------------------------------------- #

SRCS := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parsing/parse_args.c \
	$(SRC_DIR)/parsing/parse_flags.c \
	$(SRC_DIR)/parsing/validate.c \
	$(SRC_DIR)/stack/stack_init.c \
	$(SRC_DIR)/stack/stack_utils.c \
	$(SRC_DIR)/stack/ranks.c \
	$(SRC_DIR)/ops/ops_swap.c \
	$(SRC_DIR)/ops/ops_push.c \
	$(SRC_DIR)/ops/ops_rotate.c \
	$(SRC_DIR)/ops/ops_reverse_rotate.c \
	$(SRC_DIR)/ops/ops_exec.c \
	$(SRC_DIR)/metrics/disorder.c \
	$(SRC_DIR)/metrics/bench.c \
	$(SRC_DIR)/strategies/sort_small.c \
	$(SRC_DIR)/strategies/sort_simple.c \
	$(SRC_DIR)/strategies/sort_medium.c \
	$(SRC_DIR)/strategies/sort_complex.c \
	$(SRC_DIR)/strategies/sort_adaptive.c

# ---------------------------------------------------------------------------- #
#   Objects                                                                    #
# ---------------------------------------------------------------------------- #

OBJS         := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_NO_MAIN := $(filter-out $(OBJ_DIR)/main.o,$(OBJS))

HEADERS      := $(INC_DIR)/push_swap.h

# ---------------------------------------------------------------------------- #
#   Rules                                                                      #
# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@if [ ! -f $(LIBFT_DIR)/Makefile ]; then \
		echo "Error: libft not found. Copy your libft into ./$(LIBFT_DIR)/"; \
		exit 1; \
	fi
	@$(MAKE) -C $(LIBFT_DIR)

# ---------------------------------------------------------------------------- #
#   Cleaning                                                                   #
# ---------------------------------------------------------------------------- #

clean:
	rm -rf $(OBJ_DIR)
	@if [ -f $(LIBFT_DIR)/Makefile ]; then $(MAKE) -C $(LIBFT_DIR) clean; fi

fclean: clean
	rm -f $(NAME)
	@if [ -f $(LIBFT_DIR)/Makefile ]; then $(MAKE) -C $(LIBFT_DIR) fclean; fi

re: fclean all

# ---------------------------------------------------------------------------- #
#   Extras (not required by the subject, safe to keep)                         #
# ---------------------------------------------------------------------------- #

norm:
	norminette $(SRC_DIR) $(INC_DIR)

.PHONY: all clean fclean re norm