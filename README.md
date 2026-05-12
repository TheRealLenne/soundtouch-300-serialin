<h1 align="center">Bose Soundtouch 300/700 Serial UART + How to make TAP Cable</h1>
<p align="center">A tutorial + code on how to make a TAP cable and enter in the linux terminal for the Bose Soundtouch 300/700.</p>

Since the SoundTouch 300 does not expose a standard USB debug or console interface, this method can be used to gain linux shell access.
This uses a telnet server running on the ESP8266 while the esp acts as a serial bridge.
This works on the soundtouch 300, im not sure about the 700 but they are around the same thing. This process is non-invasive when wired correctly, but incorrect voltage levels or wiring may cause damage. I am NOT responsible for any damages you may do during this procedure. Read this article carefully.
UART is 3.3V TTL, do NOT inject 5V! Do NOT connect RS232 levels directly! An ESP8266 is used as a safe 3.3V UART bridge.
The ESP8266 firmware handles the UART configuration internally.
Users do not need to manually configure:
- baud rate
- parity
- stop bits<br>
The telnet bridge automatically exposes the SoundTouch UART console over TCP port 23.<br>

Originally researched and documented by [Lenne](https://lennerutten.nl).

## What is this?
The SoundTouch 300 contains a hidden UART debug/service interface
accessible through a concealed TRS connector behind the rear sticker.
This guide uses an ESP8266 as a Wi-Fi-to-UART bridge to access:
- the manufacturing shell
- boot logs
- the Linux userspace shell
From there SSH can be enabled permanently.

## What you need: (What i used)
- ESP 8266 NodeMCU
- An old AUX cable
- Some jumper wires
- Breadboard

## How to make the cable
1. Strip the AUX cable
2. Identify which wire corresponds to each TRS contact: Tip, Ring, Sleeve (Ground). A multimeter in continuity mode is recommended.
3. Attach the following cables to the following ports of the ESP<br>
Tip Of AUX (Top part)           -> D7<br>
Ring of the AUX (Middle part)   -> D8<br>
Sleeve of the Aux (Bottom part) -> GND<br>
(D7 = RX, D8 = TX)<br>
4. Flash the software included in this repository (software-for-esp.ino) to the esp using arduino ide and make sure to enter in your wifi ssid and password in the variables. If the esp8266 is not in the arduino ide yet use [this tutorial](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/)


## How to use the cable to get a console
1. Turn off the soundbar by removing the power cable in the soundbar or removing the brick from the power outlet.
2. Peel of a little bit of the sticker on the back of the soundbar where it says the HDMI Logo.
3. A Rubber cover will be under there, remove it.
4. Once you remove the rubber cover you will see an aux like port plug the aux cable in that hole.
5. Turn on the esp using a non-data micro usb cable or plug the esp into a phone brick.
6. After the led blinks 3 times on the esp, Find the local ip of the esp in your router or use nmap.
7. telnet into the esp by using `telnet espip 23` or putty
8. plug the power back into the soundbar, you should see output on the telnet.
9. Once the WiFi light is on on the soundbar press enter.
10. You should see a "A4V> " prompt
11. Type in `rb 1`, it should then go to "A4Vmfg> "
12. Then enter in `sm2 start`, and you should get straight to the linux command line!
13. To enable ssh run the following commands: `rw` and then `touch /mnt/nv/remote_services && /etc/init.d/sshd start`
14. Then just give it a quick reboot by entering `reboot` and congratulations! SSH is enabled, you can now exit telnet and ssh from your laptop at any time, just `ssh root@boseip`


**Change and make replica servers etc.**
To change out the servers to make presets work again i recommend you go further using [this tutorial](https://timvw.be/2026/02/17/keep-your-bose-soundtouch-speaker-alive-after-the-shutdown/), we did step 1 of this article already, you can go ahead with step 2.

