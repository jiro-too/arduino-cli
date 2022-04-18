#include <iostream>
#include <string.h>
#include "main.h"
#include <future>
using namespace std;
SerialClass::SerialClass(char *COM_PORT,int baudrate){
    if (strcmp(COM_PORT,"") == 0){
        throw invalid_argument("COM_PORT must not be empty");
    }
    this->BAUDRATE=baudrate;
    this->COM_PORT=COM_PORT;
}

int SerialClass::OpenDevice(){
    if (serialib::openDevice(this->COM_PORT,this->BAUDRATE) != 1) return 1;
    else return 0;

}

void SerialClass::SendData(){
    char x;
    printf("Enter Data To Send: ");
    scanf("%d",&x);
    serialib::writeChar(x);
}

void Print(char *ToPrint){
    printf("%s\n",ToPrint);
}
void SerialClass::WaitData(){
    char *x;
    serialib::readChar(x,100);
    Print(x);
}
int main(){
    SerialClass *serial = new SerialClass("/dev/tty0",9600);
    printf("SET COM PORT = %s\n", serial->COM_PORT);
    printf("SET BAUDRATE = %d\n", serial->BAUDRATE);
    printf("OPENING COM PORT\n");
    if (serial->OpenDevice() != 0){
        printf("ERROR \n");
        return 1;
    }
    // async ekhane korte hobe somehow fix smh mh

    return 0;
}

