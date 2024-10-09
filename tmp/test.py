import pyautogui
import keyboard
import time

print("Press the spacebar to stop the program.")
time.sleep(0.5)  # Adjust the delay as needed

while True:
    pyautogui.typewrite('.')
    pyautogui.press('enter')
    time.sleep(0.5)  # Adjust the delay as needed
    if keyboard.is_pressed('space'):
        break
