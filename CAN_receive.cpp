#include <mcp_can.h>
#include <SPI.h>

#define MSG_LEN (8)
#define CAN0_INT (2)

long unsigned int rxId;
unsigned char length = 0;
unsigned char buff[8];
char msgString[128];
MCP_CAN CAN0(10);

void setup() {
  Serial.begin(115200);

  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)
    Serial.println("MCP2515 initialized successfully!");
  else
    Serial.println("MCP2515 initialization failed!");

  CAN0.setMode(MCP_NORMAL); 
  pinMode(CAN0_INT, INPUT);
}

void loop() {  
  if(!digitalRead(CAN0_INT)){
    CAN0.readMsgBuf(&rxId, &length, buff);

    if((rxId & 0x80000000) == 0x80000000)
      sprintf(msgString, "Extended ID: 0x%.81x  DLC: %1d Data: ", (rxId & 0x1FFFFFFF), length);
    else
      sprintf(msgString, "Standard ID: 0x%.3lX  DLC: %1d  Data:", rxId, length);
    
    for(byte i = 0; i < length; i++){
      char hexByte[6];
      sprintf(hexByte, " 0x%.2X", buff[i]);
      strcat(msgString, hexByte);
    }
    Serial.println(msgString);
  }
}
