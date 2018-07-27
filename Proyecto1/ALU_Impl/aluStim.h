#include "systemc.h" 
SC_MODULE(stimulus) 
{
	sc_out <sc_int<16>> opA,opB;
	sc_out <sc_uint<4>> mode;
	sc_in <bool> Clk;

	void GenerateStimulus()
	{
		// Aritmetic operations
		
		// Sum
		opA.write(3);     
		opB.write(4);
		mode.write(0); // expected a 7

		wait(5,SC_NS);
		
		// Rest
		opA.write(5);     
		opB.write(6);
		mode.write(1); // expected a -1

		wait(5,SC_NS);

		// Rest
		opA.write(8);     
		opB.write(6);
		mode.write(1); // expected a 2

		wait(5,SC_NS);

		// Multiply
		opA.write(2);     
		opB.write(4);
		mode.write(2); // expected a 8

		wait(5,SC_NS);

		// Divide
		opA.write(9);     
		opB.write(3);
		mode.write(3); // expected a 3

		wait(5,SC_NS);
				
		
		// Logic Operations
		
		// OR
		opA.write(1);     
		opB.write(6);
		mode.write(4); // expected a 7

		wait(5,SC_NS);
		
		// AND
		opA.write(2);     
		opB.write(3);
		mode.write(5); // expected a 2

		wait(5,SC_NS);
		
		// XOR
		opA.write(16);     
		opB.write(5);
		mode.write(6); // expected a 21

		wait(5,SC_NS);
		
		// Shift Right
		opA.write(9);     
		opB.write(1);
		mode.write(7); // expected a 4

		wait(5,SC_NS);				
		
		// Shift Left
		opA.write(7);     
		opB.write(1);
		mode.write(8); // expected a 14

		wait(5,SC_NS);	
		
		// Negate
		opA.write(10);     
		mode.write(9); // expected a -11

		wait(5,SC_NS);			
		
		sc_stop();   
	}   

	SC_CTOR(stimulus)
	{
		SC_THREAD(GenerateStimulus);
	} 
};
