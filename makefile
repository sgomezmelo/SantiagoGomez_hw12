PDE.pdf: advection.txt SG_graph.py
	python SG_graph.py
advection.txt: SG_advection.cpp
	c++ SG_advection.cpp
	./a.out > advection.txt
	rm a.out
