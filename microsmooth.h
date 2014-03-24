/*Standard Library Dependencies*/
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#ifndef MICROSMOOTH
#define MICROSMOOTH

/*Filter Codes*/
#define SMA 0b00000001
#define CMA 0b00000010
#define EMA 0b00000100
#define SGA 0b00001000
#define KZF 0b00010000
#define RDP 0b00100000

#define SMA_LENGTH 5
#define EMA_ALPHA 10 /*This is in percentage. Should be between 0-99*/
#define SGA_LENGTH 11
#define RDP_LENGTH 11
#define epsilon 50
#define KZ_LENGTH 5
#define KZ_MAX 4
#define KZ_history_LENGTH ((KZ_LENGTH-1)*KZ_MAX)


extern int history_KZ[KZ_history_LENGTH];
extern int history_RDP[RDP_LENGTH];
extern int index_RDP[];


uint16_t* ms_init(uint8_t );
int sma_filter(int current_value, uint16_t history_SMA[]);
int cma_filter(int current_value, void * ptr); /*Pointer not needed. Maintaining consistent interface*/
int ema_filter(int current_value, void * ptr); /*Pointer not needed. Maintaining consistent interface*/
int sga_filter(int current_value, uint16_t history_SGA[]); /*Needs to be tested*/
int KZ_filter(int current_value);
int rdp_filter(int current_value, uint16_t history_RDP[]);/*Iterative neeeds testing*/
void ms_deinit(int *);

#endif
