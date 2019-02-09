// **********************************************************************************
// Programmateur Fil Pilote et Suivi Conso
// **********************************************************************************
// Copyright (C) 2014 Thibault Ducret
// Licence MIT
//
// History : 15/01/2015 Charles-Henri Hallard (http://hallard.me)
//                      Intégration de version 1.2 de la carte electronique
//           15/09/2015 Charles-Henri Hallard : Ajout compatibilité ESP8266
//
// **********************************************************************************

#ifndef PILOTES_h
#define PILOTES_h

#include "remora.h"

// Fils pilotes
#define NB_FILS_PILOTES 7

// Les fils pilotes sont connectés de la façon suivante sur l'I/O expander
// # Fil Pilote    MCP IO/Port   Digital Port
// FP1 (a et b) -> GPB6, GPB7  ->  14/15
// FP2 (a et b) -> GPB4, GPB5  ->  12/13
// FP3 (a et b) -> GPB2, GPB3  ->  10/11
// FP4 (a et b) -> GPA1, GPA0  ->  1/0
// FP5 (a et b) -> GPA3, GPA2  ->  3/2
// FP6 (a et b) -> GPA5, GPA4  ->  5/4
// FP7 (a et b) -> GPA7, GPA6  ->  7/6
// Relais       -> GPB1        ->  9
// LED          -> GPB0        ->  8
#define FP1 14,15
#define FP2 12,13
#define FP3 10,11
#define FP4  1,0
#define FP5  3,2
#define FP6  5,4
#define FP7  7,6

#define RELAIS_PIN  9
#define LED_PIN     8

// Variables exported to other source file
// ========================================
extern Adafruit_MCP23017 mcp;
extern int SortiesFP[];
extern char etatFP[];
extern char memFP[];
extern int nivDelest;
extern uint8_t plusAncienneZoneDelestee;
extern unsigned long timerDelestRelest;

// Function exported for other source file
// =======================================
bool pilotes_setup(void);
bool pilotes_loop(void);
void delester1zone(void);
void relester1zone(void);
void decalerDelestage(void);
void initFP(void);
int setfp(String);
int setfp_interne(uint8_t fp, char cOrdre);
int fp(String);
int relais(String);
int fnct_relais(String command);

#endif
