# LACROIX-Lab-Atelier-Arduino
Sources et schéma de l'atelier Arduino #1

Bienvenu dans cet atelier de prototypage rapide de conception d'un capteur de pression autonome LPWAN.

# Contexte
Dans le cadre du projet sur l'exploration des plateformes IoT connectées, nous seront ammenés à faire une campagne de mesure de valeur de pression, sur le terrain.

L'idée est ici de prototyper deux types de capteurs : 
- Capteur LORA
- Capteur Sigfox

Les effets recherchés sont de saisir l'occasion de monter en compétence en prototypage rapide et d'utiliser les technos LPWAN.


## Matériel Prototypage
```
1x Arduino Lora ou Sigfox
1x Capteur CNPR
1x Antenne
1x Breadboard
2x Piles 3.6V
1x Transistor 
1x Régulateur 5V
1x Boite de dérivation
1x domino 3 trous

```

## Logiciels nécessaires
### Pour la programmation de notre objet

Le logiciel de programmation d'Arduino :  https://www.arduino.cc/en/Main/Software
> La version qui nous intéresse est Arduino IDE 1.8.5

Logiciel de création de schéma de câblage :     http://fritzing.org/download/
> Servira principalement à ceux qui souhaite modifier le câblage

### Pour la visualisation des données

Power BI : https://powerbi.microsoft.com/fr-fr/downloads/


# Arduino (https://www.arduino.cc/en/Guide/Introduction#)
## Qu'est-ce qu'un Arduino 
Un arduino est une carte électronique Open-Source, permettant de faire du développement électronique (Hardware) et logiciel (software) très facilement, comme lire l'état d'un 'bouton' en temps réel et agir sur une 'led', mais aussi lire la valeur d'un capteur de pression et poster un message sur le web.

Pour faire cela, il est possible de programmer le microcontroleur de la carte Arduino, en envoyant des instructions écrites dans un langage compréhensible par l'Arduino à l'aide de l'environnement de développement associé (IDE).
Le langage utilisé ici s'apparente à du C++, mais il existe plusieurs fonction permettant de faciliter son développement : https://www.arduino.cc/reference/en/.

Il existe une communauté très active sur cette solution, qui ont déjà réalisé des milliers de projets dans des dommaines multiples et variés et partage leurs sources sur des plateformes comme https://github.com/arduino, https://www.hackster.io/, ainsi qu'un forum très actif https://forum.arduino.cc/, donc si vous avez un problème, il est possible que quelqu'un l'ait très certainement déjà résolu :)

Il existe plusieurs types de carte Arduino, ayant plus ou moins de performance et de caractéristiques, l'une des plus répandues est la carte Uno pratique pour sa taille et sa 20taines d'entrées/sorties et son prix d'à peu près 30 €.
Il existe aussi plusieurs type de carte de fournisseurs différents basée sur de l'arduino et fonctionnant donc avec l'environnement de développement Arduino.
Dans notre cas nous utiliserons la carte MKRFOX1200 intégrant directement une connectivité Sigfox et la carte MKR WAN 1300 intégrant une connectivité LoRa.

## Pourquoi Arduino ?
Les cartes Arduinos sont simples et accessibles aux débutants d'où l'utilisation dominante de ces cartes par les étudiants, lors des  hackatons ou par les bidouilleurs du dimanche :)
Même si les cartes Arduino, sont certainement moins performantes que certaines de leurs concurrentes comme les Nucleos de ST, elles sont destinées à un public plus large.

# Préparation de notre environnement de travail
## Installation du logiciel Arduino

1- télécharge et installe Arduino 1.8.5, ainsi que tous les drivers demandés durant l'installation (Arduino USB Driver, ...)

2- Installation des modules nécessaires aux cartes MKR Fox et MKR Wan

  Via Outils > Type de cartes > Gestionnaire de carte
  
  Chercher "WAN" > Sélectionne et installe "Arduino SAMD Boards (32 bits ARM Cortex -M0+)by Arduino", ainsi que les drivers proposés lors de l'installation (Arduino USB Driver for SAMD boards)
  
