#include "../lib/serialib.h"
#include <thread>
#include <vector>
class SerialClass : public serialib{
    public:
        char *COM_PORT;
        int BAUDRATE;
        SerialClass(char *COM_PORT,int BUADRATE);
        int OpenDevice();
        void SendData();
        void WaitData();
};
