<Qucs Schematic 0.0.20>
<Properties>
  <View=700,220,1740,794,1.08209,0,0>
  <Grid=10,10,1>
  <DataSet=ThermistorTesting.dat>
  <DataDisplay=ThermistorTesting.dpl>
  <OpenDisplay=1>
  <Script=ThermistorTesting.m>
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
  <GND * 5 1140 600 0 0 0 0>
  <Vdc V1 1 1140 550 18 -26 0 1 "3.3 V" 1>
  <.DC DC1 1 780 470 0 37 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <R R1 1 1350 480 -26 15 0 0 "Rs" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <.SW SW1 1 780 560 0 59 0 0 "DC1" 1 "lin" 1 "Rs" 1 "10k Ohm" 1 "1000k Ohm" 1 "10" 1>
  <R R2 1 1570 480 -26 15 0 0 "Rt" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <.SW SW2 1 940 560 0 59 0 0 "SW1" 1 "lin" 1 "Rt" 1 "10k Ohm" 1 "1000k Ohm" 1 "10" 1>
</Components>
<Wires>
  <1380 480 1540 480 "V_Out" 1450 430 87 "">
  <1600 480 1700 480 "" 0 0 0 "">
  <1700 480 1700 600 "" 0 0 0 "">
  <1140 600 1700 600 "" 0 0 0 "">
  <1140 580 1140 600 "" 0 0 0 "">
  <1140 480 1320 480 "" 0 0 0 "">
  <1140 480 1140 520 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
