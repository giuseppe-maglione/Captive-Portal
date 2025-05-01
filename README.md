# About
This project demonstrates a **basic Evil Twin attack** using an **ESP32** microcontroller. It creates a rogue Wi-Fi access point mimicking a legitimate one, with the intent of capturing user credentials through a fake login page.

---

## 📝 Features

- Creates a fake open Wi-Fi network (Evil Twin).
- Hosts a fake login page via captive portal.
- Captures submitted credentials.
- Displays credentials in the Serial Monitor.

---

## 🔧 Requirements

- ESP32 Development Board (any model with Wi-Fi support).
- [Arduino IDE](https://www.arduino.cc/en/software).
- ESP32 Board Manager installed in Arduino IDE.

---

## 🚀 How to Use

1. Download and setup the code.
   - Change the network SSID (optional).
   - Adjust the baud rate according to your ESP32 model.
3. Compile and flash the code into the ESP32.
   - Make sure the ESP32 libraries are installed.
5. Connect to the fake (evil twin) Wi-Fi network.
6. Enter credentials on the fake login page.

The submitted credentials will be printed in the Serial Monitor.

---

## 🛡️ Disclaimer

This project is intended solely for educational purposes in cybersecurity research. Use it only in:
- Lab environments
- Private networks you own
- With explicit consent from all parties involved

**Unauthorized access to networks or data is illegal and unethical**.
