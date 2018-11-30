#include "Nextion.h"

NexProgressBar j0  = NexProgressBar(0, 3, "j0");
NexButton btn_up   = NexButton(0, 1, "btn_up");
NexButton btn_down = NexButton(0, 2, "btn_down");
NexButton b0 = NexButton(0, 5, "b0"); //+10
NexButton b1 = NexButton(0, 6, "b1"); //-10
NexButton b2 = NexButton(0, 8, "b2"); //+5
NexButton b3 = NexButton(0, 9, "b3"); //-5
NexNumber n0 = NexNumber(0, 4, "n0"); //數值


char buffer[100] = {0};
int ledPin =13;

NexTouch *nex_listen_list[] = 
{
    &btn_up,
    &btn_down,
    &b0,
    &b1,
    &b2,
    &b3,
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
        n0.setValue(number);
        digitalWrite(ledPin, HIGH);
}


//+10mm
void b0PopCallback(void *ptr)
{
    uint32_t number = 0; 
   
    // 標準指標引道
    NexButton *btn = (NexButton *)ptr;
    dbSerialPrintln("b0PopCallback");
    dbSerialPrint("ptr=");
    dbSerialPrintln((uint32_t)ptr); 
    memset(buffer, 0, sizeof(buffer));
    //標準指標引道


    j0.getValue(&number);
    number += 10;
    if (number >= 100)
    {
        number = 100;
    }
        j0.setValue(number);
        n0.setValue(number);
        digitalWrite(ledPin, HIGH);
}

// +1mm
void b2PopCallback(void *ptr)
{
    uint32_t number = 0; 
   
    // 標準指標引道
    NexButton *btn = (NexButton *)ptr;
    dbSerialPrintln("b2PopCallback");
    dbSerialPrint("ptr=");
    dbSerialPrintln((uint32_t)ptr); 
    memset(buffer, 0, sizeof(buffer));
    //標準指標引道


    j0.getValue(&number);
    number += 1;
    if (number >= 100)
    {
        number = 100;
    }
        j0.setValue(number);
        n0.setValue(number);
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
        n0.setValue(number);
         digitalWrite(ledPin, LOW);
}

//-10mm
void b1PopCallback(void *ptr)
{
    uint32_t number = 0;  
   
    // 標準指標引道
    NexButton *btn = (NexButton *)ptr;
    dbSerialPrintln("b1PopCallback");
    dbSerialPrint("ptr=");
    dbSerialPrintln((uint32_t)ptr); 
    memset(buffer, 0, sizeof(buffer));  
    //標準指標引道

    j0.getValue(&number);
    if (number >= 10)
    {
        number -= 10;
    }
        j0.setValue(number);
        n0.setValue(number);
         digitalWrite(ledPin, LOW);
}

//-1mm
void b3PopCallback(void *ptr)
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
    if (number >= 1)
    {
        number -= 1;
    }
        j0.setValue(number);
        n0.setValue(number);
         digitalWrite(ledPin, LOW);
}

void setup(void)
{
    nexInit();
    btn_up.attachPop(buttonUpPopCallback, &btn_up);
    btn_down.attachPop(buttonDownPopCallback, &btn_down);
    b0.attachPop(b0PopCallback, &b0);
    b1.attachPop(b1PopCallback, &b1);
    b2.attachPop(b2PopCallback, &b2);
    b3.attachPop(b3PopCallback, &b3);
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