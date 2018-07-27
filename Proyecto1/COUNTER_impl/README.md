
Compila el testbench para el counter:

	g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o counter_testbench counter_testbench.cpp -lsystemc -lm

Abre el archivo .vcd para visualizar las señales.
	gtkwave counter.vcd



export SYSTEMC_HOME=/usr/local/systemc-2.3.1/