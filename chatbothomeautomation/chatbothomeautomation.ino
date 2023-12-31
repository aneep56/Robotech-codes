#include "CTBot.h"
CTBot myBot;

String ssid = "Aneep";     //  YOUR WIFI SSID
String pass = "Anip5667"; // YOUR WIFI PASSWORD
String token = "5600411511:AAHeolkmPu0piCPsWX9NXyJxLUsVdUXCSyc";   // REPLACE Token WITH YOUR TELEGRAM BOT TOKEN
int bulb1 = D0;            
int bulb2 = D1;                           
int bulb3 = D2;                            						

void setup() {
	Serial.begin(9600);
	Serial.println("Starting Bot...");
	myBot.wifiConnect(ssid, pass);

	myBot.setTelegramToken(token);

	if (myBot.testConnection())
		Serial.println("\ntestConnection OK");
	else
		Serial.println("\ntestConnection Not OK");
	pinMode(bulb1, OUTPUT);
  pinMode(bulb2, OUTPUT);
  pinMode(bulb3, OUTPUT);
	digitalWrite(bulb1, LOW); 
  digitalWrite(bulb2, LOW);
  digitalWrite(bulb3, LOW);
}

void loop() {
	TBMessage msg;

	if (myBot.getNewMessage(msg)) {

		if (msg.text.equalsIgnoreCase("LIGHT ON")) {             
			digitalWrite(bulb1, HIGH);
			myBot.sendMessage(msg.sender.id, "LIGHT is now ON");  
		}
		else if (msg.text.equalsIgnoreCase("LIGHT OFF")) {        
			digitalWrite(bulb1, LOW);                             
			myBot.sendMessage(msg.sender.id, "LIGHT is now OFF"); 
		}
   else if (msg.text.equalsIgnoreCase("FAN ON")) {        
     digitalWrite(bulb2, HIGH);                             
      myBot.sendMessage(msg.sender.id, "FAN is now ON"); 
    }
    else if (msg.text.equalsIgnoreCase("FAN OFF")) {       
      digitalWrite(bulb2, LOW);                            
      myBot.sendMessage(msg.sender.id, "FAN is now OFF"); 
    }
    else if (msg.text.equalsIgnoreCase("MOTOR ON")) {        
     digitalWrite(bulb3, HIGH);                             
      myBot.sendMessage(msg.sender.id, "Motor is now ON"); 
    }
    else if (msg.text.equalsIgnoreCase("MOTOR OFF")) {       
      digitalWrite(bulb3, LOW);                            
      myBot.sendMessage(msg.sender.id, "Motor is now OFF"); 
    }
		else {                                                   
			String reply;
			reply = (String)"Welcome " + msg.sender.username + (String)". Lets think try do!.";
			myBot.sendMessage(msg.sender.id, reply);             
		}
	}
	delay(100);
}