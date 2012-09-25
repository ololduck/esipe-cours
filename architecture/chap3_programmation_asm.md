# Chapitre 3: Programmation en assembleur

Langage d'assemblage
:   Langage compréhensible par un humain et qui représente le langage machine, directement compréhensible par le processeur

On étudie l'assembleur pour arch x86 sous linux 32b.

## A) La structure d'un programme en assembleur

les fichiers assembleurs ont généralement pour extension `.asm`

    section .data
    entier1: dd 225
    car1: db "Z"

    section .text
    global main
    main:
        mov ebx, 0
        mov eax, 1
        int 0X80

* La section .data

  Elle regroupe les données utilisées par le programme.
  ces données sont initialisées lors de leur déclaration

  Syntaxe:
    `LABEL: dx VALUE`
  + les tableaux:
    `suite: times 85 dd 5`  
    Créé à partir de l'adresse `suite` de 85x4 octets tous initialisés à 5
