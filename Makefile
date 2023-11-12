SRCS :=	ft_printf.c ft_itoh.c ft_itohi.c ft_uitoa.c ft_helper0.c ft_helper1.c ft_helper2.c 
OBJS := $(SRCS:.c=.o)
BONUS_SRCS := 
BONUS_OBJS := $(BONUS_SRCS:.c=.o)
CC = cc
AR = ar
C_FLAGS = -Wall -Wextra -Werror# -O3 -g -fsanitize=address
LD_FLAGS := -L./libft -lft
NAME = libftprintf.a
.PHONY: all clean fclean re

all: $(NAME)


clean:
	rm -rf $(OBJS)  $(BONUS_OBJS)
	cd libft && make fclean

fclean: clean
	rm -rf $(NAME)

re: fclean all


%.o: %.c
	$(CC) $(C_FLAGS) -c -o $@ $<

$(NAME): $(OBJS) libft/libft.a  
	$(AR) rc $@ $(OBJS) libft/*.o

libft/libft.a:
	cd libft && make fclean all