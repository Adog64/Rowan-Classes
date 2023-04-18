<Qucs Schematic 1.0.0>
<Properties>
  <View=-305,0,1571,859,1,0,0>
  <Grid=10,10,1>
  <DataSet=Lab01.dat>
  <DataDisplay=Lab01.dpl>
  <OpenDisplay=1>
  <Script=Lab01.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <R R1 1 450 290 -26 15 0 0 "1M Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <GND * 1 280 370 0 0 0 0>
  <GND * 1 640 380 0 0 0 0>
  <GND * 1 780 380 0 0 0 0>
  <R R2 1 640 350 15 -26 0 1 "9M Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <C C2 1 780 350 17 -26 0 1 "11 pF" 1 "" 0 "neutral" 0>
  <Vrect V1 1 280 340 18 -26 0 1 "5 V" 1 "1 ms" 1 "1 ms" 1 "1 ns" 0 "1 ns" 0 "0 ns" 0>
  <C C1 1 450 200 -26 17 0 0 "1.2 pF" 1 "" 0 "neutral" 0>
  <.SW SW1 1 -120 230 0 75 0 0 "TR1" 1 "lin" 1 "C1" 1 "0.5 pF" 1 "50 pF" 1 "10" 1 "false" 0>
  <.TR TR1 1 50 230 0 75 0 0 "lin" 1 "0" 1 "10 ms" 1 "1001" 0 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
</Components>
<Wires>
  <280 290 280 310 "" 0 0 0 "">
  <280 290 390 290 "" 0 0 0 "">
  <640 290 640 320 "" 0 0 0 "">
  <480 290 510 290 "" 0 0 0 "">
  <640 290 780 290 "" 0 0 0 "">
  <780 290 780 320 "" 0 0 0 "">
  <510 290 640 290 "" 0 0 0 "">
  <480 200 510 200 "" 0 0 0 "">
  <510 200 510 290 "" 0 0 0 "">
  <390 200 420 200 "" 0 0 0 "">
  <390 290 420 290 "" 0 0 0 "">
  <390 200 390 290 "" 0 0 0 "">
  <280 290 280 290 "V_in" 310 260 0 "">
  <780 290 780 290 "V_out" 810 260 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
