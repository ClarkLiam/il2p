import os, sys
import time
import rtmidi

midiin = rtmidi.MidiIn()

ports = range(midiin.get_port_count())
for i in ports:
    if midiin.get_port_name(i) == 'Illumination2Pro Illumination2PRO':
        midiin.open_port(i)
        print('Opened port: ' + midiin.get_port_name(i))
    
