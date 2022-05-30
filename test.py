import serial
import pyautogui

arduino=serial.Serial('COM6', 9600)

while 1:
    incoming_Data=arduino.readline()
    if 'up' in incoming_Data.decode('utf-8'):  
        pyautogui.press('up')
    incoming_Data="" 