# Les réseaux locaux - la norme Ethernet

>Aurélie Quidelleur  
><aurelie.quidelleur@univ-mlv.fr>  
>http://igm.univ-mlv.fr/~quidelleur/  

## introduction
Définitions  

LAN
:   Réseaux de taille limitée à qq km interconnectant jusqu'a une centaine de machines à des débits variant du Mb/s à la 10aine voire 100aine de Gb/s

Deux types de réseaux locaux:
* RLE (réseaux local d'entreprise): réseau type bureatique
* RLI (fuck, elle a passé la slide)

Tech la plus utilisée dans les réseaux filaires.

norme étendue désormais aux réseaux industriels et à la boucle locale.

(lire 80-2 point 3, inventé en février 1980)

## modèle IEEE et adressage MAC

### modèle IEEE

concerne les couches physique et liaison du modèle OSI

La couche liaison est divisée en deux sous-couches :
* MAC (Medium Access Control) : méthode d'accès au support et addressage
* LLC (Logical Link Control) : gestion des comunications et interface avec les couches supérieures
    * Couche LLC de type 1 : mode datagramme sans aquittement
    * couche LLC de type 2 : mode connecté (TCP)
    * couche LLC de type 3 : mode datagramme avec acquittement

### adressage MAC

* liée au matériel, a une portée locale (ne "sort" pas du lan)
* 6 octets notés en hexa; adresse construite en 2 parties
    * 24 premiers bits (Organizationally Unique Identifier) = identifiant du constructeur
    * les deux LSB (least significant bit) du 1er octet sont reservés:
        * bit I/G: nature de l'adresse (0 si unicast)
        * bit U/L : 0 pour format IEEE ("universal"), 1 pour format propriétaire
*  24 derniers bits: n° de série du constructeur afin que ce soit unique

Attention: sur ethernet, la transmission commence par le LSB de chaque octet  
ex: 10110011 00100111 se transmet 11001101 11100100

## Caractéristiques phusiques des LANs

* trois choix techniques
    * le type de topologie (étoiel ,maille, anneau)
    * le type de support physique (paire torsadée, fibre)
    * les méthodes d'accès au support (gestion du droit d'émission des éqquipements sur le support)
* De ces choix techniques découlent d'autres propriétés techniques
    * capacité
    * robustesse
    * configuration


### Topologie

* leurs perfs varient selon:
    * l'existence d'un point critique ( machine dont l'arret provoque l'écroulement du réseaut ex: etoile, anneau)
    * le mode d'insertion et de retrait d'un équipement
    * la capacité à localiser les pannes
    * le mode de transmission: mode diffustion ou mode point à point
* 3 topos utilisés dans les lans:
    * bus
    * etoile
    * anneau

### Support de transmission

* trois supports sont utilisés dans les LAN filaires
    * La paire torsadée
    * le cable coaxial 
    * la fibre optique
* Le choix du support conditionne le débi maximal et la taille du réseau.
* le choix du support détermine aussi les conditions de cablage
    * Flexibilité du support souhaitable ou non
    * Coût
    * Immunité aux perturbations electromagnétiques
    * Sécurité

#### la paire torsadée
La paire torsadée utilise un transmission différentielle: à récéption du signal, une différence sur les deux signaux est faite, et permet de récupérer un signal non affecté par le bruit.

UTP: Unshielded Twisted Pair
FTP: Foiled Twisted Pair
SFTP : Shielded-Foiled Twisted Pair
SSTP : Shielded-Shielded Twisted Pair

#### le cable coaxial

conducteur extérieur relié à la terre 

Gaine-blindage-isolant-ame

#### fibre optique

Protection-Gaine-coeur (en µm)
2 modes:
multimode (plus de débit)
monomode (un seul signal)

### Codage des données

* Sur les lans, transport des données sur de courtes distances : en général, transmission en bande de base
* Les données binaires sont représentées par un signal non-déterministe caractérisé par une Densité de Puissance(DSP = évaluation probabiliste de la répartition de la puissance du signal dans le domaine fréquentiel)

* le support de transmission est un canal:
    * A bande passante limitée (toutes les fréquences ne "passent" pas)
    * Présentant des défauts
* Nécéssité d'adapter le codage des données au support de transmission
* qualités recherchées:
    * valeur moyenne nulle(économies de puissance)
    * Spectre étroit permet de passer dans la BP du support
    * Possibilité de reconstituer l'horloge d'émission pour la synchro du récépteur
    * possibilité éventuelle de détécter voire corriger les erreurs

### détection d'erreurs

* Origine des erreurs : bruit, distorsion, atténuation
* Détection: on repère l'existence d'une erreur au moins, mais on ne peut pas la localiser  
    exemple: bit de parité
* Correction: on repere l'existence de l'erreur et on la localise.
* Détection et correction nécessitent l'ajout de bits de controle aux messages utiles
* La détection d'erreur consomme moins de bits que la correction d'erreurs

#### CRC
Le CRC ne fait que de la détection, et repose sur des divisions polynomiales.

* utilisé dans la trame ethernet
* ajoute des bits qui sont des combinaisons linéaires des bits du message utile

<!--
    TODO: 
    Penser a se trouver un lien expliquant bien le CRC( tout ce qui est polynomes, etc)
-->

Si le reste de la division polynomiale du CRC est 0, il n'y a pas d'erreurs. Si il y en a une, il y en a eu une.
Il reste une probabilité d'erreur, de 3x10^-12


## méthodes d'accès au support

Ce sont les rêgles de distribution de la parole aux équipements connectés sur un même support.

Il existe de nombreuses techniques:
* centralisée/distribuée:  
    Une station se charge de répartir la parole/l'ensemble des machines effectue la même fonction
* statique/dynamique:  
    Accès déterminé à l'initialisation du réseau, et figé/évolution suivant l'état du réseau et les besoins des machines
* déterministe/aléatoire:  
    prévoir avec certitude quelle station a accès au support à un instant `t`/aucune certitude
* équitable/prioritaire:  
    chaque équipement a la même probabilité d'acceder au support / accès prioritaire
* avec contentions/sans contentions:  
    avec ou sans possibilité de collisions entre les trames émises.

### exemples
* Aloha:  
    tout le monde envoie, avec temporisation aléatoire sur détection de collision
* Slotted Aloha:  
    la temporisation n'est plus entièrement aléatoire, mais répartie sur des *slots*
* CSMA(Carrier Sens Multiple Access):  
    Aloha avec écoute du canal avant émission.
    Des variantes existes combinant les dfférentes méthodes

## Ethernet ( IEEE 802.3) et ses extensions

* Concerne la couche physique et la couche MAC du modèle IEEE
* 1ere version en 1983

### format de la trame

Format commun à toutes les trames ethernet:
* Préambule 7 octets valant 1010101 pour la synchro
* Larquer de début: 1o
* Longueur/type si 1er o < 1500

### CSMA/CD
### Ethernet commuté, Span tree
### les normes de l'Ethernet
