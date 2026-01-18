<<<<<<< HEAD
# Offline Portable Doomscrolling
Doomscrolling machine that runs on an ESP32.<br>
I specifically used the Espressif ESP32-WROOM-32U and added a Motorola SBG6580P2 antenna.

# How to setup
1. Make sure you have Platform IO installed unless you are using Arduino IDE or whatever but I am only showing how to use Platform IO since that is what I used.
2. Clone this repo into wherever.
3. Wire your ESP32 and format your MicroSD/SD card both accordingly to this website -> https://lastminuteengineers.com/esp32-microsd-card-tutorial/ (you can stop at "Setting Up the Arduino IDE") and connect your antenna if you have one.
4. Open VS Code and go to Platform IO home then click the Open Project button and open this repo.
5. Open a terminal and run this command in it: ```pio run -t uploadfs```
6. Close the terminal after it runs successfully and click the upload button on the bottom bar next. (If it doesn't work then try holding the boot button on the ESP until is says "Connecting...")
7. If everything goes well then you are done with setup and can use it.

# How to use
1. Make sure wiring and setup is correct then plug it into a power source (power bank for portability).
2. Connect to the SSID you set it to (default is "The Bomb") and the password you also set it to (default is "verysafepassword").
3. Open your browser and go to 192.168.69.69 and enjoy doomscrolling.

# BOM
| Item                    | Cost est. (USD) | Quantity            |
|-------------------------|-----------------|---------------------|
| ESP32                   | ~$7-9           | x1                  |
| Antenna (Optional)      | idk             | x1                  |
| MicroSD/SD Card Adapter | ~$1-3           | x1                  |
| F-F DuPont Wires        | ~$1-3           | x6 individual wires |

# Credits
ChatGPT made index.html because I hate CSS but everything else was me and AI free. I promise.<br>
Thanks to https://lastminuteengineers.com/esp32-microsd-card-tutorial/ and https://randomnerdtutorials.com/esp32-access-point-ap-web-server/ for educating me enough to make this possible.

# Contact
email -> trajesh@3272010.xyz
=======
# Offline-Portable-Doomscrolling
Doomscrolling on an ESP32.
>>>>>>> 4090119ddffb71d2c98f35ed5999e3f2c41530fd
