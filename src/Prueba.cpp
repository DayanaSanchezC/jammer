/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#include "RF24.h"

// Configuración de pines para el NRF24L01 en la placa Particle:
// Pin CE  -> D2
// Pin CSN -> D3
void setup();
void loop();
RF24 radio(D2, D3);

// Dirección del canal de comunicación (Debe tener 5 bytes y ser igual en el receptor)
const uint64_t direccion = 0xE8E8F0F0E1LL;

void setup() {
    Serial.begin(9600);
    
    // Espera hasta 5 segundos a que abras el Monitor Serie en VS Code
    waitFor(Serial.isConnected, 5000); 
    Serial.println("--- Iniciando Prueba de NRF24L01 ---");

    // Inicializa el hardware de la antena
    if (!radio.begin()) {
        Serial.println("❌ Error: ¡No se pudo detectar el módulo NRF24L01!");
        Serial.println("Por favor, verifica que los pines VCC, GND, MISO, MOSI y SCK estén bien conectados.");
        while (1); // Detiene la ejecución aquí si hay un error físico
    }

    // Configura el canal donde va a escribir los datos
    radio.openWritingPipe(direccion);
    
    // RF24_PA_MIN usa el mínimo de energía. Ideal para pruebas de escritorio a corta distancia.
    radio.setPALevel(RF24_PA_MIN);
    
    // Detiene la escucha activa para actuar puramente como Transmisor
    radio.stopListening();
    
    Serial.println("✅ ¡Módulo NRF24L01 detectado e inicializado correctamente!");
}

void loop() {
    // Mensaje de texto que vamos a enviar por el aire
    const char mensaje[] = "Test Particle RF24";
    
    Serial.print("Enviando datos... ");
    
    // radio.write envía el paquete y devuelve 'true' si un receptor confirma la recepción
    bool enviadoOk = radio.write(&mensaje, sizeof(mensaje));
    
    if (enviadoOk) {
        Serial.println("¡Mensaje enviado con éxito y recibido por el objetivo!");
    } else {
        Serial.println("Enviado, pero sin confirmación (es normal si aún no enciendes el receptor).");
    }
    
    // Envía un paquete cada 3 segundos
    delay(3000);
}
/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#include "RF24.h"

// Configuración de pines para el NRF24L01 en la placa Particle:
// Pin CE  -> D2
// Pin CSN -> D3
void setup();
void loop();

RF24 radio(D2, D3);

// Dirección del canal de comunicación (Debe tener 5 bytes y ser igual en el receptor)
const uint64_t direccion = 0xE8E8F0F0E1LL;

void setup() {
    Serial.begin(9600);
    
    // Espera hasta 5 segundos a que abras el Monitor Serie en VS Code
    waitFor(Serial.isConnected, 5000); 
    Serial.println("--- Iniciando Prueba de NRF24L01 ---");

    // Inicializa el hardware de la antena
    if (!radio.begin()) {
        Serial.println("❌ Error: ¡No se pudo detectar el módulo NRF24L01!");
        Serial.println("Por favor, verifica que los pines VCC, GND, MISO, MOSI y SCK estén bien conectados.");
        while (1); // Detiene la ejecución aquí si hay un error físico
    }

    // Configura el canal donde va a escribir los datos
    radio.openWritingPipe(direccion);
    
    // RF24_PA_MIN usa el mínimo de energía. Ideal para pruebas de escritorio a corta distancia.
    radio.setPALevel(RF24_PA_MIN);
    
    // Detiene la escucha activa para actuar puramente como Transmisor
    radio.stopListening();
    
    Serial.println("✅ ¡Módulo NRF24L01 detectado e inicializado correctamente!");
}

void loop() {
    // Mensaje de texto que vamos a enviar por el aire
    const char mensaje[] = "Test Particle RF24";
    
    Serial.print("Enviando datos... ");
    
    // radio.write envía el paquete y devuelve 'true' si un receptor confirma la recepción
    bool enviadoOk = radio.write(&mensaje, sizeof(mensaje));
    
    if (enviadoOk) {
        Serial.println("¡Mensaje enviado con éxito y recibido por el objetivo!");
    } else {
        Serial.println("Enviado, pero sin confirmación (es normal si aún no enciendes el receptor).");
    }
    
    // Envía un paquete cada 3 segundos
    delay(3000);
}