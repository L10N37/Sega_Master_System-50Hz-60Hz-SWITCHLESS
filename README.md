Switchless modchip for master system using PIC12F675 or PIC12F629.
Default 60Hz
Hold pause when powering on for 50Hz mode.

Connections are:
5v
GND 
Pause/ bottom of R9 (pullup resistor for pause circuit)
VDP 50/60Hz mode pin (cut this/ float it and wire onto it)

You can see a 5v plane pictured with the modchips 5v line wired to it. Any of that row/ end of those resistors there are good spots to grab 5v.

I haven't thrown a proper diagram together but there are photos.
The raw hex file is here for flashing straight onto the PIC chip. I used XGPro / TL866 II +
