//-----------------------------------------------------
// Author: Eng. Fabricio Quiros-Corella
// Design Name : up_down_12bits_counter
// File Name : up_down_12bits_counter_tb.cpp
// Function : This is a test bench implementation
// for the Up/Down 12-bit counter
//-----------------------------------------------------
#include "systemc.h"
#include "up_down_12bits_counter.cpp"

int sc_main (int argc, char* argv[]) 
{
  sc_signal<bool>   clock;
  sc_signal<bool>   reset;
  sc_signal<bool>   enable;
  sc_signal<bool>   up_down;
  sc_signal<sc_uint<12> > counter_out;
  int i = 0;
  int max_12bits_value = 4095;
  // Connect the DUT
  up_down_12bits_counter counter("COUNTER");
    counter.clock(clock);
    counter.reset(reset);
    counter.enable(enable);
    counter.up_down(up_down);
    counter.counter_out(counter_out);

  sc_start(1, SC_NS);

  // Open VCD file
  sc_trace_file *wf = sc_create_vcd_trace_file("counter");
  // Dump the desired signals
  sc_trace(wf, clock, "clock");
  sc_trace(wf, reset, "reset");
  sc_trace(wf, enable, "enable");
  sc_trace(wf, up_down, "up_down");
  sc_trace(wf, counter_out, "count");

  // Initialize all variables
  enable = 0; // Initialize enable
  up_down = 1; // Up counter
  for (i=0;i<5;i++) 
  {
    clock = 0; 
    sc_start(1, SC_NS);
    clock = 1; 
    sc_start(1, SC_NS);
  }
  reset = 0; // Assert reset
  cout << "@" << sc_time_stamp() <<"\nAsserting reset (Active low)\n" << endl;
  for (i=0;i<10;i++) 
  {
    clock = 0; 
    sc_start(1, SC_NS);
    clock = 1; 
    sc_start(1, SC_NS);
  }
  reset = 1;    // De-assert the reset
  cout << "@" << sc_time_stamp() <<"\nDe-Asserting reset (De-active high)\n" << endl;
  for (i=0;i<5;i++) {
    clock = 0; 
    sc_start(1, SC_NS);
    clock = 1; 
    sc_start(1, SC_NS);
  }
  cout << "@" << sc_time_stamp() <<"\nAsserting Enable (Up count started)\n" << endl;
  enable = 1;  // Assert enable
  for (i = 0; i < max_12bits_value; i++) 
  {
    clock = 0; 
    sc_start(1, SC_NS);
    clock = 1; 
    sc_start(1, SC_NS);
  }
  cout << "@" << sc_time_stamp() <<"\nEnable already-asserted (Down count started)\n" << endl;
  up_down = 0;  // Down counter
  for (i = 0; i < max_12bits_value; i++) 
  {
    clock = 0; 
    sc_start(1, SC_NS);
    clock = 1; 
    sc_start(1, SC_NS);
  }  
  cout << "@" << sc_time_stamp() <<"\nDe-Asserting Enable\n" << endl;
  enable = 0; // De-assert enable
  cout << "@" << sc_time_stamp() <<"\nAsserting Reset (De-active high)\n" << endl;
  reset = 0; // Assert reset

  cout << "@" << sc_time_stamp() <<"\nTerminating simulation" << endl;
  sc_close_vcd_trace_file(wf);
  return 0;// Terminate simulation
}
