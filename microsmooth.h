/*Standard Library Dependencies*/
#include <stdint.h>
//#include <math.h>
#include <stdlib.h>

#ifndef MICROSMOOTH
#define MICROSMOOTH

/*Filter Codes*/
#define SMA 0b00000001
#define CMA 0b00000010
#define EMA 0b00000100
#define SGA 0b00001000
#define KZA 0b00010000
#define RDP 0b00100000

/*Algorithm Parameters*/

/*
These parameters should be tuned depending on need. Each of these parameters affects
run time and signal smoothing obtained. See documentation for specific instructions 
on tuning these parameters.
*/

/*Simple Moving Average - Length of window */
#define SMA_LENGTH 5

/*Exponential Moving Average - Alpha parameter */
#define EMA_ALPHA 10 /*This is in percentage. Should be between 0-99*/

/*Savitzky Golay Filter -  */
#define SGA_LENGTH 11

/*Ramer Douglas Peucker -  */
#define RDP_LENGTH 7
#define epsilon 50

/*Kolmogorov Zurbenko Filter-  */
#define KZA_LENGTH 5
#define KZA_MAX 4
#define KZA_HISTORY_LENGTH ((KZA_LENGTH-1)*KZA_MAX)
#define KZA_MID (KZA_HISTORY_LENGTH)/2

uint16_t* ms_init(uint8_t );
int sma_filter(int current_value, uint16_t history_SMA[]);
int cma_filter(int current_value, void * ptr); /*Pointer not needed. Maintaining consistent interface*/
int ema_filter(int current_value, void * ptr); /*Pointer not needed. Maintaining consistent interface*/
int sga_filter(int current_value, uint16_t history_SGA[]); /*Needs to be tested*/
int kza_filter(int current_value);
int rdp_filter(int current_value, uint16_t history_RDP[]);/*Iterative neeeds testing*/
void ms_deinit(int *);

#endif
