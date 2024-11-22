#include <string.h>
#include <ArduinoJson.h>

struct Power {
  String id;
  int ledPin;
  int btnPin;

  void startPins() {
    pinMode(ledPin, OUTPUT);
    pinMode(btnPin, INPUT);
  }

  bool ledState = false;
  bool lastButtonState = false;

  void toggleLed() {
    ledState = !ledState;

    JsonDocument powerJson;
    powerJson["type"] = "POWER_TOGGLE";
    powerJson["id"] = id;
    powerJson["ledState"] = ledState;
    serializeJson(powerJson, Serial);
    Serial.println();
  }

  void alive() {
    digitalWrite(ledPin, ledState ? HIGH : LOW);

    bool currentButtonState = digitalRead(btnPin);

    bool hasInactiveAndTurnActive = currentButtonState == HIGH && lastButtonState == LOW;

    if (hasInactiveAndTurnActive) {
      toggleLed();
    }

    lastButtonState = currentButtonState;
  }
};

Power createPower(String id, int ledPin, int btnPin) {
  Power p = Power{};
  p.id = id;
  p.ledPin = ledPin;
  p.btnPin = btnPin;
  return p;
}

const int MAX_SOURCES_POWERS = 3;
const int MAX_SOURCES_POWERS_LENGTH = MAX_SOURCES_POWERS-1;
struct Sources {
  Power powers[MAX_SOURCES_POWERS];
  int currentIndex = 0;

  void add(Power power) {
    /*
      essa funcionalidade é para simplificar e não utilizar bibliotecas
      uma solução seria usar uma linkedlist invés de um array
    */
    // excedeu tamanho do array de powers
    if (currentIndex > MAX_SOURCES_POWERS_LENGTH) {
      return;
    }

    powers[currentIndex] = power;
    currentIndex++;
  }

  void alive() {
    for (int x = 0; x < currentIndex; x++) {
      powers[x].alive();
    }
  }

  Power* findPowerById(String id) {
    for (const auto& power : powers) {
      if (power.id == id) return &power;
    }
    return nullptr;
  }
}

sources = Sources{};

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String incomeJSON = Serial.readString();

    JsonDocument doc;
    deserializeJson(doc, incomeJSON);

    // lida com criação de POWER
    if (doc["action"] == "CREATE_POWER") {
      Power pw = createPower(doc["id"], doc["led_pin"], doc["btn_pin"]);
      sources.add(pw);
    
      JsonDocument powerJson;
      powerJson["type"] = "NEW_POWER";
      powerJson["id"] = pw.id;
      powerJson["ledState"] = pw.ledPin;
      powerJson["btnPin"] = pw.btnPin;
      serializeJson(powerJson, Serial);
      Serial.println();
    // lida com ligar/desligar POWER
    } else if (doc["action"] == "POWER_TOGGLE") {
      Power* power = sources.findPowerById(doc["id"]);

      power->toggleLed();
    }
  }

  sources.alive();
}