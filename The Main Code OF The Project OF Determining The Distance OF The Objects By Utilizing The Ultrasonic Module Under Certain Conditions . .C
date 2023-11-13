// The Project OF Determining The Distance OF The Objects By Utilizing The Ultrasonic Module Under Certain Conditions .

// The Main Code OF The Project OF Determining The Distance OF The Objects By Utilizing The Ultrasonic Module Under Certain Conditions . .C

// In this program, We want to determine the distance of the Objects by utilizing the Ultrasonic Module and then display it on the LCD Screen. If the distance of the Objects is " Four Centimeters (4 CM) " or fewer than " Four Centimeters (4 CM) " , the LED Light will turn on One Hundred Percent (100 %) , but if the distance of the Objects is " Thirty-Four Centimeters (34 CM) " or more than " Thirty-Four Centimeters (34 CM) " , the LED Light will turn off One Hundred Percent (100 %) .




#include <LiquidCrystal.h>                                                                                                              // Library Required for this Project .
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;                                                                            // Definition of Different Bases .
int Time, Trigger = 9, Echo = 10;                                                                                                     // Basic Definition : Numbers 9 , and 10 . :
float Distance;                                                                                                   // Set Value to Distance .
LiquidCrystal LCD (rs, en, d4, d5, d6, d7);                                                                                         // Definition of Different Bases .


void setup () {


  pinMode (Trigger, OUTPUT);                                                                                                   // Introducing The OUTPUT Pin .
  pinMode (Echo, INPUT);                                                                                                      // Introducing The INPUT Pin .
  Serial.begin (9600);                                                                                                       // Introducing The Series .
  LCD.begin (16, 2);                                                                                                        // Introducing LCD Resolution .


}


void loop () {


  digitalWrite (Trigger, LOW);
  delayMicroseconds (2);                                                                                           // Running the Delay Function (2 Microseconds) . :
  digitalWrite (Trigger, HIGH);
  delayMicroseconds (10);                                                                                        // Running the Delay Function (10 Microseconds) . :
  digitalWrite (Trigger, LOW);
  Time = pulseIn (Echo, HIGH);
  Distance = Time * 0.034 / 2;                                                                                // Set Value to Distance .
  Serial.print (" Distance : ");                                                                             // Show the Desired Message .
  Serial.println (Distance);                                                                                // Show the Desired Message .
  LCD.setCursor (0, 0);                                                                                    // To run Regularly and Display the OUTPUT Below .
  LCD.print (" Distance : ");                                                                             // Show the Desired Message .
  LCD.print (Distance);                                                                                  // Show the Desired Message .


  delay (500);                                                                                         // Running the Delay Function (0.5 Seconds) . :
  LCD.clear ();                                                                                       // Clears the LCD Screen and Positions the Cursor in the Upper-Left Corner .
  float X = map (Distance, 4, 30, 255, 0);
  if (Distance <= 4)


  {


  digitalWrite (6, HIGH);


  }


  else if (Distance >= 34)


  {


  digitalWrite (6, LOW)


  }


  else


  }


    analogWrite (6, X);


    }


}
