#include <mcp_can.h>
#include <SPI.h>

#define MSG_LEN (8)

MCP_CAN CAN0(10);
byte data[MSG_LEN] = {0xAA, 0xBB, 0xCC, 0xDD, 0xFF, 0xAF, 0xFA, 0xCD};

void setup() {
  Serial.begin(115200);

  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)
    Serial.println("MCP2515 initialized successfully!");
  else
    Serial.println("MCP2515 initialization failed!");

  CAN0.setMode(MCP_NORMAL); 
}


void loop() {  
  if(CAN0.sendMsgBuf(0x123, 0, MSG_LEN, data) == CAN_OK)
    Serial.println("Message successfully sent!");
  else
    Serial.println("Sending message failed!");

  delay(1000);
}
