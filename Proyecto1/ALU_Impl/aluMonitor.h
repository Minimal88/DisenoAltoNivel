#include "iomanip"

SC_MODULE(monitor)
{   
	sc_in <bool> overflow, Clk, zero;
	sc_in <sc_uint<4> > mode;
	sc_in <sc_int<16>> opA,opB,result;
	
	
	
	void monitorate()
	{     
		cout << std::setw(11) << "Time";     
		cout << std::setw(10) << "opA";     
		cout << std::setw(10) << "opB";     
		cout << std::setw(10) << "mode";     
		cout << std::setw(10) << "result";
		cout << std::setw(10) << "overflow"; 
		cout << std::setw(5) << "zero" << endl ;
		
		int i = 0;
		
		while(true)
		{
			wait();
			cout << i;
			i++;
			cout << std::setw(10) << sc_time_stamp();
			cout << std::setw(10) << opA;       
			cout << std::setw(10) << opB;   
			cout << std::setw(10) << mode;           
			cout << std::setw(10) << result;
			cout << std::setw(10) << overflow;
			cout << std::setw(5) << zero.read() << endl;
		}
	}

	SC_CTOR(monitor)
	{     
		SC_THREAD(monitorate);
		sensitive << Clk.pos();
	} 
};
