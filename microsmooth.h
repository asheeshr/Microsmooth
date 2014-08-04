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
#ifndef SMA_LENGTH
#define SMA_LENGTH 5
#endif

/*Exponential Moving Average - Alpha parameter */
#ifndef EMA_ALPHA
#define EMA_ALPHA 10 /*This is in percentage. Should be between 0-99*/
#endif

/*Savitzky Golay Filter -  */
#ifndef SGA_LENGTH
#define SGA_LENGTH 11
#endif

/*Ramer Douglas Peucker -  */
#ifndef RDP_LENGTH
#define RDP_LENGTH 7
#endif

#ifndef epsilon
#define epsilon 50
#endif

/*Kolmogorov Zurbenko Filter-  */
#ifndef KZA_LENGTH
#define KZA_LENGTH 5
#endif

#ifndef KZA_MAX
#define KZA_MAX 4
#endif

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
