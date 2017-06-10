import win32api
import serial

arduino = serial.Serial('COM4',9600,timeout=0.1)

VK_MEDIA_PLAY_PAUSE = 0xB3
hwcode = win32api.MapVirtualKey(VK_MEDIA_PLAY_PAUSE, 0)

while True:
    read_line=arduino.readline()
    button_pressed=read_line[0:22]
    button_pressed=button_pressed[:-1] # Delete last character.
    if(button_pressed=="A70 FFFFFFFF FFFFFFFF"): # Code of the pressed button.
        print("Play/Pause pressed")                   
        win32api.keybd_event(VK_MEDIA_PLAY_PAUSE, hwcode)
