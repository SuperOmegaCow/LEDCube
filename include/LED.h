#ifndef LED_H
#define LED_H

class LED
{
    public:
        LED(char x, char y, char z);

        void setOn(bool value);

        virtual ~LED();

    private:
        bool on;
        unsigned char x;
        unsigned char y;
        unsigned char z;

};

#endif
