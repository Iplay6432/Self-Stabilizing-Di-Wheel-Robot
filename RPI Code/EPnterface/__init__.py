import serial

class EPnterface:
    def __init__(self, port, baudrate=115200):
        self.port = port
        self.baudrate = baudrate
        
        try:
            self.ser = serial.Serial(self.port, self.baudrate)
        except serial.SerialException as e:
            print(f"Error opening serial port {self.port}: {e}")
            return False
        except ValueError as e:
            print(f"Invalid/Out of range parameters {self.port}, {self.baudrate}: {e}")
            return False
        
        return True
        
        