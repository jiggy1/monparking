# CC=gcc

# executer: compiler
# 	./main
	
# compiler: categorie_c.c categorie_b.c categorie_a.c main.c
# 	$(CC) categorie_c.c categorie_b.c categorie_a.c main.c -o main -lmysqlclient -lm



executer: main.o categorie_c.o categorie_b.o categorie_a.o
	gcc -o executer main.o categorie_c.o categorie_b.o categorie_a.o -lmysqlclient -lm


categorie_a.o : categorie_a.o
	gcc -c categorie_a.c 



categorie_b.o : categorie_b.o
	gcc -c categorie_b.c 



categorie_c.o : categorie_c.o
	gcc -c categorie_c.c 


