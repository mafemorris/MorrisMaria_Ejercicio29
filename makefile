grafica1.png : tiempo.txt ejercicio.py
	python ejercicio.py

tiempo.txt : ejercicio.x
	./ejercicio.x
	rm ejercicio.x

ejercicio.x : ejercicio.cpp
	c++ ejercicio.cpp -o ejercicio.x
	

clear :
	rm grafica1.png