#define BLYNK_PRINT Serial   
    #include <SPI.h>
    #include <Ethernet.h>
    #include <BlynkSimpleEthernet.h>
    #include <SimpleTimer.h>
    
    // You should get Auth Token in the Blynk App.
    // Go to the Project Settings (nut icon).
    char auth[] = "xxxxxxxxx";
    
    float temp;
    int tempPin = 1; //analog pin 1
    
    SimpleTimer timer;
    
    void setup()
    {
      Serial.begin(9600); // See the connection status in Serial Monitor
      Blynk.begin(auth);
    
      // Setup a function to be called every second
      timer.setInterval(1000L, sendUptime);
    }
    
    // that you define how often to send data to Blynk App.
    void sendUptime()
    {
     // shows the value temp on virtual pin 10
      Blynk.virtualWrite(10, temp); 
    }
    
    void loop()
    {
      Blynk.run(); // Initiates Blynk
      timer.run(); // Initiates SimpleTimer
      
       temp = analogRead(tempPin);
       temp = temp * 0.48828125;  
      
    }
