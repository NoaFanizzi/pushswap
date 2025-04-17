NAME		= checker

DIR			= bonus
SRC_DIR		= $(DIR)/srcs
INC_DIR		= $(DIR)/includes

SRCS		= main_bonus.c index_bonus.c mem_allocation_bonus.c parsing_bonus.c \
			  push_bonus.c reversed_rotate_bonus.c rotate_bonus.c swap_bonus.c
SRCS		:= $(addprefix $(SRC_DIR)/, $(SRCS))

vpath %.c $(SRC_DIR)
vpath %.h $(INC_DIR)