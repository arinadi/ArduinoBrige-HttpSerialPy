# Importing Libraries

import time

import serial

from flask import Flask, json
from markupsafe import escape

from win10toast import ToastNotifier


arduino = serial.Serial(port='COM5', baudrate=115200, timeout=.1)
toast = ToastNotifier()
api = Flask(__name__)

def write_read(x):
    # arduino.write(bytes(x, 'utf-8')) # Command prompt input
    arduino.write(x.encode('utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    print(data)
    toast.show_toast("Arduino HTTPSerialPy", "Serial Data : " + data.decode('utf-8'), duration = 1, threaded=True)
    return data

@api.route("/")
def hello():
    return "<h1>Arduino HTTPSerialPy</h1>"

@api.route("/light/<status>")
def light(status):
    status = escape(status)
    write_read(status)
    
    return f"Hello, Lampu {escape(status)}!"

toast.show_toast("Arduino HTTPSerialPy", "The program has been started successfully", duration = 1, threaded=True)

if __name__ == '__main__':
    api.run()