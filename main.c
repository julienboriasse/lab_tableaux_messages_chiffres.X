/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F25K80
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

// Déclarations des fonctions de chiffrement

/**
 * Permet de chiffrer un caractère
 * Exemple de code:
 * for (int i=0; i<sizeof(msg); i++) {
 *  msg[i] = chiffrer_caractere(msg[i]);
 * }
 */

// Cette fonction n'est pas encore définie, vous devrez le faire dans le laboratoire
uint8_t chiffrer_caractere(uint8_t c);

/**
 * Permet de dechiffrer un caractère
 * Exemple de code:
 * for (int i=0; i<sizeof(msg); i++) {
 *  msg[i] = dechiffrer_caractere(msg[i]);
 * }
 */

// Cette fonction n'est pas encore définie, vous devrez le faire dans le laboratoire
uint8_t dechiffrer_caractere(uint8_t c);

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        uint8_t message[] = "J'adore mon enseignant !";
        printf("Message : %s\r\n", message);
        
        // Grace à la boucle for, on va traiter chaque caractère du message successivement
        for (uint8_t i = 0 ; i < sizeof(message) ; i++) {
            // c represente le caractère à traiter
            uint8_t c = message[i];
            
            // Chiffres
            if (c >= '0' && c <= '9') {
                c = (c + 5);
                // si le nouveau caractere est plus grand que 9
                if (c > '9') {
                    c = c - 10;
                }
            }
            // lettres minuscules
            else if (c >= 'a' && c <= 'z') {
                c = c - 4;
                // si le nouveau caractere est plus petit que a
                if (c < 'a') {
                    c = c + 26;
                }
            }
            // caractère spéciaux
            else {
                switch (c) {
                    case '!':
                        c = '"';
                        break;
                    case '"':
                        c = ' ';
                        break;
                    case ' ':
                        c = '!';
                        break;
                    case ',':
                        c = '?';
                        break;
                    case '.':
                        c = ',';
                        break;
                    case '?':
                        c = '.';
                        break;
                    // tous les autres caractères restent inchangés    
                    default:
                        break;
                }
            }
            
            message[i] = c;
        }
        
        printf("Message chiffre : %s\r\n", message);
        
        // On recommence après 5 secondes
        __delay_ms(5000);
        printf("\r\n");
    }
}
/**
 End of File
*/