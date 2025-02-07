// Pin
int Red = 5;
int Yellow = 6;
int Green = 7;
int button = A3;

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;
bool vehicleDetected = false;
unsigned long noVehicleStart = 0;

void setup() {
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  vehicleDetected = checkVehicle();

  if (!vehicleDetected) {
    if (noVehicleStart == 0) {
      noVehicleStart = millis(); // Start counting time
    } else if (millis() - noVehicleStart >= 30000) { // 30 seconds
      stayRedMode();
      return;
    }
  } else {
    noVehicleStart = 0; // Reset counter if a vehicle is detected
  }

  // Traffic Light
  if (digitalRead(button) == LOW) {
    pedestrian(); 
  }
  changeLights(Green, 2000);

  if (digitalRead(button) == LOW) {
    pedestrian(); 
  }
  changeLights(Yellow, 2000);

  if (digitalRead(button) == LOW) {
    pedestrian(); 
  }
  changeLights(Red, 2000);
}

// pedestrian
void changeLights(int activeLight, int delayTime) {
  digitalWrite(Red, (activeLight == Red) ? HIGH : LOW);
  digitalWrite(Yellow, (activeLight == Yellow) ? HIGH : LOW);
  digitalWrite(Green, (activeLight == Green) ? HIGH : LOW);
  
  unsigned long start = millis();
  while (millis() - start < delayTime) {
    if (digitalRead(button) == LOW) {
      pedestrian();
      return;
    }
  }
}


void pedestrian() {
  digitalWrite(Green, LOW);
  digitalWrite(Yellow, HIGH);
  delay(2000);
  digitalWrite(Yellow, LOW);
  digitalWrite(Red, HIGH);
  delay(5000);

  
  digitalWrite(Red, LOW);
  digitalWrite(Yellow, HIGH);
  delay(2000);
  digitalWrite(Yellow, LOW);
  digitalWrite(Green, HIGH);
  delay(2000);
}

//detect vehicle
bool checkVehicle() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm

  return (distance > 0 && distance < 50); // Vehicle detected if distance < 50cm
}

//no vehicle detected
void stayRedMode() {
  digitalWrite(Red, HIGH);
  digitalWrite(Yellow, LOW);
  digitalWrite(Green, LOW);
  
  while (!checkVehicle()) {
    delay(500);
  }
}
