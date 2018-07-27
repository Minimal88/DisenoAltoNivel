//-----------------------------------------------------
// Testbench for the 12-bit up-counter ---------------->
// Example from www.asic-world.com (with fixes)
//-----------------------------------------------------
#include "systemc.h"
#include "counter_design.cpp"

int sc_main (int arg, char* argv[]) {
  sc_signal<bool>   clock;
  sc_signal<bool>   reset;
  sc_signal<bool>   enable;
  sc_signal<bool>   up;
  sc_signal<sc_uint<12> > counter_out;
  int i = 0;
  // Connect the DUT
  first_counter counter("COUNTER");
  counter.clock(clock);
  counter.reset(reset);
  counter.enable(enable);
  counter.up(up);
  counter.counter_out(counter_out);

  sc_start(1, SC_NS);

  // Open VCD file
  sc_trace_file *wf = sc_create_vcd_trace_file("counter");
  // Dump the desired signals
  sc_trace(wf, clock, "clock");
  sc_trace(wf, reset, "reset");
  sc_trace(wf, enable, "enable");
  sc_trace(wf, up, "up");
  sc_trace(wf, counter_out, "count");

  // Initialize all variables
  reset = 1;       // initial value of reset
  enable = 0;      // initial value of enable
  up = 0;          // initial value of up

  for (i=0;i<13;i++) { //antes era 5___________________________
    clock = 0; 
    sc_start(1, SC_NS);
    clock = 1; 
    sc_start(1, SC_NS);
  }

  //UP COUNTING
  reset = 0;    // Assert the reset
  cout << "@" << sc_time_stamp() <<" Asserting reset\n" << endl;
  for (i=0;i<13;i++) {
    clock = 0; 
    sc_start(1, SC_NS);
    clock = 1; 
    sc_start(1, SC_NS);
  }
  reset = 1;    // De-assert the reset
  cout << "@" << sc_time_stamp() <<" De-Asserting reset\n" << endl;
  for (i=0;i<13;i++) {
    clock = 0; 
    sc_start(1, SC_NS);
    clock = 1; 
    sc_start(1, SC_NS);
  }
  cout << "@" << sc_time_stamp() <<" Asserting Enable\n" << endl;
  enable = 1;  // Assert enable
  for (i=0;i<4096;i++) {
    clock = 0; 
    sc_start(1, SC_NS);
    clock = 1; 
    sc_start(1, SC_NS);
  }
  

  //DOWN COUNTING

  up = 0;          //De-assert the upcounting
  cout << "@" << sc_time_stamp() <<" De-Asserting upcounting\n" << endl;

  for (i=0;i<4096;i++) {
    clock = 0; 
    sc_start(1, SC_NS);
    clock = 1; 
    sc_start(1, SC_NS);
  }
  

  cout << "@" << sc_time_stamp() <<" De-Asserting Enable\n" << endl;
  enable = 0; // De-assert enable

  cout << "@" << sc_time_stamp() <<" Terminating simulation\n" << endl;
  sc_close_vcd_trace_file(wf);
  return 0;// Terminate simulation

}
