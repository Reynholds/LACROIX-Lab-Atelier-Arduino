//Mise en oeuvre Arduino pour récupération contact pluviométrie + affichage sur LCD 2 lignes
//Pluviométre contact ( resistance du contact = O ohms si détection)  
//04/04/2018


//Pin n°13 contact pluviomètre
int Impulsion_pluvio =  13; 
int Index_pluvio = 0;
int Etat_pluvio ;

//variable utilisée pour gestion front montant contact pluviomètre
int memoire = HIGH; 

// include the library code:
#include <LiquidCrystal.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  //Initialisation moniteur série
  Serial.begin(9600);  
  //Pin 13 avec résistance de pullup interne
  pinMode(Impulsion_pluvio,INPUT_PULLUP);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  // Print a message to the LCD.
  lcd.print("Index pluvio: ");
 
}
  
void loop() {

  // Lecture pin n°13 (information logique)
  Etat_pluvio = digitalRead(Impulsion_pluvio);

  // Si le contact pluvio a un état différent de celui enregistré ET
  // que cet état est "bas"
    if((Etat_pluvio != memoire) && (Etat_pluvio == LOW)) 
   
    {
        // on incrémente le compteur
        Index_pluvio++;

  // Affichage de l'index sur moniteur série à chaque implusion
  Serial.println(Index_pluvio); 
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(Index_pluvio); 
  lcd.print(" mm"); 
  
    }

    // on enregistre l'état du pluvio 
     memoire = Etat_pluvio;  
 
}
