//-----------------------------------------------------
// Author: Eng. Fabricio Quiros-Corella
// Design Name : up_down_12bits_counter
// File Name : up_down_12bits_counter.cpp
// Function : This is a Up/Down 12-bit counter with
// synchronous active low reset and
// with active high enable signal
//-----------------------------------------------------
#include "systemc.h"

SC_MODULE (up_down_12bits_counter) 
{
  sc_in_clk     clock ;      // Clock input of the design
  sc_in<bool>   reset ;      // Active low, Reset input for counter
  sc_in<bool>   enable;      // Active high Enable input for counter
  sc_in<bool>   up_down;     // Up/Down input: Up count true, Down count false
  sc_out<sc_uint<12> > counter_out; // 12-bit vector output of the counter

  //------------Local Variables Here---------------------
  sc_uint<12>	count;

  //------------Code Starts Here-------------------------
  
  void up_down_count ()
  {
	// At every rising edge of clock we check if reset is active low
    // If active low, we load the counter output with 12'b000000000000
    if (reset.read() == 0) 
    {
      count =  0;
      counter_out.write(count);
    }
    // If enable is active, start the count
    else if (enable.read() == 1) 
    {
	  // Decremental count enabled
	  if (up_down.read() == 0)
	  {
	   count = count - 1;
       counter_out.write(count);
       cout<<"@" << sc_time_stamp() <<" :: Decremented Counter "<< counter_out.read() <<endl;
	  }
	  else // True, incremental count enabled
	  {
		  count = count + 1;
		  counter_out.write(count);
		  cout<<"@" << sc_time_stamp() <<" :: Incremented Counter "<< counter_out.read() <<endl;
	  }
    }
  } // End of function up_down_count

  // Constructor for the counter
  // Since this counter is a positive edge trigged one,
  // We trigger the below block with respect to positive
  // edge of the clock and also when ever reset changes state
  SC_CTOR(up_down_12bits_counter) 
  {
    cout<<"Executing new"<<endl;
    SC_METHOD(up_down_count);
    sensitive << reset;
    sensitive << clock.pos();
  } // End of Constructor

}; // End of Module Up/Down 12-bit counter
