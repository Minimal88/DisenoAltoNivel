(* src = "design.sv:2" *)
module mesi_fsm(clk, reset, PW, PR, BW, BR, S, state);
  (* src = "design.sv:20" *)
  wire [1:0] _00_;
  (* src = "design.sv:63" *)
  wire _01_;
  (* src = "design.sv:66" *)
  wire _02_;
  (* src = "design.sv:63" *)
  wire _03_;
  (* src = "design.sv:27" *)
  wire _04_;
  (* src = "design.sv:50" *)
  wire _05_;
  (* src = "design.sv:60" *)
  wire _06_;
  wire [1:0] _07_;
  wire [1:0] _08_;
  wire [1:0] _09_;
  wire [1:0] _10_;
  wire [1:0] _11_;
  wire [1:0] _12_;
  wire [1:0] _13_;
  wire _14_;
  wire [1:0] _15_;
  wire [1:0] _16_;
  wire [1:0] _17_;
  wire _18_;
  wire [1:0] _19_;
  wire [1:0] _20_;
  wire [1:0] _21_;
  wire _22_;
  wire [1:0] _23_;
  (* src = "design.sv:8" *)
  input BR;
  (* src = "design.sv:7" *)
  input BW;
  (* src = "design.sv:6" *)
  input PR;
  (* src = "design.sv:5" *)
  input PW;
  (* src = "design.sv:9" *)
  input S;
  (* src = "design.sv:3" *)
  input clk;
  (* src = "design.sv:4" *)
  input reset;
  (* src = "design.sv:10" *)
  output [1:0] state;
  reg [1:0] state;
  assign _01_ = PR && (* src = "design.sv:63" *) _03_;
  assign _02_ = PR && (* src = "design.sv:66" *) S;
  assign _03_ = ! (* src = "design.sv:63" *) S;
  assign _04_ = PR || (* src = "design.sv:27" *) PW;
  assign _05_ = PR || (* src = "design.sv:50" *) BR;
  assign _06_ = BW || (* src = "design.sv:60" *) BR;
  always @(posedge clk)
      state <= _00_;
  reg [1:0] _31_;
  (* parallel_case *)
  always @*
    casez (_02_)
      1'b1:
        _31_ = 2'b01;
      default:
        _31_ = _23_;
    endcase
  assign _07_ = _31_;
  reg [1:0] _32_;
  (* parallel_case *)
  always @*
    casez (_01_)
      1'b1:
        _32_ = 2'b10;
      default:
        _32_ = _07_;
    endcase
  assign _08_ = _32_;
  reg [1:0] _33_;
  (* parallel_case *)
  always @*
    casez (_06_)
      1'b1:
        _33_ = 2'b11;
      default:
        _33_ = _08_;
    endcase
  assign _09_ = _33_;
  reg [1:0] _34_;
  (* parallel_case *)
  always @*
    casez (BW)
      1'b1:
        _34_ = 2'b11;
      default:
        _34_ = state;
    endcase
  assign _10_ = _34_;
  reg [1:0] _35_;
  (* parallel_case *)
  always @*
    casez (PW)
      1'b1:
        _35_ = state;
      default:
        _35_ = _10_;
    endcase
  assign _11_ = _35_;
  reg [1:0] _36_;
  (* parallel_case *)
  always @*
    casez (_05_)
      1'b1:
        _36_ = 2'b10;
      default:
        _36_ = _11_;
    endcase
  assign _12_ = _36_;
  reg [1:0] _37_;
  (* parallel_case *)
  always @*
    casez ({ _22_, _18_, _14_ })
      3'b??1:
        _37_ = _12_;
      3'b?1?:
        _37_ = _17_;
      3'b1??:
        _37_ = _21_;
      default:
        _37_ = _09_;
    endcase
  assign _13_ = _37_;
  assign _14_ = state == 2'b10;
  reg [1:0] _39_;
  (* parallel_case *)
  always @*
    casez (BR)
      1'b1:
        _39_ = 2'b10;
      default:
        _39_ = _10_;
    endcase
  assign _15_ = _39_;
  reg [1:0] _40_;
  (* parallel_case *)
  always @*
    casez (PW)
      1'b1:
        _40_ = 2'b00;
      default:
        _40_ = _15_;
    endcase
  assign _16_ = _40_;
  reg [1:0] _41_;
  (* parallel_case *)
  always @*
    casez (PR)
      1'b1:
        _41_ = 2'b01;
      default:
        _41_ = _16_;
    endcase
  assign _17_ = _41_;
  assign _18_ = state == 2'b01;
  reg [1:0] _43_;
  (* parallel_case *)
  always @*
    casez (BR)
      1'b1:
        _43_ = 2'b11;
      default:
        _43_ = state;
    endcase
  assign _19_ = _43_;
  reg [1:0] _44_;
  (* parallel_case *)
  always @*
    casez (BW)
      1'b1:
        _44_ = 2'b10;
      default:
        _44_ = _19_;
    endcase
  assign _20_ = _44_;
  reg [1:0] _45_;
  (* parallel_case *)
  always @*
    casez (_04_)
      1'b1:
        _45_ = 2'b00;
      default:
        _45_ = _20_;
    endcase
  assign _21_ = _45_;
  assign _22_ = state == 2'b00;
  reg [1:0] _47_;
  (* parallel_case *)
  always @*
    casez (reset)
      1'b1:
        _47_ = state;
      default:
        _47_ = _13_;
    endcase
  assign _00_ = _47_;
  reg [1:0] _48_;
  (* parallel_case *)
  always @*
    casez (PW)
      1'b1:
        _48_ = 2'b01;
      default:
        _48_ = state;
    endcase
  assign _23_ = _48_;
endmodule

