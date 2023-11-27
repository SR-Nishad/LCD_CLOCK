Hello!

Wellcome to our Mini-Arduino Project.

Components need for this project :

	1) Arduino UNO
	2) LCD Display (16x2)
	3) Jumper Wires (Male to Female)
	4) I2C Module


Process: 

Firstly we have connected our "I2C Module" with our "16x2 LCD Display". 
Then we have connected female parts of the jumper wires to our "I2C Moudle" and the male parts connected to the "Arduino UNO". 
We have connected I2C module's GND to Arduino GND,, I2C module's VCC to 5V of Arduino,, I2C module's SDA to Arduino A4 & I2C modules SCL to Arduino A5.
We have shown our connection to INTERFACING image that we have attahed here. 
Then we connected the USB cable to PC to power our Arduino UNO and this usb will also help us to upload Code from PC.

In our coding we have used Wire.h & LiquidCrystal_I2C.h libraries, you can see our code in LCD_CLOCK_CODE file. 



We have also uploaded couple of output iamges so that you can see the output that we got. 


Thank You. 