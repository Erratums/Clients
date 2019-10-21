
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial); // Wait for Serial Initialization
}

void loop() {
  // Sample data "RLY4=ON|RLY5=OFF|RLY6=OFF|RLY7=OFF"

  // Switch On 1st relay and Off all other 
  Serial.println(F("RLY4=ON|RLY5=OFF|RLY6=OFF|RLY7=OFF|"));
  delay(1000);
  
  Serial.println(F("RLY4=OFF|RLY5=ON|RLY6=OFF|RLY7=OFF|"));
  delay(1000);
  
  Serial.println(F("RLY4=OFF|RLY5=OFF|RLY6=ON|RLY7=OFF|"));
  delay(1000);
  
  Serial.println(F("RLY4=OFF|RLY5=OFF|RLY6=OFF|RLY7=ON|"));
  delay(1000);
}