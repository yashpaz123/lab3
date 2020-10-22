OBJS := ex1.o ex2.o ex3.o ex4.o ex5.o
SOLOBJS := ex1_sol.o ex2_sol.o ex3_sol.o ex4_sol.o ex5_sol.o
CFLAGS := -Werror -c -Og -g -std=gnu99
SOLCFLAGS := -Werror -c -Og -std=gnu99

all : tester tester_sol

handin :
	tar -czvf lab3.tar.gz *.c *.h Makefile

%.o : %.c
	gcc $(CFLAGS) $*.c

tester : $(OBJS) tester.o
	gcc $^ -o $@

tester_sol : $(SOLOBJS) tester.o
	gcc $^ -o $@

clean :
	rm -f $(OBJS) tester tester_sol
