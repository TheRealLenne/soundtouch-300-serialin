<h1 align="center">Bose Soundtouch 300/700 Serial In + How to make TAP Cable</h1>
<p align="center">A tutorial + code on how to make a TAP cable and enter in the linux terminal for the Bose Soundtouch 300/700.</p>

Since there are no ways to plug a USB-A in the soundtouch300 this is the way i enabled SSH access since Bose deprecated their servers.
This uses a telnet server running on the ESP8266 while the esp acts as a serial bridge.

**What you need: (What i used)**
- ESP 8266 NodeMCU
- An old AUX cable
- Some jumper wires
- Breadboard

**How to make the cable**
1. Strip the AUX cable
2. Find out which parts of the aux cable corrosponds to which cable
3. Attach the following cables to the following ports of the ESP<br>
Tip Of AUX (Top part)           -> D7<br>
Ring of the AUX (Middle part)   -> D8<br>
Sleeve of the Aux (Bottom part) -> GND<br>



More soon.