3- Tout est prêt pour continuer

# Prise en main Arduino IDE
## Hello blink
Afin de tester la carte Arduino, nous allons commencer par faire clignoter la LED ! 

1- Démarre Arduino 1.8.5 

2- Sélectionne le modèle de ta carte 

	Outils > Type de cartes > Arduino MKR (WAN ou FOX)
  
3- Connecter et vérifier que la carte Arduino soit bien reconnue par PC à l'aide du câble micro-usb, "la LED verte devrait s'allumer, signifiant que la carte est sous tension"

	Outils > Port : "COMXX (Arduino MKR XXX)", sinon sélectionner le port qui contient le nom de la carte Arduino
  
4- Récupération d'un programme pour faire clignoter la LED

	Fichier > Exemples > 01.Basics > Blink
	
  Cela permet d'afficher un programme permettant de faire clignoter la LED.
  
5- Transfert ton programme dans la carte Arduino

	Croquis > Téléverser, la LED du Arduino devrait commencer à clignoter !

#### Quelques explications du code
Comme tu peux le remarquer, le programme est séparée en 3 parties

##### Les commentaires :
Le commentaire explique comment fonctionne le programme, de manière générale, les commentaires ne sont pas interprétés par la carte Arduino, et donc ne génèrent pas d'erreur, surtout il permette de comprendre ce qui est fait par le programme en langage humain.

> Tout le texte situé après "//" ou entre " /* " et " */ " sera considéré comme du commentaire.

```
/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

```
##### Le Setup :
Sur une carte Arduino, le code présent dans le Setup est exécuté une seule fois.
Il permet par exemple de configurer les broches (appelées aussi pin) de la carte en entrée ou en sortie, cette configuration, ne sera plus nécessaire par la suite, ou encore le setup, peut permettre lors de la première connexion au réseau Sigfox de récupérer l'heure...

- Dans notre cas, on s'en sert pour initialiser la pin nommée "LED_BUILTIN" en sortie "OUTPUT"
````
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}
````

##### La boucle :
Nous y voilà ! C'est ici que tout se passe.
Dans la boucle, le code est répété inlassablement, toujours de haut en bas.
Ici on se sert de l'instruction digitalWrite, pour écrire dans la pin "LED_BUILTIN", la valeur "HIGH" qui permet d'allumer la led, puis on attends 1000 millisecondes avant d'y écrire la valeur "LOW" qui éteint la led, etc .
````
// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
````


## Fade
En utilisant la même méthode, mets en place le programme Fade dans l'arduino
### Astuce : la Led intégrée sur la carte n'est pas forcément la numéro 9, mais est toujours la "LED_BUILTIN"

# Github
GitHub est une plateforme de partage de "codes sources" soit de tout éléments permetant de reproduire un projet.
Il existe de nombreux codes sources sur tout type de plateforme du simple code source en Java pour coder un visuel d'analyse de donnée au programme complet du bot mirai qui a fait tremblé le web en fin 2016.

Dans notre cas, nous en servons pour stocker toutes les sources nécessaires à ce projet.
## Récupérer les sources
1- Connecte-toi sur la page https://github.com/Reynholds/LACROIX-Lab-Atelier-Arduino

2- Via le bouton de couleur verte "Clone and Download", utilise la fonction "Download Zip" pour récupérer le répertoire entier.
Il existe une façon de récupérer les sources plus propice à la collaboration, permettant à n'importe quel contributeur de facilement proposer des améliorations sur un code source, via des "commit", "pull" ou "push", tout est expliqué sur le site "https://openclassrooms.com/courses/gerer-son-code-avec-git-et-github".


# Répertoire de travail
## Le dossier Embarquement
Contient les éléments nécessaires pour prendre en main la carte Arduino, lui ajouter le capteur de pression et la connecter à son Back-end.

## Le dossier Décollage
Intégration des éléments dans la boite et 

## Le dossier "Dans les Nuages"
Vérification des données dans le Cloud Azure

## Atterrissage
Visualisation des données sur Power BI
