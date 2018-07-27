#include <systemc.h>
#include "aluStim.h"
#include "aluMonitor.h"

//#define DEBUG_OPT

SC_MODULE (alu_module)
{
  	sc_in <sc_uint<4>> alu_mode;
    sc_in <sc_int<16>> alu_input_a;
    sc_in <sc_int<16>> alu_input_b;
    
    sc_out <bool> carry;
    sc_out <bool> overflow;
    sc_out <bool> zero;
    sc_out <sc_int<16>> alu_out;
     
    // Helper variables
    sc_int <16> input_a;
    sc_int <16> input_b;
    sc_int <16> output;

    void operation ()
    {						
#ifdef DEBUG_OPT		
		cout << "ALU MODE: " << alu_mode.read() << endl;
		cout << "INPUT A: " << alu_input_a.read() << endl;
		cout << "INPUT B: " << alu_input_b.read() << endl;
		cout << "and the result is: " << output << endl;
#endif

		// Reset flags
		overflow.write(false);

		input_a = alu_input_a->read();
		input_b = alu_input_b->read();
			
		switch (alu_mode.read())
		{		
			// Aritmetic operations	
			// If mode is 0, then sum
			case 0:
				output = input_a + input_b;
				break;
				
			// If mode is 1, then rest	
			case 1:
				output = input_a - input_b;
				break;				
				
			// If mode is 2, then multiply	
			case 2:
				output = input_a * input_b;
				break;				
				
			// If mode is 3, then divide	
			case 3:
				output = input_a / input_b;
				break;
				
				
			// Logic operations	
			// If mode is 4, then OR	
			case 4:
				output = input_a | input_b;
				break;								
				
			// If mode is 5, then AND	
			case 5:
				output = input_a & input_b;
				break;
				
			// If mode is 6, then XOR	
			case 6:
				output = input_a ^ input_b;
				break;
				
			// If mode is 7, then shift right	
			case 7:
				output = input_a >> input_b;
				break;				
				
			// If mode is 8, then shift left	
			case 8:
				output = input_a << input_b;
				break;				

			// If mode is 9, then negate	
			case 9:
				output = ~input_a;
				break;			
		}
		
		if(65535 <= output) 
		{
			overflow.write(true);
		}
		
		alu_out.write(output);		
	}
	
	
	SC_CTOR(alu_module)
    {
		SC_METHOD(operation);
		
		sensitive << alu_mode << alu_input_a << alu_input_b;	
					
		cout << "\n\nALU Initialized, Ronny J., Esteban M., Fabricio Q., Arnoldo R." << endl << endl << endl;;
    }
};

int sc_main(int argc, char* argv[]) 
{	
	// Inputs
	sc_signal <sc_uint<4>> mode;
	sc_signal <sc_int<16>> in_A, in_B;
	sc_signal <bool> zero;
	
	// Outputs
	sc_signal <bool> carry_alu;
	sc_signal <bool> overflow_alu;
	sc_signal <sc_int<16>> output_alu;
	
	sc_clock TestClk("TestClock", 5, SC_NS,1,SC_NS);
	
	// ALU Instantiation
	alu_module alu("my_alu");  
					
	// Bind the generated stimulus with ALU's properties
	// First, the inputs
	alu.alu_input_a(in_A);
	alu.alu_input_b(in_B);
	alu.alu_mode(mode);

	// Then the outputs
	alu.carry(carry_alu);
	alu.overflow(overflow_alu);
	alu.alu_out(output_alu);
	alu.zero(zero);
	
	stimulus Stimulus("Stimulus");   
	Stimulus.opA(in_A);   
	Stimulus.opB(in_B);
	Stimulus.mode(mode);
	Stimulus.Clk(TestClk);

  	monitor Monitor("Monitor");   
	Monitor.opA(in_A);   
	Monitor.opB(in_B);   
	Monitor.mode(mode);
	Monitor.result(output_alu);
	Monitor.overflow(overflow_alu);
	Monitor.Clk(TestClk);
	Monitor.zero(zero);   

	sc_start();

	return(0);
}
