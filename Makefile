PATH_LIBFT = libft/
PATH_VM = vm/
PATH_ASM = asm/

all: 	
	make -C libft/
	make -C asm/
	make -C vm/

clean:
	make clean -C libft/
	make clean -C asm/
	make clean -C vm/

fclean: clean
	make fclean -C libft/
	make fclean -C asm/
	make fclean -C vm/

re:
	make re -C libft/
	make re -C asm/
	make re -C vm/
