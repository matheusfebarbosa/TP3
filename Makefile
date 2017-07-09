#Author: Matheus Felipe Eduardo Barbosa

TP3: main.o internal_sorting.o solutions.o graph.o
	gcc main.o internal_sorting.o solutions.o graph.o -o TP3 -Wall -Wextra -Werror -std=c99 -pedantic
main.o: main.c
		gcc -c main.c -Wall -Wextra -Werror -std=c99 -pedantic
solutions.o: solutions.c solutions.h
			gcc -c solutions.c -Wall -Wextra -Werror -std=c99 -pedantic
internal_sorting.o: internal_sorting.c internal_sorting.h
				gcc -c internal_sorting.c -Wall -Wextra -Werror -std=c99 -pedantic
graph.o: graph.c graph.h
					gcc -c graph.c -Wall -Wextra -Werror -std=c99 -pedantic				
clean:
	rm *.o TP3