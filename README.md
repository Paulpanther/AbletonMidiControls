# Ableton Midi Controls

### Installation
1. `pip install -r requirements.txt`
2. Install [loopMidi](http://www.tobias-erichsen.de/software/loopmidi.html)
3. Launch loopMidi and add a port
4. Open Ableton Preferences, Link Tempo MIDI and enable `Track`, `Sync`, `Remote` and `MPE` for `Input: loopMIDI Port`
5. Install the Arduino IDE and install the [ESP32 board](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)
6. Download [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer/archive/master.zip) and [AsyncTCP](https://github.com/me-no-dev/AsyncTCP/archive/master.zip)
7. Add them via Sketch, Include Library, Add .zip Library
8. Replace your WIFIs SSID and password
9. Upload the code to your esp and read the IP from the Serial Monitor on 115200 baud 
10. Run `ws_client.py` with the ip as its arguments
11. Use MIDI Mappings or add a MIDI Track in Ableton


### Resources used
- https://github.com/AhmadMoussa/Python-Midi-Ableton
- https://randomnerdtutorials.com/esp32-websocket-server-arduino/