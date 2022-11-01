//https://github.com/gbmhunter/CppLinuxSerial
//$g++ serialport.cpp -lCppLinuxSerial -o serialport.o
//$./serial.o
#include <CppLinuxSerial/SerialPort.hpp>
#include <iostream>
#include <string>
#include <iterator>
#include <cstring>
#include "serial_port.hpp"


using namespace mn::CppLinuxSerial;
using std::cout;
int serial_1(char *readbuff)
{
	// Create serial port object and open serial port at 57600 buad, 8 data bits, no parity bit, and one stop bit (8n1)
	//char tempBuff[64] = {'\0'};
	SerialPort serialPort("/dev/ttyUSB0", BaudRate::B_115200, NumDataBits::EIGHT, Parity::NONE, NumStopBits::ONE);
	// Use SerialPort serialPort("/dev/ttyACM0", 13000); instead if you want to provide a custom baud rate
	serialPort.SetTimeout(-1); // Block when reading until any data is received
	serialPort.Open();

	{
	// Write some ASCII data
	//serialPort.Write("santhosh\n");

	// Read some data back (will block until at least 1 byte is received due to the SetTimeout(-1) call above)
	std::string readData;
	//char *creadData = readData.c_str();
	serialPort.Read(readData);
	//cout << readData;
	memset(readbuff,'\0',readData.length());
	memcpy(readbuff,readData.c_str(),readData.length());
	//cout<<"Length :"<<readData.length();
	//cout<<readbuff;
	return readData.length();
	}
   

	// Close the serial port
	serialPort.Close();
	return 0;
}
/*int out(char *buff){
	char buffer[124];
	{
		memset(buffer,'\0',strlen(buffer));
		serial_1(buffer);
		//cout<<buffer;
		return buffer;
	}
}*/
