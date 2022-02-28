import rtmidi


class Midi:
    On = 0x90
    Off = 0x80
    Control = 0xB0

    def __init__(self):
        midiout = rtmidi.MidiOut()
        available_ports = midiout.get_ports()

        if available_ports:
            midiout.open_port(1)
        else:
            midiout.open_virtual_port("My virtual output")
        self.out = midiout

    def send(self, status: int, key: int, value: int = 127, channel: int = 0):
        print(f"Sending event={hex(status + channel)}, {key}, {value}")
        self.out.send_message([status + channel, key, value])

    def __del__(self):
        del self.out
