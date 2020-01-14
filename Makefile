# SOURCES 

SRC := main.c image.c julia.c mandelbrot.c debug.c

# PATH GLOBAL

SRC_PATH := src
OBJ_PATH := obj
HEADER_PATH := inc

# OBJECTS AND DEPENDENCY

OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)
DEP = $(OBJ:%.o=%.d)
INCLUDE := -I$(HEADER_PATH) 

# GLOBAL

CC = gcc
CFLAGS = #-Wall -Wextra -Werror 
FLAGS := -lmlx -framework OpenGL -framework AppKit
NAME = fractol

# UTILS
ECHO= echo -e

# RULES

.PHONY: all
all: 
	@printf "\e[92mCompilation's flags: \e[36m$(CFLAGS)\n"
	@printf "\e[92mGenerating objects :\e[0m\n"
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@printf "\e[34mGenerated : \e[5;36m$(NAME)\e[0m\n"
	@$(CC) $(CFLAGS) $(INCLUDE) $(FLAGS) $^ -o $@

-include $(DEP)
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -c $< -o $@
	@printf "\e[1;31m  >>  \e[4;34m$@\e[0m\n"

.PHONY: clean
clean:
	@printf "\e[1;31mObject's removed\e[0m\n"
	@$(RM) -r $(OBJ_PATH)

.PHONY: fclean
fclean:
	@printf "\e[1;31m$(NAME) removed\e[0m\n"
	@$(MAKE) clean 2> /dev/null
	@$(RM) $(NAME)

.PHONY: re
re:
	@$(MAKE) fclean 2> /dev/null
	@$(MAKE) 
