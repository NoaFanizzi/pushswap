NAME		= push_swap

DIR			= mandatory
SRC_DIR		= $(DIR)/srcs
INC_DIR		= $(DIR)/includes
MOV_DIR		= Movements
STK_A_DIR	= Stack_A
STK_B_DIR	= Stack_B
UTILS_DIR	= utils

MOV_SRCS	= movements.c push.c reversed_rotate.c rotate.c swap.c
MOV_SRCS	:= $(addprefix $(MOV_DIR)/, $(MOV_SRCS))

STK_A_SRCS	= cost_a.c find_biggest_a.c find_lowest_a.c
STK_A_SRCS	:= $(addprefix $(STK_A_DIR)/, $(STK_A_SRCS))

STK_B_SRCS	= cost_b.c find_biggest_b.c find_lowest_b.c
STK_B_SRCS	:= $(addprefix $(STK_B_DIR)/, $(STK_B_SRCS))

UTILS_SRCS	= index.c mem_allocation.c parsing.c set.c
UTILS_SRCS	:= $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))

SRCS		= main.c push_swap.c sort.c \
			  $(MOV_SRCS) $(STK_A_SRCS) $(STK_B_SRCS) $(UTILS_SRCS)
SRCS		:= $(addprefix $(SRC_DIR)/, $(SRCS))


vpath %.c $(SRC_DIR) $(SRC_DIR)/$(MOV_DIR) $(SRC_DIR)/$(STK_A_DIR) $(SRC_DIR)/$(STK_B_DIR) $(SRC_DIR)/$(UTILS_DIR)
vpath %.h $(INC_DIR)