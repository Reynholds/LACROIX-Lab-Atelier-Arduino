# LACROIX-Lab-Atelier-Arduino
Sources et schéma de l'atelier Arduino #1

Bienvenu dans cet atelier de prototypage rapide de conception d'un capteur de pression autonome LPWAN.

# Contexte
Dans le cadre du projet sur l'exploration des plateformes IoT connectées, nous seront ammenés à faire une campagne de mesure de valeur de pression, sur le terrain.

L'idée est ici de prototyper deux types de capteurs : 
- Capteur LORA
- Capteur Sigfox

Les effets recherchés sont de saisir l'occasion de monter en compétence en prototypage rapide et d'utiliser les technos LPWAN.


## Matériels Prototypage
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
Logiciel de visualisation de schéma :     http://fritzing.org/download/
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
# Installation du logiciel Arduino

1- télécharge et installe Arduino 1.8.5, ainsi que tous les drivers demandés durant l'installation (Arduino USB Driver, ...)

2- Installation des modules nécessaires aux cartes MKR Fox et MKR Wan
  Via Outils > Type de cartes > Gestionnaire de carte 
  Chercher "WAN" > Sélectionne et installe "Arduino SAMD Boards (32 bits ARM Cortex -M0+)by Arduino", ainsi que les drivers proposés lors de l'installation (Arduino USB Driver for SAMD boards)
  
3- Tout est prêt pour continuer

# Prise en main Arduino IDE
# Hello blink
Afin de tester la carte Arduino, nous allons commencer par faire clignoter la LED ! 

1- Démarre Arduino 1.8.5 

2- Sélectionne le modèle de ta carte 
  Outils > Type de cartes > Arduino MKR (WAN ou FOX)
  
3- Connecter et vérifier que la carte Arduino soit bien reconnue par PC à l'aide du câble micro-usb, "la LED verte devrait s'allumer, signifiant que la carte est sous tension"
  Outils > Port : "COMXX (Arduino MKR XXX)", sinon sélectionner le port qui contient le nom de la carte Arduino
  
  ### Astuce
  Il se peut que la carte ne soit pas reconnue, appuyer alors 3 fois successivement sur le bouton Reset (RST) de la carte
  
4- Récupération d'un programme pour faire clignoter la LED
  Fichier > Exemples > 01.Basics > Blink
  Cela permet d'afficher un programme permettant de faire clignoter la LED.




