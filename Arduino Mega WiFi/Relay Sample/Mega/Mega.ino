
String tempData, relayIndex, relayState;

void setup() {
  // put your setup code here, to run once:
  Serial3.begin(9600);
  Serial.begin(9600);
  while (!Serial); // Wait for Serial Initialization
  while (!Serial3); // Wait for Serial Initialization

  clearData();
  for (int iCntr = 4; iCntr < 8; iCntr++) {
    pinMode(iCntr, OUTPUT);
  }
}

void loop() {
  if (Serial3.available() > 0) {
    char chr = (char) Serial3.read();

    if (chr == '=') {
      // We found '=', that means the data in tempData till now represend relay index
      relayIndex = tempData;
      tempData = "";
    } else if (chr == '|') {
      // We found '|', that means we received data related to 1 relay completly 
      relayState = tempData;
      // Now process the data
      updateRelayState();
      clearData();
    } else {
      // Neither '=' nor '|', keep reading data and update to tempData
      tempData += chr;
    }
  }
}

void clearData() {
  tempData = "";
  relayIndex = "";
  relayState = "";
}

void updateRelayState() {
  int iRlyIndex;
  byte bRlyState;

  Serial.print(relayIndex);
  Serial.print(F(": "));
  Serial.println(relayState);
  Serial.println();

  if (relayIndex.equals(F("RLY4"))) {
    iRlyIndex = 4;
  } else if (relayIndex.equals(F("RLY5"))) { 
    iRlyIndex = 5;
  } else if (relayIndex.equals(F("RLY6"))) { 
    iRlyIndex = 6;
  } else if (relayIndex.equals(F("RLY7"))) { 
    iRlyIndex = 7;
  }

  if (relayState.equals(F("ON"))) {
    bRlyState = HIGH;
  } else {
    bRlyState = LOW;
  }

  digitalWrite(iRlyIndex, bRlyState);
}
