 ; Generating a square
 ; Parameters:
G21 ; Millimetre units
M104 S230 ; Set extruder temperature to 200 degrees
G90 ; Absolute coordinates
M83 ; Relative extruder coordinates
G92 E0 ; Reset extruder coordinate to 0
G28 X Y Z ; Home all axis
G29 ; Detailed Z-probe
M109 S230 ; Wait for extruder to reach temperature
M106 ; Turn fan on
G1 F1260 ; Set feed rate
G92 E0 ; Reset extruder coordinate to 0
G1 X20.000000 Y20.000000 Z0.000000
G3 X20.000000 Y20.000000 I25.000000 J20.000000 E2.356194
M107 ; Turn fan off
G1 Z10 ; Move nozzle up and out of the way
