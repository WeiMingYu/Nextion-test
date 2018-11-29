#include "Nextion.h"

NexProgressBar j0  = NexProgressBar(0, 3, "j0");
NexButton btn_up   = NexButton(0, 1, "btn_up");
NexButton btn_down = NexButton(0, 2, "btn_down");

char buffer[100] = {0};
int ledPin =13;

NexTouch *nex_listen_list[] = 
{
    &btn_up,
    &btn_down,
    NULL
};

void buttonUpPopCallback(void *ptr)
{
    uint32_t number = 0; 
   
    // 標準指標引道
    NexButton *btn = (NexButton *)ptr;
    dbSerialPrintln("buttonUpPopCallback");
    dbSerialPrint("ptr=");
    dbSerialPrintln((uint32_t)ptr); 
    memset(buffer, 0, sizeof(buffer));
    //標準指標引道


    j0.getValue(&number);
    number += 5;
    if (number >= 100)
    {
        number = 100;
    }
        j0.setValue(number);
        digitalWrite(ledPin, HIGH);
}

void buttonDownPopCallback(void *ptr)
{
    uint32_t number = 0;  
   
    // 標準指標引道
    NexButton *btn = (NexButton *)ptr;
    dbSerialPrintln("buttonDownPopCallback");
    dbSerialPrint("ptr=");
    dbSerialPrintln((uint32_t)ptr); 
    memset(buffer, 0, sizeof(buffer));  
    //標準指標引道

    j0.getValue(&number);
    if (number >= 5)
    {
        number -= 5;
    }
        j0.setValue(number);
         digitalWrite(ledPin, LOW);
}

void setup(void)
{
    nexInit();
    btn_up.attachPop(buttonUpPopCallback, &btn_up);
    btn_down.attachPop(buttonDownPopCallback, &btn_down);
    dbSerialPrintln("setup done");
    pinMode(ledPin, OUTPUT);
}

//執行內容
void loop(void)
{
  nexLoop(nex_listen_list);
 //  digitalWrite(ledPin, HIGH);
    // delay(2000);
// digitalWrite(ledPin, LOW);
//  delay(2000);
 }//