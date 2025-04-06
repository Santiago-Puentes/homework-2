1:
	(cd ej1/ && g++ clock.cpp clockMethods.cpp -o clock && ./clock)
2:
	(cd ej2/ && g++ studentMethods.cpp courseMethods.cpp main.cpp -o programa_curso && valgrind --leak-check=full --track-origins=yes ./programa_curso)
3:
	(cd ej3/ && g++ -g main.cpp complejo.cpp entero.cpp real.cpp -o prueba_ej3 && valgrind --leak-check=full --show-leak-kinds=all  --track-origins=yes ./prueba_ej3)
4:
	(cd ej4/ && g++ -g main.cpp -o prueba_ej4 && ./prueba_ej4)