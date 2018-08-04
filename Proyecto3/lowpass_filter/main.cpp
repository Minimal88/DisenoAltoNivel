#include "systemc-ams.h"
#include "sine.h"
#include "lowpass_elec.h"
#include "drain.h"

int sc_main(int argc, char* argv[])
{
  sc_set_time_resolution(10.0, sc_core::SC_NS);	// setting the time resolution
       
  sca_tdf::sca_signal<double> sig_sine, sig_lpout ;	// The two signals we need

  sine src("sine", 90000, 1000000);  //Data rate and frequency in Hz.  f=3kHz
  drain dr("drain");
  lp_elec lp("lowpass", 1600, 0.000000001); // R in ohms and C in nano Farads
  //1.6 kohm y 1nF
  //Cutoff Frequency

  src.out(sig_sine);
  lp.in(sig_sine);
  lp.out(sig_lpout);
  dr.in(sig_lpout);
   

  //sca_util::sca_trace_file* tr = sca_util::sca_create_tabular_trace_file("tr.dat");
  sca_util::sca_trace_file* tr = sca_util::sca_create_vcd_trace_file("tr.vcd");
  sca_util::sca_trace(tr, sig_sine ,"sine");
  sca_util::sca_trace(tr, sig_lpout ,"lpout");
  
  sc_core::sc_start(20, sc_core::SC_MS);
   
  return 0;
}


