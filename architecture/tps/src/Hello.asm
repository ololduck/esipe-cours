; Premier programme en assembleur

SECTION .data ; Section des données.
msg :
    db "Hello World", 10 ; La chaine de caractères a afficher, 
                         ; 10 est code ASCII retour a la ligne.

SECTION .text            ; Section du code.
global main              ; Rend l'étiquette visible de l'extérieur.
main :                   ; Étiquette pointant au début du programme.
    nop                  ; Instruction vide
    mov edx, 0xc         ; arg3, nombre de caractères a afficher 
                         ; (Équivalent a mov edx, 12).
    mov ecx, msg         ; arg2, adresse du premier caractère 
                         ; à  afficher.
    mov ebx, 1           ; arg1, numéro de la sortie pour l'affichage, 
                         ; 1 est la sortie standard.
    mov eax, 4           ; Numéro de la commande write pour 
                         ; l'interruption 80h.
    int 0x80             ; Interruption 0x80, appel au noyau.
    mov ebx, 0           ; Code de sortie, 0 est la sortie normale.
    mov eax, 1           ; Numéro de la commande exit.
    int 0x80             ; Interruption 0x80, appel au noyau.
